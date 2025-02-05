
//**************************************************************************************************/

/*
 * Copyright (c) 2018-2019, Texas Instruments Incorporated
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

/*
 *  ======== i2ctmp116.c ========
 */

// #include <cstdint>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
/*saensor controller from project max30102_with sensor controller */
// #include "scif.h"
/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>
#include <ti/display/Display.h>
#include "MAX30102.h"
/* Example/Board Header files */
#include "Board.h"
#include "scif.h"
#define TASKSTACKSIZE       640

/*
 *  ======== TMP Registers ========
 */
#define TMP006_REG          0x0001  /* Die Temp Result Register for TMP006 */
#define TMP116_REG          0x0000  /* Die Temp Result Register for TMP116 */

#define TMP006_ADDR         0x41;
#define TMP116_BP_ADDR      0x48;
#define TMP116_LP_ADDR      0x49;

static Display_Handle display;

/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    uint16_t        sample;
    uint16_t        temperature;
  

    /* Call driver init functions */
//    Display_init();
    GPIO_init();


    /* Open the HOST display for output */
//    display = Display_open(Display_Type_UART, NULL);
//     if (display == NULL) {
//         while (1);
//     }
// Display_printf(display, 0, 0, "reading  from max30102  ");;



   bspI2cInit();
   
   maxim_max30102_init();

int8_t integer_deg;
uint8_t fractinaldeg;
uint16_t xx;
maxim_max30102_wakeup();
maxim_max30102_read_fifo(&xx,&xx);
sleep(1);
    maxim_max30102_read_temperature(&integer_deg,&fractinaldeg);
    maxim_max30102_shutdown();
// Display_printf(display, 0, 0, "temperature from max30102  %d , %d \r\n\0",integer_deg,fractinaldeg);


// sleep(2);
// Display_printf(display, 0, 0, "reading  from max30102  %d  \r\n\0",scifTaskData.newTask.output.outputDataBuffer[2]);;
// Display_printf(display, 0, 0, "temperature from max30102  %d , %d \r\n\0",integer_deg,fractinaldeg);

// Initialize the SCIF operating system abstraction layer
// scifOsalInit();


// Initialize the SCIF driver
// scifInit(&scifDriverSetup);

// Enable RTC ticks, with N Hz tick interval
//1 was N
// scifStartRtcTicksNow(0x00010000 / 1);
// Initialize the SCIF driver
// scifInit(&scifDriverSetup);

// Enable RTC ticks, with N Hz tick interval
//1 was N
// scifStartRtcTicksNow(0x00010000 / 1);
//start initalizatin of sc
// scifStartTasksNbl(1 << SCIF_NEW_TASK_TASK_ID);

float x=0;
while(1)

{

maxim_max30102_wakeup();
maxim_max30102_read_fifo(&xx,&xx);

    maxim_max30102_read_temperature(&integer_deg,&fractinaldeg);
    maxim_max30102_shutdown();
    sleep(1);
// sleep(2);
// Display_printf(display, 0, 0, "reading  from max30102  %d  \r\n\0",scifTaskData.newTask.output.outputDataBuffer[5]);;
// Display_printf(display, 0, 0, "reading  from max30102  %d  \r\n\0",scifTaskData.newTask.output.outputDataBuffer[2]);;
// Display_printf(display, 0, 0, "reading  from max30102  %d  \r\n\0",scifTaskData.newTask.output.outputDataBuffer[0]);;
// Display_printf(display, 0, 0, "reading  from max30102  %d  \r\n\0",scifTaskData.newTask.output.outputDataBuffer[1]);;
// Display_printf(display, 0, 0, "reading  from max30102  %d  \r\n\0",scifTaskData.newTask.output.outputDataBuffer[4]);;
// Display_printf(display, 0, 0, "reading  from max30102  %d  \r\n\0",scifTaskData.newTask.output.outputDataBuffer[6]);;
// Display_printf(display, 0, 0, "reading  from max30102  %d  \r\n\0",scifTaskData.newTask.output.outputDataBuffer[7]);;
// Display_printf(display, 0, 0, "reading  from max30102  %d  \r\n\0",scifTaskData.newTask.output.outputDataBuffer[8]);;

}
    return (NULL);
}
