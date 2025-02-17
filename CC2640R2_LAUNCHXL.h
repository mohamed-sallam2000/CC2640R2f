/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       CC2640R2_LAUNCHXL.h
 *
 *  @brief      CC2640R2 LaunchPad Board Specific header file.
 *
 *  This file is responsible for setting up the board specific items for the
 *  CC2640R2_LAUNCHXL board.
 *
 *  This board file is made for the 7x7 mm QFN package, to convert this board
 *  file to use for other smaller device packages(5x5 mm and 4x4 mm QFN), the
 *  board will need to be modified since all the IO pins are not available for
 *  smaller packages. Note that the 2.7 x 2.7 mm WCSP package should use a
 *  separate board file also included within the SDK.
 *
 *  Refer to the datasheet for all the package options and IO descriptions:
 *  http://www.ti.com/lit/ds/symlink/cc2640r2f.pdf
 *
 *  For example, to change to the 4x4 package, remove all defines for all IOs
 *  not available (IOID_10 and higher) since the 4x4 package
 *  has only 10 DIO pins as listed in the datasheet. Remove the modules/pins
 *  not used including ADC, Display, SPI1, LED, and PIN due to limited pins.
 *  ============================================================================
 */
#ifndef __CC2640R2_LAUNCHXL_BOARD_H__
#define __CC2640R2_LAUNCHXL_BOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include <ti/drivers/PIN.h>
#include <ti/devices/cc26x0r2/driverlib/ioc.h>

/* Externs */
extern const PIN_Config BoardGpioInitTable[];

/* Defines */
#define CC2640R2_LAUNCHXL

/* Mapping of pins to board signals using general board aliases
 *      <board signal alias>                  <pin mapping>
 */

/* Analog Capable DIOs */
#define CC2640R2_LAUNCHXL_DIO23_ANALOG          IOID_23
#define CC2640R2_LAUNCHXL_DIO24_ANALOG          IOID_24
#define CC2640R2_LAUNCHXL_DIO25_ANALOG          IOID_25
#define CC2640R2_LAUNCHXL_DIO26_ANALOG          IOID_26
#define CC2640R2_LAUNCHXL_DIO27_ANALOG          IOID_27
#define CC2640R2_LAUNCHXL_DIO28_ANALOG          IOID_28
#define CC2640R2_LAUNCHXL_DIO29_ANALOG          IOID_29
#define CC2640R2_LAUNCHXL_DIO30_ANALOG          IOID_30

/* Digital IOs */
#define CC2640R2_LAUNCHXL_DIO0                  IOID_0
#define CC2640R2_LAUNCHXL_DIO1_RFSW             IOID_1
#define CC2640R2_LAUNCHXL_DIO12                 IOID_12
#define CC2640R2_LAUNCHXL_DIO15                 IOID_15
#define CC2640R2_LAUNCHXL_DIO16_TDO             IOID_16
#define CC2640R2_LAUNCHXL_DIO17_TDI             IOID_17
#define CC2640R2_LAUNCHXL_DIO21                 IOID_21
#define CC2640R2_LAUNCHXL_DIO22                 IOID_22

/* Discrete Inputs */
#define CC2640R2_LAUNCHXL_PIN_BTN1              IOID_13
#define CC2640R2_LAUNCHXL_PIN_BTN2              IOID_14

/* GPIO */
#define CC2640R2_LAUNCHXL_GPIO_LED_ON           1
#define CC2640R2_LAUNCHXL_GPIO_LED_OFF          0

/* I2C */
#define CC2640R2_LAUNCHXL_I2C0_SCL0             IOID_5
#define CC2640R2_LAUNCHXL_I2C0_SDA0             IOID_4

/* I2S */
#define CC2640R2_LAUNCHXL_I2S_ADO               IOID_0
#define CC2640R2_LAUNCHXL_I2S_ADI               IOID_1
#define CC2640R2_LAUNCHXL_I2S_BCLK              IOID_30
#define CC2640R2_LAUNCHXL_I2S_MCLK              PIN_UNASSIGNED
#define CC2640R2_LAUNCHXL_I2S_WCLK              IOID_29

