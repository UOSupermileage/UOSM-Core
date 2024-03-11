/*
 * CANMessageLookUpModule.c
 *
 *  Created on: Dec 4, 2022
 *      Author: mingy
 */

#include "CANMessageLookUpModule.h"
#include "CANDriver.h"

void ThrottleDataCallback(iCommsMessage_t *msg) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    SerialPrintln("CAN Throttle message received");
}
void ErrorDataCallback(iCommsMessage_t *msg) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    SerialPrintln("CAN Error message received");
}
void SpeedDataCallback(iCommsMessage_t *msg) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    SerialPrintln("CAN Speed message received");
}
void EventDataCallback(iCommsMessage_t *msg) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    SerialPrintln("CAN Event message received");
}
void MotorRPMDataCallback(iCommsMessage_t *msg) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    SerialPrintln("CAN RPM received");
}
void CurrentVoltageDataCallback(iCommsMessage_t *msg) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    SerialPrintln("CAN Voltage message received");
}

/*********************************************************************************
 *
 * 		Look up table for CAN ID and meta data about its payload
 *
 **********************************************************************************/
const ICommsMessageInfo CANMessageLookUpTable[NUMBER_CAN_MESSAGE_IDS] = {
    // Message Index			CAN ID		Num of Bytes		Callback
    {THROTTLE_DATA_ID, 0x0001, 2, &ThrottleDataCallback},
    {SPEED_DATA_ID, 0x0002, 4, &SpeedDataCallback},
    {MOTOR_RPM_DATA_ID, 0x0003, 4, &MotorRPMDataCallback},
    {EVENT_DATA_ID, 0x0400, 2, &EventDataCallback},
    {ERROR_DATA_ID, 0x0401, 2, &ErrorDataCallback},
    {CURRENT_VOLTAGE_DATA_ID, 0x0004, 2, &CurrentVoltageDataCallback},
};

PUBLIC const ICommsMessageInfo *CANMessageLookUpGetInfo(ICommsMessageLookUpIndex id) { return &CANMessageLookUpTable[id]; }