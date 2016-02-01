#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H
/* Avoid superfluous warning messages. */
#define _PLIB_UNSUPPORTED
/* TMR Driver Configuration Options */
#define DRV_TMR_INSTANCES_NUMBER 1
#define DRV_TMR_INTERRUPT_MODE false
#define DRV_TMR_CLIENTS_NUMBER 1
#define DRV_TMR_COUNT_WIDTH 16
#define DRV_TMR_ALARM_ENABLE
#define DRV_TMR_ALARM_PERIODIC true
/* Clock System Service Configuration */
#define SYS_CLK_CONFIG_PRIMARY_XTAL (24000000UL)
#define SYS_CLK_CONFIG_SECONDARY_XTAL (32768UL)
#define SYS_CLK_CONFIG_SYSPLL_INP_DIVISOR 3
#define SYS_CLK_CONFIG_FREQ_ERROR_LIMIT 10
#endif /* _SYSTEM_CONFIG_H */