/* LEDs */
#define CC2640R2_LAUNCHXL_PIN_LED_ON            1
#define CC2640R2_LAUNCHXL_PIN_LED_OFF           0
#define CC2640R2_LAUNCHXL_PIN_RLED              IOID_6
#define CC2640R2_LAUNCHXL_PIN_GLED              IOID_7

/* PWM Outputs */
#define CC2640R2_LAUNCHXL_PWMPIN0               CC2640R2_LAUNCHXL_PIN_RLED
#define CC2640R2_LAUNCHXL_PWMPIN1               CC2640R2_LAUNCHXL_PIN_GLED
#define CC2640R2_LAUNCHXL_PWMPIN2               PIN_UNASSIGNED
#define CC2640R2_LAUNCHXL_PWMPIN3               PIN_UNASSIGNED
#define CC2640R2_LAUNCHXL_PWMPIN4               PIN_UNASSIGNED
#define CC2640R2_LAUNCHXL_PWMPIN5               PIN_UNASSIGNED
#define CC2640R2_LAUNCHXL_PWMPIN6               PIN_UNASSIGNED
#define CC2640R2_LAUNCHXL_PWMPIN7               PIN_UNASSIGNED

/* SPI */
#define CC2640R2_LAUNCHXL_SPI_FLASH_CS          IOID_20
#define CC2640R2_LAUNCHXL_FLASH_CS_ON           0
#define CC2640R2_LAUNCHXL_FLASH_CS_OFF          1

/* SPI Board */
#define CC2640R2_LAUNCHXL_SPI0_MISO             IOID_8          /* RF1.20 */
#define CC2640R2_LAUNCHXL_SPI0_MOSI             IOID_9          /* RF1.18 */
#define CC2640R2_LAUNCHXL_SPI0_CLK              IOID_10         /* RF1.16 */
#define CC2640R2_LAUNCHXL_SPI0_CSN              IOID_11
#define CC2640R2_LAUNCHXL_SPI1_MISO             PIN_UNASSIGNED
#define CC2640R2_LAUNCHXL_SPI1_MOSI             PIN_UNASSIGNED
#define CC2640R2_LAUNCHXL_SPI1_CLK              PIN_UNASSIGNED
#define CC2640R2_LAUNCHXL_SPI1_CSN              PIN_UNASSIGNED

/* UART Board */
#define CC2640R2_LAUNCHXL_UART_RX               IOID_2          /* RXD */
#define CC2640R2_LAUNCHXL_UART_TX               IOID_3          /* TXD */
#define CC2640R2_LAUNCHXL_UART_CTS              IOID_19         /* CTS */
#define CC2640R2_LAUNCHXL_UART_RTS              IOID_18         /* RTS */

/*!
 *  @brief  Initialize the general board specific settings
 *
 *  This function initializes the general board specific settings.
 */
void CC2640R2_LAUNCHXL_initGeneral(void);

/*!
 *  @brief  Turn off the external flash on LaunchPads
 *
 */
void CC2640R2_LAUNCHXL_shutDownExtFlash(void);

/*!
 *  @brief  Wake up the external flash present on the board files
 *
 *  This function toggles the chip select for the amount of time needed
 *  to wake the chip up.
 */
void CC2640R2_LAUNCHXL_wakeUpExtFlash(void);

/*!
 *  @def    CC2640R2_LAUNCHXL_ADCBufName
 *  @brief  Enum of ADCs
 */
typedef enum CC2640R2_LAUNCHXL_ADCBufName {
    CC2640R2_LAUNCHXL_ADCBUF0 = 0,

    CC2640R2_LAUNCHXL_ADCBUFCOUNT
} CC2640R2_LAUNCHXL_ADCBufName;

/*!
 *  @def    CC2640R2_LAUNCHXL_ADCBuf0SourceName
 *  @brief  Enum of ADCBuf channels
 */
