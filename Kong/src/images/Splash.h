#pragma once

namespace Images {

  #ifndef DEBUG
  const uint8_t PROGMEM PPOT[] = {
  65, 31,
  0xfe, 0x01, 0x05, 0xf1, 0xf1, 0xf1, 0x11, 0xd1, 0xb1, 0xd1, 0x11, 0xf1, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x00, 0x00, 0xff, 0x00, 0x00, 0x7f, 0x7f, 0x09, 0x09, 0x0f, 0x06, 0x00, 0x7f, 0x7f, 0x19, 0x39, 0x6f, 0x46, 0x00, 0x7f, 0x7f, 0x49, 0x49, 0x41, 0x41, 0x00, 0x26, 0x6f, 0x49, 0x49, 0x7b, 0x32, 0x00, 0x26, 0x6f, 0x49, 0x49, 0x7b, 0x32, 
  0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0x02, 0x79, 0xcd, 0x95, 0xa5, 0xcd, 0x79, 0x01, 0x11, 0x11, 0x11, 0x01, 0xf9, 0xf9, 0x01, 0x01, 0x00, 0x00, 0xff, 0x00, 0x00, 0x7f, 0x7f, 0x09, 0x09, 0x0f, 0x06, 0x00, 0x7f, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x00, 0x7c, 0x7e, 0x0b, 0x0b, 0x7e, 0x7c, 0x00, 0x07, 0x0f, 0x78, 0x78, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0x00, 0x00, 0x1f, 0x3f, 0x3f, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3e, 0x36, 0x36, 0x3e, 0x36, 0x3e, 0x36, 0x3e, 0x36, 0x36, 0x3e, 0x36, 0x36, 0x3e, 0x36, 0x00, 0x00, 0xff, 0x00, 0x00, 0x3e, 0x7f, 0x41, 0x41, 0x7f, 0x3e, 0x00, 0x7f, 0x7f, 0x0e, 0x1c, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0x40, 0x50, 0x40, 0x40, 0x40, 0x78, 0x46, 0x41, 0x41, 0x59, 0x59, 0x41, 0x41, 0x41, 0x41, 0x59, 0x59, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x01, 0x01, 0x7f, 0x7f, 0x01, 0x01, 0x00, 0x7c, 0x7e, 0x0b, 0x0b, 0x7e, 0x7c, 0x00, 0x7f, 0x7f, 0x09, 0x09, 0x0f, 0x06, 0x00, 0x7f, 0x7f, 0x49, 0x49, 0x41, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };  
  #else
  const uint8_t PROGMEM PPOT[] = {
  0x00 ,0x07, 0x3d
  };
  #endif  
  
  #ifndef DEBUG
  const uint8_t PROGMEM PPOT_Arrow[] = {
  5, 7,
  0x7f, 0x7f, 0x3e, 0x1c, 0x08, 
  };
  #else
  const uint8_t PROGMEM PPOT_Arrow[] = {
  0x00 ,0x07, 0x3d
  };
  #endif  

  const uint8_t PROGMEM PPOT_Spindle[] = {
  2, 8,
  0xd4, 0xd2, 
  };
  
  const uint8_t PROGMEM Ppot_Loading[] = {
  33, 8,
  0x0f, 0x0f, 0x08, 0x08, 0x00, 0x06, 0x09, 0x0b, 0x06, 0x00, 0x0e, 0x03, 0x03, 0x0e, 0x00, 0x0f, 0x09, 0x0f, 0x06, 0x00, 0x0f, 0x0f, 0x00, 0x0f, 0x02, 0x03, 0x0f, 0x00, 0x0e, 0x0f, 0x09, 0x0d, 0x00, 
  };

