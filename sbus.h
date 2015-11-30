#ifndef __SBUS_H__
#define __SBUS_H__
#include <stdio.h>
#include <stdint.h>
#include <cc2510fx.h>
#include "main.h"
#include "config.h"

#if SBUS_ENABLED

void sbus_init(void);
void sbus_update(__xdata uint16_t *data);
void sbus_start_transmission(uint8_t frame_lost);
void sbus_exit_failsafe(void);
void sbus_enter_failsafe(void);
void sbus_uart_set_mode(__xdata union uart_config_t *cfg);

//best match for 1mbit/s = 999755.859375 bit/s
//baudrate = (((256.0 + baud_m)*2.0**baud_e) / (2**28)) * 26000000.0
#define SBUS_BAUD_E 15
#define SBUS_BAUD_M 59

#define SBUS_DATA_LEN 25
extern __xdata uint8_t sbus_data[SBUS_DATA_LEN];

#define SBUS_SYNCBYTE 0xF0
#define SBUS_ENDBYTE  0x00
#define SBUS_FLAG_FRAME_LOST      (1<<5)
#define SBUS_FLAG_FAILSAFE_ACTIVE (1<<4)
#define SBUS_FRAME_LOST 1
#define SBUS_FRAME_NOT_LOST 0

#endif

#endif