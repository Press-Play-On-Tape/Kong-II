/**
 * @file ArduboyNewTones.cpp
 * \brief An Arduino library for playing tones and tone sequences,
 * intended for the Arduboy game system.
 */

/*****************************************************************************
  ArduboyNewTones

An Arduino library to play tones and tone sequences.

Specifically written for use by the Arduboy miniature game system
https://www.arduboy.com/
but could work with other Arduino AVR boards that have 16 bit timer 3
available, by changing the port and bit definintions for the pin(s)
if necessary.

NewTone Created by Tim Eckel - teckel@leethost.com
Copyright 2013 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html

ArduboyTones by Scott Allen
Copyright (c) 2017

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*****************************************************************************/

#include "ArduboyNewTones.h"

// pointer to a function that indicates if sound is enabled
static bool (*outputEnabled)();

static unsigned long _nt_time; // Time note should end.
static volatile bool tonesPlaying = false;
static volatile bool toneSilent;
#ifdef TONES_VOLUME_CONTROL
static volatile bool toneHighVol;
static volatile bool forceHighVol = false;
static volatile bool forceNormVol = false;
#endif

static volatile uint16_t *tonesStart;
static volatile uint16_t *tonesIndex;
static volatile uint16_t toneSequence[MAX_TONES * 2 + 1];
static volatile bool inProgmem;


ArduboyTones::ArduboyTones(boolean (*outEn)())
{
  outputEnabled = outEn;

  toneSequence[MAX_TONES * 2] = TONES_END;

  bitClear(TONE_PIN_PORT, TONE_PIN); // set the pin low
  bitSet(TONE_PIN_DDR, TONE_PIN); // set the pin to output mode
#ifdef TONES_2_SPEAKER_PINS
  bitClear(TONE_PIN2_PORT, TONE_PIN2); // set pin 2 low
  bitSet(TONE_PIN2_DDR, TONE_PIN2); // set pin 2 to output mode
#endif
}

void ArduboyTones::tone(uint16_t freq, uint16_t dur)
{
  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
  inProgmem = false;
  tonesStart = tonesIndex = toneSequence; // set to start of sequence array
  toneSequence[0] = freq;
  toneSequence[1] = dur;
  toneSequence[2] = TONES_END; // set end marker
  nextTone(); // start playing
}

void ArduboyTones::tone(uint16_t freq1, uint16_t dur1,
                        uint16_t freq2, uint16_t dur2)
{
  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
  inProgmem = false;
  tonesStart = tonesIndex = toneSequence; // set to start of sequence array
  toneSequence[0] = freq1;
  toneSequence[1] = dur1;
  toneSequence[2] = freq2;
  toneSequence[3] = dur2;
  toneSequence[4] = TONES_END; // set end marker
  nextTone(); // start playing
}

void ArduboyTones::tone(uint16_t freq1, uint16_t dur1,
                        uint16_t freq2, uint16_t dur2,
                        uint16_t freq3, uint16_t dur3)
{
  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
  inProgmem = false;
  tonesStart = tonesIndex = toneSequence; // set to start of sequence array
  toneSequence[0] = freq1;
  toneSequence[1] = dur1;
  toneSequence[2] = freq2;
  toneSequence[3] = dur2;
  toneSequence[4] = freq3;
  toneSequence[5] = dur3;
  // end marker was set in the constructor and will never change
  nextTone(); // start playing
}

void ArduboyTones::tones(const uint16_t *tones)
{
  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
  inProgmem = true;
  tonesStart = tonesIndex = (uint16_t *)tones; // set to start of sequence array
  nextTone(); // start playing
}

void ArduboyTones::tonesInRAM(uint16_t *tones)
{
  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
  inProgmem = false;
  tonesStart = tonesIndex = tones; // set to start of sequence array
  nextTone(); // start playing
}

void ArduboyTones::noTone()
{
  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
  TCCR3B = _BV(CS31); // Default clock prescaler of 8.
  TCCR3A = _BV(WGM30); // Set to defaults so PWM can work like normal (PWM, phase corrected, 8bit).
  bitClear(TONE_PIN_PORT, TONE_PIN); // set the pin low
#ifdef TONES_VOLUME_CONTROL
  bitClear(TONE_PIN2_PORT, TONE_PIN2); // set pin 2 low
#endif
  tonesPlaying = false;
}

