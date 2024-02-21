#ifndef PINS_H
#define PINS_H

/* aligned to BoSL v0.5.3 */
/* and in the further future this should be moved behind a HAL */

#define EN_SWA   (PIN_PA0)
#define EN_SWB   (PIN_PA1)
#define EN_SWC   (PIN_PA2)
#define EN_SWVPP (PIN_PA3)

#define SD_CS   (PIN_PB0)
#define SD_SCLK (PIN_PB1)
#define SD_MOSI (PIN_PB2)
#define SD_MISO (PIN_PB3)

#define SIM_RI_BFD  (PIN_PB5)
#define SIM_CTS_BFD (PIN_PB6)
#define LED_PIN     (PIN_PB7)

#define SIM_DTR_BFD    (PIN_PC0)
#define SIM_STATUS_BFD (PIN_PC1)
#define WDT_KICK       (PIN_PC2)

#define SCL        (PIN_PD0)
#define SDA        (PIN_PD1)
#define SIM_TX_BFD (PIN_PD2)
#define SIM_RX_BFD (PIN_PD3)
#define SIM_PWRKEY (PIN_PD4)
#define SIM_RESET  (PIN_PD6)

#define TTL_RX        (PIN_PE0)
#define TTL_TX        (PIN_PE1)
#define RTC_INTERRUPT (PIN_PE7)

#define SIM_RTS_BFD (PIN_PG0)
#define SIM_DCD_BFD (PIN_PG1)
#define CS_EXTERNAL (PIN_PG3)
#define SIM_BUF_EN  (PIN_PG4)

#define RXD2 (PIN_PH0)
#define TXD2 (PIN_PH1)

#define RXD3 (PIN_PJ0)
#define TXD3 (PIN_PJ1)

#define modem Serial1

#endif