#include <t200i2c.h>

/* -*- C++ -*-
 *
 * Example program for ELT T200 I2C
 * Version: 1.0.0
 *
 */

#include "t200i2c.h"
#include <Wire.h>

// From the example for the S300, but for the T200 instead.

T200I2C s3(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  s3.begin(T200I2C_ADDR);
  delay(10000); // 10sec wait.
  Serial.println("START T200I2C");
}

void loop() {
  unsigned int co2;
  co2 = s3.getC02ppm();
  Serial.print("CO2 = ");
  Serial.print(co2);
  Serial.println(" ppm");
  delay(10000); // 30sec wait
}

