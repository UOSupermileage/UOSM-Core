/*
 * SerialDebugDriver.h
 *
 *  Created on: Sep. 5, 2022
 *      Author: mingy
 */

#ifndef USERDRIVERS_SERIALDEBUGDRIVER_H_
#define USERDRIVERS_SERIALDEBUGDRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "UOSMCoreConfig.h"

// Standard Lib
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define MAX_SERIAL_PRINT_LENGTH 128

//#define VERBOSE

/* NOTE:
 * Initalization of the serial peripheral is done in main.c
 * Auto generated init by the IOC file */

void SerialPrint(const char* message, ...);

void SerialPrintln(const char* message, ...);

#ifdef __cplusplus
}
#endif

#endif /* USERDRIVERS_SERIALDEBUGDRIVER_H_ */
