/*
* ELT T200 I2C Library
* t200.h
* Essentially a near clone of the goodly ELT_S300_HOLLY
* library written by https://github.com/mhorimoto,
* but modified for a different sensor type.
*/

#ifndef ELT_T200_I2C_GREY
#define ELT_T200_I2C_GREY

#include "Arduino.h"
#include "Wire.h"

#define T200I2C_ADDR      0x31

class T200I2C {
 public:
  T200I2C(TwoWire &w);
  boolean begin(uint8_t i2caddr);
  void sleep(void);
  void wakeup(void);
  void clear_recalib(void);
  void start_mcdl(void);
  void end_mcdl(void);
  void start_acdl(void);
  void end_acdl(void);
  unsigned int getC02ppm(void);
/*
* mcdl stands for Manual Calibration Function in Dimming Light
* acdl is the periodic Automatic Calibration Function in Dimming Light
*/
private:
  TwoWire *wire;
  unsigned int co2i;
  uint8_t _i2caddr;
  uint8_t _tmpBuf[7];

/**
* I2C write function where 'cmd' is the 8 bit command ID
*/
void writeCommand(uint8_t cmd);
};
#endif
