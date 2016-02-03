/* 
 * File:   app.h
 * Author: peterb
 *
 * Created on February 2, 2016, 10:00 AM
 */

#ifndef APP_H
#define	APP_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "driver/tmr/drv_tmr.h"
#include "system/ports/sys_ports.h"
/* Application states */
typedef enum
{
APP_STATE_INIT,
APP_STATE_WAIT_FOR_ALARM
} APP_STATES;
/* Application Data */
typedef struct
{
APP_STATES state;
DRV_HANDLE handleTmr;
unsigned int timerAlarmCount;
bool ledIsOn;
} APP_DATA;
/* Application State Machine Functions */
void APP_Initialize( void );
void APP_Tasks( void );
#endif	/* APP_H */

