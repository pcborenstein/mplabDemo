#include "app.h"
/* Application Data */
APP_DATA appData;
/* Application's Timer Callback Function */
static void APP_TimerCallback ( uintptr_t context, uint32_t alarmCount )
{
    appData.timerAlarmCount++;
    if (APP_TMR_ALARM_COUNT_MAX < appData.timerAlarmCount)
    {
        appData.timerAlarmCount = 0;
    }
}
/* Application's Blinky LED Setup Function */
static void APP_BlinkyLedSetup( void )
{
    DRV_TMR_Alarm16BitRegister(appData.handleTmr, APP_TMR_ALARM_PERIOD, true,
                                (uintptr_t)NULL, APP_TimerCallback);
    DRV_TMR_Start(appData.handleTmr);
    SYS_PORTS_PinDirectionSelect(PORTS_ID_0, SYS_PORTS_DIRECTION_OUTPUT,
                                APP_LED_PORT, APP_LED_PIN);
}
/* Application's Blinky LED Update Function */
static void APP_BlinkyLedUpdate( void )
{
    if ( appData.timerAlarmCount < APP_TMR_ALARM_COUNT_LED_ON )
    {
        if (!appData.ledIsOn)
        {
            appData.ledIsOn = true;
            SYS_PORTS_PinSet(PORTS_ID_0, APP_LED_PORT, APP_LED_PIN);
        }
    }
    else
    {
        if (appData.ledIsOn)
        {
            appData.ledIsOn = false;
            SYS_PORTS_PinClear(PORTS_ID_0, APP_LED_PORT, APP_LED_PIN);
        }
    }
}
/* Application State Machine */
void APP_Initialize ( void )
{
    appData.state = APP_STATE_INIT;
    appData.timerAlarmCount = 0;
    appData.ledIsOn = false;
}

void APP_Tasks ( void )
{
    switch ( appData.state )
    {
    case APP_STATE_INIT:
    {
        appData.handleTmr = DRV_TMR_Open(APP_TMR_DRV_INDEX, DRV_IO_INTENT_EXCLUSIVE);
        if( DRV_HANDLE_INVALID != appData.handleTmr )
        {
            APP_BlinkyLedSetup();
            appData.state = APP_STATE_WAIT_FOR_ALARM;
        }
    break;
    }
    case APP_STATE_WAIT_FOR_ALARM:
    {
        APP_BlinkyLedUpdate();
    break;
    }
    default:
    {
     break;
    }
}
}