  #ifndef DEBUG
  const uint8_t PROGMEM PressAandB[] = {
  68, 16,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0x7e, 0xc7, 0xeb, 0xed, 0xeb, 0xc7, 0x7e, 0xbc, 0x00, 0x00, 0x3c, 0x2c, 0x00, 0x38, 0x14, 0x38, 0x00, 0x08, 0x24, 0x10, 0x00, 0x04, 0x38, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0x7e, 0xc1, 0xd5, 0xd5, 0xd5, 0xcb, 0x7e, 0xbc, 0x00, 0x00, 0x3c, 0x10, 0x3c, 0x00, 0x38, 0x14, 0x38, 0x00, 0x3c, 0x14, 0x28, 0x00, 0x3c, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };
  #else
  const uint8_t PROGMEM PressAandB[] = {
  0x01 ,0x01, 0x01
  };
  #endif 

  #ifndef DEBUG
  const uint8_t PROGMEM PressAandB_Mask[] = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  };
  #else
  const uint8_t PROGMEM PressAandB_Mask[] = {
  0x01 ,0x01, 0x01
  };
  #endif 

  #ifndef DEBUG
  const uint8_t PROGMEM Title_Kong[] = {
  128, 64,
  0x00, 0x00, 0x04, 0x0a, 0x35, 0xc2, 0x3f, 0xc0, 0x3e, 0xc1, 0x00, 0x00, 0x00, 0x63, 0x9c, 0x63, 0x9c, 0x63, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x9c, 0xc0, 0xfc, 0xfc, 0xfc, 0x3c, 0x1c, 0x1c, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0x8c, 0x44, 0x64, 0x64, 0x44, 0x8c, 0xf8, 0xf8, 0xf0, 0xc0, 0x00, 0x1c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x9c, 0xfc, 0xfc, 0xfc, 0x1c, 0x00, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0x3c, 0x1c, 0x1c, 0x1c, 0x38, 0x7c, 0x7c, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x1c, 0x00, 0x1c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0x63, 0x9c, 0x63, 0x9c, 0x63, 0x00, 0x00, 0x00, 0xc1, 0x3e, 0xc0, 0x3f, 0xc2, 0x35, 0x0a, 0x04, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0x66, 0x99, 0xe6, 0x19, 0xa6, 0x79, 0x00, 0x00, 0x00, 0x18, 0x27, 0x58, 0xa7, 0x58, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xf9, 0x03, 0xff, 0xbf, 0xbf, 0xbe, 0xbc, 0xf8, 0x00, 0x1f, 0x2f, 0x5f, 0x5f, 0xbf, 0xbf, 0xa0, 0xa0, 0xa5, 0xbf, 0x5f, 0x5f, 0x2f, 0x1f, 0x00, 0xf8, 0xbf, 0xbf, 0xbf, 0xfa, 0x0d, 0x17, 0x2f, 0x5f, 0xff, 0xbf, 0xbf, 0xff, 0x00, 0x00, 0x1f, 0x2f, 0x5f, 0x5f, 0xbf, 0xbc, 0xb8, 0xb8, 0xbb, 0xbf, 0x5f, 0x2f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xf8, 0x00, 0xf8, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x58, 0xa7, 0x58, 0x27, 0x18, 0x00, 0x00, 0x00, 0x79, 0xa6, 0x19, 0xe6, 0x99, 0x66, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x02, 0x8d, 0x70, 0x8f, 0x70, 0x8f, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x90, 0x50, 0x20, 0x10, 0x10, 0x08, 0x88, 0x84, 0x84, 0x04, 0x84, 0x88, 0x88, 0x10, 0x28, 0xc8, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72, 0x8f, 0x70, 0x8f, 0x70, 0x8d, 0x02, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x61, 0x9e, 0x61, 0x9e, 0x61, 0x9e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x18, 0x44, 0x24, 0x22, 0xa2, 0xa1, 0x01, 0x01, 0x80, 0xa0, 0xd0, 0x68, 0x50, 0x20, 0x40, 0x40, 0x80, 0x30, 0x78, 0x3c, 0x9b, 0xc0, 0xe0, 0xf0, 0xf0, 0xff, 0xd1, 0xe6, 0xe2, 0xa1, 0xc2, 0xae, 0xe0, 0x9f, 0xf8, 0xe3, 0xc8, 0x0c, 0x74, 0x38, 0x00, 0x00, 0x80, 0x80, 0x40, 0xa0, 0xd0, 0xa0, 0x41, 0x01, 0x02, 0x02, 0x42, 0x44, 0x44, 0x48, 0x88, 0x30, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9e, 0x61, 0x9e, 0x61, 0x9e, 0x61, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0xa0, 0x41, 0x3c, 0x3e, 0xff, 0x81, 0x00, 0x7e, 0x7f, 0xff, 0xff, 0xff, 0x5b, 0xff, 0xff, 0x5b, 0x18, 0xe7, 0xf8, 0xc0, 0xce, 0xbf, 0x63, 0x6d, 0xdc, 0xd4, 0xd4, 0xdc, 0xdd, 0xdb, 0xeb, 0xf7, 0xf7, 0xf7, 0xef, 0xef, 0x6f, 0xaf, 0xce, 0xf0, 0xf0, 0xfc, 0xcf, 0x30, 0xb6, 0xfe, 0xfe, 0xb6, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0x01, 0x03, 0xfe, 0x7c, 0x78, 0x82, 0x40, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x50, 0xa8, 0xa4, 0x52, 0x35, 0xad, 0x52, 0x20, 0x40, 0xb8, 0xa5, 0x1a, 0xd8, 0x25, 0x1c, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x05, 0x05, 0x05, 0x99, 0x61, 0x01, 0x00, 0x07, 0x07, 0xef, 0xff, 0xf7, 0xff, 0xef, 0xee, 0xce, 0xcc, 0xcc, 0xed, 0xed, 0xfd, 0xed, 0xed, 0xec, 0xce, 0xce, 0xcf, 0xef, 0xef, 0xff, 0xf7, 0x3f, 0x0f, 0x00, 0x02, 0xc3, 0x33, 0x0a, 0x0b, 0x0b, 0x05, 0x04, 0x04, 0x04, 0x05, 0x05, 0x38, 0x4a, 0xb0, 0x35, 0x4a, 0x70, 0x80, 0x40, 0xa4, 0x5a, 0x6a, 0xa4, 0x48, 0x50, 0xa0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xa0, 0xa0, 0xa1, 0xa1, 0xa2, 0xa5, 0x42, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xc2, 0x81, 0x80, 0x00, 0x01, 0x02, 0x04, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x3f, 0x3f, 0xbf, 0xbf, 0xbf, 0x7f, 0x7f, 0xbf, 0xbf, 0x3f, 0x3f, 0x3f, 0x3f, 0x0f, 0x07, 0x03, 0x00, 0x08, 0x04, 0x02, 0x00, 0x01, 0x02, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x05, 0x0b, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x15, 0x1d, 0x00, 0x1e, 0x05, 0x05, 0x1e, 0x00, 0x1f, 0x06, 0x02, 0x1f, 0x00, 0x1f, 0x15, 0x11, 0x00, 0x00, 0x00, 0x1f, 0x20, 0x5f, 0x91, 0x9a, 0x9a, 0x91, 0x9f, 0x80, 0x40, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x32, 0x2d, 0x2e, 0x2a, 0x2a, 0x2e, 0x26, 0x2a, 0x2c, 0x2c, 0x2c, 0x2e, 0x2c, 0x2c, 0x2c, 0x10, 0x0e, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x0d, 0x12, 0x24, 0x2c, 0x28, 0x2c, 0x2c, 0x2c, 0x2c, 0x28, 0x26, 0x26, 0x2e, 0x2e, 0x2c, 0x2d, 0x12, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x15, 0x1d, 0x00, 0x1e, 0x05, 0x05, 0x1e, 0x00, 0x1f, 0x06, 0x02, 0x1f, 0x00, 0x1f, 0x15, 0x11, 0x00, 0x00, 0x00, 0x1f, 0x20, 0x5f, 0x90, 0x92, 0x94, 0x93, 0x9f, 0x80, 0x40, 0x3f, 0x00, 0x00, 0x00, 0x00, 
  };
  #else
  const uint8_t PROGMEM Title_Kong[] = {
  0x01 ,0x01, 0x01
  };
  #endif 

}