void ArduboyTones::volumeMode(uint8_t mode)
{
#ifdef TONES_VOLUME_CONTROL
  forceNormVol = false; // assume volume is tone controlled
  forceHighVol = false;

  if (mode == VOLUME_ALWAYS_NORMAL) {
    forceNormVol = true;
  }
  else if (mode == VOLUME_ALWAYS_HIGH) {
    forceHighVol = true;
  }
#endif
}

bool ArduboyTones::playing()
{
  return tonesPlaying;
}

void ArduboyTones::nextTone()
{
  uint16_t freq;
  uint16_t dur;
  uint8_t prescaler;
  unsigned long top;

  freq = getNext(); // get tone frequency

  if (freq == TONES_END) { // if freq is actually an "end of sequence" marker
    noTone(); // stop playing
    return;
  }

  tonesPlaying = true;

  if (freq == TONES_REPEAT) { // if frequency is actually a "repeat" marker
    tonesIndex = tonesStart; // reset to start of sequence
    freq = getNext();
  }

#ifdef TONES_VOLUME_CONTROL
  if (((freq & TONE_HIGH_VOLUME) || forceHighVol) && !forceNormVol) {
    toneHighVol = true;
  }
  else {
    toneHighVol = false;
  }
#endif

  freq &= ~TONE_HIGH_VOLUME; // strip volume indicator from frequency

  if (freq == 0) { // if tone is silent
    freq = SILENT_FREQ;
    toneSilent = true;
    bitClear(TONE_PIN_PORT, TONE_PIN); // set the pin low
  }
  else {
    toneSilent = false;
  }

  prescaler = _BV(CS30);           // Try using prescaler 1 first.
  top = F_CPU / freq / 4 - 1;      // Calculate the top.
  if (top > 65535) {               // If not in the range for prescaler 1, use prescaler 256 (61 Hz and lower @ 16 MHz).
    prescaler = _BV(CS32);         // Set the 256 prescaler bit.
    top = top / 256 - 1;           // Calculate the top using prescaler 256.
  }

  if (!outputEnabled()) { // if sound has been muted
    toneSilent = true;
  }

#ifdef TONES_VOLUME_CONTROL
  if (toneHighVol && !toneSilent) {
    // set pin 2 to the compliment of pin 1
    if (bitRead(TONE_PIN_PORT, TONE_PIN)) {
      bitClear(TONE_PIN2_PORT, TONE_PIN2);
    }
    else {
      bitSet(TONE_PIN2_PORT, TONE_PIN2);
    }
  }
  else {
    bitClear(TONE_PIN2_PORT, TONE_PIN2); // set pin 2 low for normal volume
  }
#endif

  dur = getNext(); // get tone duration
  if (dur > 0) _nt_time = millis() + dur; else _nt_time = 0xFFFFFFFF; // Set when the note should end, or play "forever".

  ICR3 = top;                      // Set the top.
  if (TCNT3 > top) TCNT3 = top;    // Counter over the top, put within range.
  TCCR3B = _BV(WGM33) | prescaler; // Set PWM, phase and frequency corrected (ICR1) and prescaler.
  TCCR3A = _BV(COM3B0);
  bitWrite(TIMSK3, OCIE3A, 1); // enable the output compare match interrupt
}

uint16_t ArduboyTones::getNext()
{
  if (inProgmem) {
    return pgm_read_word(tonesIndex++);
  }
  return *tonesIndex++;
}

ISR(TIMER3_COMPA_vect)
{
  if (millis() < _nt_time) {
    if (!toneSilent) {
      *(&TONE_PIN_PORT) ^= TONE_PIN_MASK; // toggle the pin
#ifdef TONES_VOLUME_CONTROL
      if (toneHighVol) {
        *(&TONE_PIN2_PORT) ^= TONE_PIN2_MASK; // toggle pin 2
      }
#endif
    }
  }
  else {
    ArduboyTones::nextTone();
  }
}
