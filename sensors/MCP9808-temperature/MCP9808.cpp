#include "MCP9808.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <memory>
#include <inttypes.h>
#include <bitset>

using namespace std;

namespace exploringBB {

#define MCP9808_REG_CONFIG             0x01
#define MCP9808_REG_UPPER_TEMP         0x02
#define MCP9808_REG_LOWER_TEMP         0x03
#define MCP9808_REG_CRIT_TEMP          0x04
#define MCP9808_REG_AMBIENT_TEMP       0x05
#define MCP9808_REG_MANUF_ID           0x06
#define MCP9808_REG_DEVICE_ID          0x07

#define MCP9808_I2CADDR_DEFAULT        0x18

#define MCP9808_REG_CONFIG_ALERTMODE   0x0001
#define MCP9808_REG_CONFIG_ALERTPOL    0x0002
#define MCP9808_REG_CONFIG_ALERTSEL    0x0004
#define MCP9808_REG_CONFIG_ALERTCTRL   0x0008
#define MCP9808_REG_CONFIG_ALERTSTAT   0x0010
#define MCP9808_REG_CONFIG_INTCLR      0x0020
#define MCP9808_REG_CONFIG_WINLOCKED   0x0040
#define MCP9808_REG_CONFIG_CRITLOCKED  0x0080
#define MCP9808_REG_CONFIG_SHUTDOWN    0x0100

/**
 * The constructor for the MCP9808 accelerometer object. It passes the bus number and the
 * device address (with is 0x18 by default) to the constructor of I2CDevice. All of the states
 * are initialized and the registers are updated.
 * @param I2CBus The bus number that the MCP9808 device is on?
 * @param I2CAddress The address of the MCP9808 device (default 0x18, but can be altered)
 */
MCP9808::MCP9808(unsigned int I2CBus, unsigned int I2CAddress):
	I2CDevice(I2CBus, I2CAddress){   // this member initialization list calls the parent constructor
	I2CAddress = I2CAddress;
	I2CBus = I2CBus;
	registers = NULL;
}

float MCP9808::readTempC(void) {
   unsigned char t[2];
   readRegister(MCP9808_REG_AMBIENT_TEMP, t, 2);
   
   float temp = 0;
   char u = t[0]; // Upper byte
   char l = t[1]; // Lower byte
   
   u = u & 0x1F;

   if ((u & 0x10) == 0x10){
       u = u & 0x0F;   //Clear SIGN
       temp = 256.0 - (u *  16.0 + l / 16.0);
   } else {                              
       temp = (u * 16.0 + l / 16.0);
   }

   return temp;
}

MCP9808::~MCP9808() {}

} /* namespace exploringBB */