typedef enum CC2640R2_LAUNCHXL_ADCBuf0ChannelName {
    CC2640R2_LAUNCHXL_ADCBUF0CHANNEL0 = 0,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNEL1,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNEL2,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNEL3,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNEL4,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNEL5,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNEL6,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNEL7,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNELVDDS,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNELDCOUPL,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNELVSS,

    CC2640R2_LAUNCHXL_ADCBUF0CHANNELCOUNT
} CC2640R2_LAUNCHXL_ADCBuf0ChannelName;

/*!
 *  @def    CC2640R2_LAUNCHXL_ADCName
 *  @brief  Enum of ADCs
 */
typedef enum CC2640R2_LAUNCHXL_ADCName {
    CC2640R2_LAUNCHXL_ADC0 = 0,
    CC2640R2_LAUNCHXL_ADC1,
    CC2640R2_LAUNCHXL_ADC2,
    CC2640R2_LAUNCHXL_ADC3,
    CC2640R2_LAUNCHXL_ADC4,
    CC2640R2_LAUNCHXL_ADC5,
    CC2640R2_LAUNCHXL_ADC6,
    CC2640R2_LAUNCHXL_ADC7,
    CC2640R2_LAUNCHXL_ADCDCOUPL,
    CC2640R2_LAUNCHXL_ADCVSS,
    CC2640R2_LAUNCHXL_ADCVDDS,

    CC2640R2_LAUNCHXL_ADCCOUNT
} CC2640R2_LAUNCHXL_ADCName;

/*!
 *  @def    CC2640R2_LAUNCHXL_CryptoName
 *  @brief  Enum of Crypto names
 */
typedef enum CC2640R2_LAUNCHXL_CryptoName {
    CC2640R2_LAUNCHXL_CRYPTO0 = 0,

    CC2640R2_LAUNCHXL_CRYPTOCOUNT
} CC2640R2_LAUNCHXL_CryptoName;

/*!
 *  @def    CC2640R2_LAUNCHXL_AESCCMName
 *  @brief  Enum of AESCCM names
 */
typedef enum CC2640R2_LAUNCHXL_AESCCMName {
    CC2640R2_LAUNCHXL_AESCCM0 = 0,

    CC2640R2_LAUNCHXL_AESCCMCOUNT
} CC2640R2_LAUNCHXL_AESCCMName;

/*!
 *  @def    CC2640R2_LAUNCHXL_AESGCMName
 *  @brief  Enum of AESGCM names
 */
typedef enum CC2640R2_LAUNCHXL_AESGCMName {
    CC2640R2_LAUNCHXL_AESGCM0 = 0,

    CC2640R2_LAUNCHXL_AESGCMCOUNT
} CC2640R2_LAUNCHXL_AESGCMName;

/*!
 *  @def    CC2640R2_LAUNCHXL_AESCBCName
 *  @brief  Enum of AESCBC names
 */
typedef enum CC2640R2_LAUNCHXL_AESCBCName {
    CC2640R2_LAUNCHXL_AESCBC0 = 0,

    CC2640R2_LAUNCHXL_AESCBCCOUNT
} CC2640R2_LAUNCHXL_AESCBCName;

/*!
 *  @def    CC2640R2_LAUNCHXL_AESCTRName
 *  @brief  Enum of AESCTR names
 */
typedef enum CC2640R2_LAUNCHXL_AESCTRName {
    CC2640R2_LAUNCHXL_AESCTR0 = 0,

    CC2640R2_LAUNCHXL_AESCTRCOUNT
} CC2640R2_LAUNCHXL_AESCTRName;

/*!
 *  @def    CC2640R2_LAUNCHXL_AESECBName
 *  @brief  Enum of AESECB names
 */
typedef enum CC2640R2_LAUNCHXL_AESECBName {
    CC2640R2_LAUNCHXL_AESECB0 = 0,

    CC2640R2_LAUNCHXL_AESECBCOUNT
} CC2640R2_LAUNCHXL_AESECBName;

/*!
 *  @def    CC2640R2_LAUNCHXL_AESCTRDRBGName
 *  @brief  Enum of AESCTRDRBG names
 */
typedef enum CC2640R2_LAUNCHXL_AESCTRDRBGName {
    CC2640R2_LAUNCHXL_AESCTRDRBG0 = 0,

    CC2640R2_LAUNCHXL_AESCTRDRBGCOUNT
} CC2640R2_LAUNCHXL_AESCTRDRBGName;

/*!
 *  @def    CC2640R2_LAUNCHXL_TRNGName
 *  @brief  Enum of TRNG names
 */
typedef enum CC2640R2_LAUNCHXL_TRNGName {
    CC2640R2_LAUNCHXL_TRNG0 = 0,

    CC2640R2_LAUNCHXL_TRNGCOUNT
} CC2640R2_LAUNCHXL_TRNGName;

/*!
 *  @def    CC2640R2_LAUNCHXL_GPIOName
 *  @brief  Enum of GPIO names
 */
typedef enum CC2640R2_LAUNCHXL_GPIOName {
    CC2640R2_LAUNCHXL_GPIO_S1 = 0,
    CC2640R2_LAUNCHXL_GPIO_S2,
    CC2640R2_LAUNCHXL_SPI_MASTER_READY,
    CC2640R2_LAUNCHXL_SPI_SLAVE_READY,
    CC2640R2_LAUNCHXL_GPIO_LED_GREEN,
    CC2640R2_LAUNCHXL_GPIO_LED_RED,
    CC2640R2_LAUNCHXL_GPIO_TMP116_EN,
    CC2640R2_LAUNCHXL_GPIO_SPI_FLASH_CS,
    CC2640R2_LAUNCHXL_SDSPI_CS,
    CC2640R2_LAUNCHXL_GPIO_LCD_CS,
    CC2640R2_LAUNCHXL_GPIO_LCD_POWER,
    CC2640R2_LAUNCHXL_GPIO_LCD_ENABLE,
    CC2640R2_LAUNCHXL_GPIOCOUNT
} CC2640R2_LAUNCHXL_GPIOName;

/*!
 *  @def    CC2640R2_LAUNCHXL_GPTimerName
 *  @brief  Enum of GPTimer parts
 */
typedef enum CC2640R2_LAUNCHXL_GPTimerName {
    CC2640R2_LAUNCHXL_GPTIMER0A = 0,
    CC2640R2_LAUNCHXL_GPTIMER0B,
    CC2640R2_LAUNCHXL_GPTIMER1A,
    CC2640R2_LAUNCHXL_GPTIMER1B,
    CC2640R2_LAUNCHXL_GPTIMER2A,
    CC2640R2_LAUNCHXL_GPTIMER2B,
    CC2640R2_LAUNCHXL_GPTIMER3A,
    CC2640R2_LAUNCHXL_GPTIMER3B,

    CC2640R2_LAUNCHXL_GPTIMERPARTSCOUNT
} CC2640R2_LAUNCHXL_GPTimerName;

/*!
 *  @def    CC2640R2_LAUNCHXL_GPTimers
 *  @brief  Enum of GPTimers
 */
typedef enum CC2640R2_LAUNCHXL_GPTimers {
    CC2640R2_LAUNCHXL_GPTIMER0 = 0,
    CC2640R2_LAUNCHXL_GPTIMER1,
    CC2640R2_LAUNCHXL_GPTIMER2,
    CC2640R2_LAUNCHXL_GPTIMER3,

    CC2640R2_LAUNCHXL_GPTIMERCOUNT
} CC2640R2_LAUNCHXL_GPTimers;

/*!
 *  @def    CC2640R2_LAUNCHXL_I2CName
 *  @brief  Enum of I2C names
 */
typedef enum CC2640R2_LAUNCHXL_I2CName {
    CC2640R2_LAUNCHXL_I2C0 = 0,

    CC2640R2_LAUNCHXL_I2CCOUNT
} CC2640R2_LAUNCHXL_I2CName;

/*!
 *  @def    CC2640R2_LAUNCHXL_I2SName
 *  @brief  Enum of I2S names
 */
typedef enum CC2640R2_LAUNCHXL_I2SName {
    CC2640R2_LAUNCHXL_I2S0 = 0,

    CC2640R2_LAUNCHXL_I2SCOUNT
} CC2640R2_LAUNCHXL_I2SName;

/*!
 *  @def    CC2640R2_LAUNCHXL_NVSName
 *  @brief  Enum of NVS names
 */
typedef enum CC2640R2_LAUNCHXL_NVSName {
#ifndef Board_EXCLUDE_NVS_INTERNAL_FLASH
    CC2640R2_LAUNCHXL_NVSCC26XX0 = 0,
#endif
#ifndef Board_EXCLUDE_NVS_EXTERNAL_FLASH
    CC2640R2_LAUNCHXL_NVSSPI25X0,
#endif

    CC2640R2_LAUNCHXL_NVSCOUNT
} CC2640R2_LAUNCHXL_NVSName;

/*!
 *  @def    CC2640R2_LAUNCHXL_PWM
 *  @brief  Enum of PWM outputs
 */
typedef enum CC2640R2_LAUNCHXL_PWMName {
    CC2640R2_LAUNCHXL_PWM0 = 0,
    CC2640R2_LAUNCHXL_PWM1,
    CC2640R2_LAUNCHXL_PWM2,
    CC2640R2_LAUNCHXL_PWM3,
    CC2640R2_LAUNCHXL_PWM4,
    CC2640R2_LAUNCHXL_PWM5,
    CC2640R2_LAUNCHXL_PWM6,
    CC2640R2_LAUNCHXL_PWM7,

    CC2640R2_LAUNCHXL_PWMCOUNT
} CC2640R2_LAUNCHXL_PWMName;

/*!
 *  @def    CC2640R2_LAUNCHXL_SDName
 *  @brief  Enum of SD names
 */
typedef enum CC2640R2_LAUNCHXL_SDName {
    CC2640R2_LAUNCHXL_SDSPI0 = 0,

    CC2640R2_LAUNCHXL_SDCOUNT
} CC2640R2_LAUNCHXL_SDName;

/*!
 *  @def    CC2640R2_LAUNCHXL_SPIName
 *  @brief  Enum of SPI names
 */
typedef enum CC2640R2_LAUNCHXL_SPIName {
    CC2640R2_LAUNCHXL_SPI0 = 0,
    CC2640R2_LAUNCHXL_SPI1,

    CC2640R2_LAUNCHXL_SPICOUNT
} CC2640R2_LAUNCHXL_SPIName;

/*!
 *  @def    CC2640R2_LAUNCHXL_UARTName
 *  @brief  Enum of UARTs
 */
typedef enum CC2640R2_LAUNCHXL_UARTName {
    CC2640R2_LAUNCHXL_UART0 = 0,

    CC2640R2_LAUNCHXL_UARTCOUNT
} CC2640R2_LAUNCHXL_UARTName;

/*!
 *  @def    CC2640R2_LAUNCHXL_UDMAName
 *  @brief  Enum of DMA buffers
 */
typedef enum CC2640R2_LAUNCHXL_UDMAName {
    CC2640R2_LAUNCHXL_UDMA0 = 0,

    CC2640R2_LAUNCHXL_UDMACOUNT
} CC2640R2_LAUNCHXL_UDMAName;

/*!
 *  @def    CC2640R2_LAUNCHXL_WatchdogName
 *  @brief  Enum of Watchdogs
 */
typedef enum CC2640R2_LAUNCHXL_WatchdogName {
    CC2640R2_LAUNCHXL_WATCHDOG0 = 0,

    CC2640R2_LAUNCHXL_WATCHDOGCOUNT
} CC2640R2_LAUNCHXL_WatchdogName;

#ifdef __cplusplus
}
#endif

#endif /* __CC2640R2_LAUNCHXL_BOARD_H__ */
