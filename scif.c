/// \addtogroup module_scif_driver_setup
//@{
#include "scif.h"
#include "scif_framework.h"
#undef DEVICE_FAMILY_PATH
#if defined(DEVICE_FAMILY)
    #define DEVICE_FAMILY_PATH(x) <ti/devices/DEVICE_FAMILY/x>
#elif defined(DeviceFamily_CC26X0)
    #define DEVICE_FAMILY_PATH(x) <ti/devices/cc26x0/x>
#elif defined(DeviceFamily_CC26X0R2)
    #define DEVICE_FAMILY_PATH(x) <ti/devices/cc26x0r2/x>
#elif defined(DeviceFamily_CC13X0)
    #define DEVICE_FAMILY_PATH(x) <ti/devices/cc13x0/x>
#else
    #define DEVICE_FAMILY_PATH(x) <x>
#endif
#include DEVICE_FAMILY_PATH(inc/hw_types.h)
#include DEVICE_FAMILY_PATH(inc/hw_memmap.h)
#include DEVICE_FAMILY_PATH(inc/hw_aon_event.h)
#include DEVICE_FAMILY_PATH(inc/hw_aon_rtc.h)
#include DEVICE_FAMILY_PATH(inc/hw_aon_wuc.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_sce.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_smph.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_evctl.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_aiodio.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_timer.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_wuc.h)
#include DEVICE_FAMILY_PATH(inc/hw_event.h)
#include DEVICE_FAMILY_PATH(inc/hw_ints.h)
#include DEVICE_FAMILY_PATH(inc/hw_ioc.h)
#include <string.h>
#if defined(__IAR_SYSTEMS_ICC__)
    #include <intrinsics.h>
#endif


// OSAL function prototypes
uint32_t scifOsalEnterCriticalSection(void);
void scifOsalLeaveCriticalSection(uint32_t key);




/// Firmware image to be uploaded to the AUX RAM
static const uint16_t pAuxRamImage[] = {
    /*0x0000*/ 0x1408, 0x040C, 0x1408, 0x042C, 0x1408, 0x0447, 0x1408, 0x044D, 0x4436, 0x2437, 0xAEFE, 0xADB7, 0x6442, 0x7000, 0x7C6B, 0x6872, 
    /*0x0020*/ 0x0068, 0x1425, 0x6873, 0x0069, 0x1425, 0x6874, 0x006A, 0x1425, 0x786B, 0xF801, 0xFA01, 0xBEF2, 0x7870, 0x6872, 0xFD0E, 0x6874, 
    /*0x0040*/ 0xED92, 0xFD06, 0x7C70, 0x642D, 0x0450, 0x786B, 0x8F1F, 0xED8F, 0xEC01, 0xBE01, 0xADB7, 0x8DB7, 0x6630, 0x6542, 0x0000, 0x1870, 
    /*0x0060*/ 0x9D88, 0x9C01, 0xB60D, 0x1067, 0xAF19, 0xAA00, 0xB609, 0xA8FF, 0xAF39, 0xBE06, 0x0C6B, 0x8869, 0x8F08, 0xFD47, 0x9DB7, 0x086B, 
    /*0x0080*/ 0x8801, 0x8A01, 0xBEEC, 0x262F, 0xAEFE, 0x4630, 0x0450, 0x5527, 0x6642, 0x0000, 0x0C6B, 0x15C0, 0x0450, 0x6742, 0x03FF, 0x0C6D, 
    /*0x00A0*/ 0x786C, 0x686D, 0xED37, 0xB605, 0x0000, 0x0C6C, 0x7C71, 0x652D, 0x0C6D, 0x786D, 0x686E, 0xFD0E, 0xF801, 0xE92B, 0xFD0E, 0xBE01, 
    /*0x00C0*/ 0x6436, 0xBDB7, 0x241A, 0xA6FE, 0xADB7, 0x641A, 0xADB7, 0x0000, 0x00BC, 0x01BF, 0x01C6, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 
    /*0x00E0*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    /*0x0100*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    /*0x0120*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    /*0x0140*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    /*0x0160*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6000, 0x15CD, 0x6CBB, 0x1000, 
    /*0x0180*/ 0x9A24, 0xAE01, 0x05BC, 0x5009, 0x4040, 0x68BB, 0x70CA, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x5009, 0x4003, 0x68BB, 0x70D3, 
    /*0x01A0*/ 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x6000, 0x15CD, 0x6CBB, 0x5000, 0x68BB, 0x70DE, 0x7DE7, 0x70AE, 0x061C, 0x09E4, 0x6CBB, 
    /*0x01C0*/ 0x5002, 0x4000, 0x68BB, 0x70E7, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x5003, 0x4000, 0x68BB, 0x70F0, 0x7DE7, 0x70AE, 0x05E8, 
    /*0x01E0*/ 0x09E4, 0x6CBB, 0x5004, 0x4000, 0x68BB, 0x70F9, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x5005, 0x4000, 0x68BB, 0x7102, 0x7DE7, 
    /*0x0200*/ 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x5006, 0x4000, 0x68BB, 0x710B, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x5008, 0x4050, 0x68BB, 
    /*0x0220*/ 0x7114, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x5021, 0x4001, 0x68BB, 0x711D, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x500A, 
    /*0x0240*/ 0x4027, 0x68BB, 0x7126, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x500C, 0x4000, 0x68BB, 0x712F, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 
    /*0x0260*/ 0x6CBB, 0x500D, 0x407F, 0x68BB, 0x7138, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x7093, 0x600E, 0x164D, 0x5000, 0x68BB, 0x7143, 
    /*0x0280*/ 0x7DE7, 0x70AE, 0x061C, 0x09E4, 0x6CBB, 0x5000, 0x68BB, 0x714B, 0x7DE7, 0x70AE, 0x061C, 0x09E4, 0x6CBB, 0x5001, 0x68BB, 0x7153, 
    /*0x02A0*/ 0x7DE7, 0x70AE, 0x061C, 0x09E4, 0x6CBB, 0x6000, 0x15CD, 0x6CBB, 0x70AE, 0x68BB, 0x15FE, 0x6CBB, 0x7007, 0x68BB, 0x15FE, 0x6CBB, 
    /*0x02C0*/ 0x68BB, 0x15F3, 0x6CBB, 0x0000, 0x68BB, 0x15C7, 0x6CBB, 0x70AF, 0x68BB, 0x15FE, 0x6CBB, 0x7000, 0x68BB, 0x162E, 0x6CBB, 0x7000, 
    /*0x02E0*/ 0x68BB, 0x162E, 0x6CBB, 0x7000, 0x68BB, 0x162E, 0x6CBB, 0x7000, 0x68BB, 0x162E, 0x6CBB, 0xCD47, 0x7000, 0x68BB, 0x162E, 0x6CBB, 
    /*0x0300*/ 0xAD47, 0x7001, 0x68BB, 0x162E, 0x6CBB, 0xCDA0, 0xCD0A, 0x2075, 0xCF3A, 0x2098, 0xFF3A, 0x8801, 0x8A23, 0xAED6, 0x0005, 0x0C77, 
    /*0x0320*/ 0x68BB, 0x15F3, 0x6CBB, 0x5021, 0x4001, 0x68BB, 0x719A, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x501F, 0x68BB, 0x71A2, 0x7DE7, 
    /*0x0340*/ 0x70AE, 0x061C, 0x09E4, 0x6CBB, 0x7C96, 0x5020, 0x68BB, 0x71AB, 0x7DE7, 0x70AE, 0x061C, 0x09E4, 0x6CBB, 0x7C97, 0x5009, 0x4080, 
    /*0x0360*/ 0x68BB, 0x71B5, 0x7DE7, 0x70AE, 0x05E8, 0x09E4, 0x6CBB, 0x086C, 0x8201, 0x0C6C, 0x9801, 0x04C0, 0x0001, 0x0C67, 0xADB7, 0xADB7, 
    /*0x0380*/ 0x086C, 0x8201, 0x0C6C, 0x7025, 0x1653, 0xADB7, 0xADB7, 0x53F4, 0x15D2, 0x670F, 0x15D5, 0x53F4, 0x15D2, 0x460F, 0x53F8, 0x15D2, 
    /*0x03A0*/ 0x470F, 0xADB7, 0xD802, 0xDEFE, 0xADB7, 0x53FF, 0x2713, 0xAE0B, 0x2713, 0xAE09, 0x2713, 0xAE07, 0x2713, 0xAE05, 0x2713, 0xAE03, 
    /*0x03C0*/ 0xD801, 0xBEF4, 0xE202, 0xADB7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0DE4, 0x5DE5, 0x15CD, 0x15FE, 0x79E5, 0x15FE, 0xFD44, 0x15FE, 
    /*0x03E0*/ 0x09E7, 0x15F3, 0x8DB7, 0x460F, 0x53F4, 0x15D2, 0x670F, 0x15D5, 0x53FD, 0x15D2, 0x660F, 0x53F5, 0x15D2, 0xADB7, 0xEA00, 0xBE1B, 
    /*0x0400*/ 0xB50E, 0xFDA1, 0x8601, 0xFC00, 0xB602, 0x660F, 0x8E02, 0x460F, 0xFD47, 0x53FA, 0x15D2, 0x670F, 0x15D5, 0x53FD, 0x15D2, 0x470F, 
    /*0x0420*/ 0x660F, 0x53F4, 0x15D2, 0x670F, 0x15D5, 0x53FA, 0x15D2, 0x2613, 0xA601, 0xE201, 0x470F, 0xADB7, 0x0DE4, 0x5DE5, 0x7DE6, 0x15CD, 
    /*0x0440*/ 0x15FE, 0x79E5, 0x15FE, 0xEA00, 0xBE06, 0x15C7, 0x79E6, 0xF201, 0x15FE, 0x7001, 0x162E, 0x09E7, 0x15F3, 0x8DB7, 0xEA00, 0xBE1C, 
    /*0x0460*/ 0xB50B, 0x660F, 0x53F5, 0x15D2, 0x670F, 0x15D5, 0x53FF, 0x15D2, 0xFDA1, 0x2613, 0xA601, 0xF201, 0x470F, 0x8601, 0xFC00, 0xB602, 
    /*0x0480*/ 0x660F, 0x8E02, 0x460F, 0xFD47, 0x53F9, 0x15D2, 0x670F, 0x15D5, 0x53FD, 0x15D2, 0x470F, 0xF0FF, 0xADB7, 0xFB0C, 0xEDA4, 0xEB09, 
    /*0x04A0*/ 0x640B, 0xCDB1, 0xADB7, 0x5527, 0x6642, 0x862B, 0xF200, 0xFB27, 0xADB7
};


/// Look-up table that converts from AUX I/O index to MCU IOCFG offset
static const uint8_t pAuxIoIndexToMcuIocfgOffsetLut[] = {
    120, 116, 112, 108, 104, 100, 96, 92, 28, 24, 20, 16, 12, 8, 4, 0
};


/** \brief Look-up table of data structure information for each task
  *
  * There is one entry per data structure (\c cfg, \c input, \c output and \c state) per task:
  * - [31:20] Data structure size (number of 16-bit words)
  * - [19:12] Buffer count (when 2+, first data structure is preceded by buffering control variables)
  * - [11:0] Address of the first data structure
  */
static const uint32_t pScifTaskDataStructInfoLut[] = {
//  cfg         input       output      state       
    0x00000000, 0x00000000, 0x046010EA, 0x00101176  // New task
};




// No run-time logging task data structure signatures needed in this project




// No task-specific initialization functions




// No task-specific uninitialization functions




/** \brief Initilializes task resource hardware dependencies
  *
  * This function is called by the internal driver initialization function, \ref scifInit().
  */
static void scifTaskResourceInit(void) {
    scifInitIo(11, AUXIOMODE_OPEN_DRAIN_WITH_INPUT | (1 << BI_AUXIOMODE_OUTPUT_DRIVE_STRENGTH), -1, 1);
    HWREG((IOC_BASE + IOC_O_IOCFG0) + pAuxIoIndexToMcuIocfgOffsetLut[11]) |= IOC_IOCFG0_HYST_EN_M;
    scifInitIo(10, AUXIOMODE_OPEN_DRAIN_WITH_INPUT | (1 << BI_AUXIOMODE_OUTPUT_DRIVE_STRENGTH), -1, 1);
    HWREG((IOC_BASE + IOC_O_IOCFG0) + pAuxIoIndexToMcuIocfgOffsetLut[10]) |= IOC_IOCFG0_HYST_EN_M;
    HWREG(AON_WUC_BASE + AON_WUC_O_AUXCLK) = (AON_WUC_AUXCLK_SRC_SCLK_HF | AON_WUC_AUXCLK_SCLK_HF_DIV_DIV2) | AON_WUC_AUXCLK_PWR_DWN_SRC_SCLK_LF;
    HWREG(AON_RTC_BASE + AON_RTC_O_CTL) |= AON_RTC_CTL_RTC_4KHZ_EN;
} // scifTaskResourceInit




/** \brief Uninitilializes task resource hardware dependencies
  *
  * This function is called by the internal driver uninitialization function, \ref scifUninit().
  */
static void scifTaskResourceUninit(void) {
    scifUninitIo(11, -1);
    scifUninitIo(10, -1);
    HWREG(AON_WUC_BASE + AON_WUC_O_AUXCLK) = (AON_WUC_AUXCLK_SRC_SCLK_HF | AON_WUC_AUXCLK_SCLK_HF_DIV_DIV2) | AON_WUC_AUXCLK_PWR_DWN_SRC_NONE;
    HWREG(AON_RTC_BASE + AON_RTC_O_CTL) &= ~AON_RTC_CTL_RTC_4KHZ_EN;
} // scifTaskResourceUninit




/** \brief Re-initializes I/O pins used by the specified tasks
  *
  * It is possible to stop a Sensor Controller task and let the System CPU borrow and operate its I/O
  * pins. For example, the Sensor Controller can operate an SPI interface in one application state while
  * the System CPU with SSI operates the SPI interface in another application state.
  *
  * This function must be called before \ref scifExecuteTasksOnceNbl() or \ref scifStartTasksNbl() if
  * I/O pins belonging to Sensor Controller tasks have been borrowed System CPU peripherals.
  *
  * \param[in]      bvTaskIds
  *     Bit-vector of task IDs for the task I/Os to be re-initialized
  */
void scifReinitTaskIo(uint32_t bvTaskIds) {
    if (bvTaskIds & (1 << SCIF_NEW_TASK_TASK_ID)) {
        scifReinitIo(11, -1, 1);
        HWREG((IOC_BASE + IOC_O_IOCFG0) + pAuxIoIndexToMcuIocfgOffsetLut[11]) |= IOC_IOCFG0_HYST_EN_M;
        scifReinitIo(10, -1, 1);
        HWREG((IOC_BASE + IOC_O_IOCFG0) + pAuxIoIndexToMcuIocfgOffsetLut[10]) |= IOC_IOCFG0_HYST_EN_M;
    }
} // scifReinitTaskIo




/// Driver setup data, to be used in the call to \ref scifInit()
const SCIF_DATA_T scifDriverSetup = {
    (volatile SCIF_INT_DATA_T*) 0x400E00D6,
    (volatile SCIF_TASK_CTRL_T*) 0x400E00E0,
    (volatile uint16_t*) 0x400E00CE,
    0x0000,
    sizeof(pAuxRamImage),
    pAuxRamImage,
    pScifTaskDataStructInfoLut,
    pAuxIoIndexToMcuIocfgOffsetLut,
    scifTaskResourceInit,
    scifTaskResourceUninit,
    (volatile uint16_t*) NULL,
    (volatile uint16_t*) NULL,
    NULL
};




/** \brief Starts or modifies RTC-based task scheduling tick generation
  *
  * RTC-based tick generation will wake up the Sensor Controller first at the specified value of the RTC
  * and then periodically at the specified interval. The application must call this function after
  * calling \ref scifInit().
  *
  * The application must ensure that:
  * - \a tickStart is not in the past (prefer using \ref scifStartRtcTicksNow() to avoid this)
  * - \a tickPeriod is not too short. RTC ticks will be skipped silently if the Sensor Controller does
  *   not complete its tasks within a single tick interval.
  *
  * \param[in]      tickStart
  *     RTC value when the first tick is generated:
  *     - Bits 31:16 = seconds
  *     - Bits 15:0 = 1/65536 of a second
  * \param[in]      tickPeriod
  *     Interval at which subsequent ticks are generated:
  *     - Bits 31:16 = seconds
  *     - Bits 15:0 = 1/65536 of a second
  */
void scifStartRtcTicks(uint32_t tickStart, uint32_t tickPeriod) {
    HWREG(AON_RTC_BASE + AON_RTC_O_CH2CMP) = tickStart;
    HWREG(AON_RTC_BASE + AON_RTC_O_CH2CMPINC) = tickPeriod;
    HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) |= AON_RTC_CHCTL_CH2_EN_M | AON_RTC_CHCTL_CH2_CONT_EN_M;
    HWREG(AON_EVENT_BASE + AON_EVENT_O_AUXWUSEL) =
        (HWREG(AON_EVENT_BASE + AON_EVENT_O_AUXWUSEL) & ~AON_EVENT_AUXWUSEL_WU0_EV_M) |
        (AON_EVENT_AUXWUSEL_WU0_EV_RTC_CH2);
} // scifStartRtcTicks




/** \brief Starts or modifies RTC-based task scheduling tick generation
  *
  * RTC-based tick generation will wake up the Sensor Controller first after approximately 128 us and
  * then periodically at the specified interval. The application must call this function after calling
  * \ref scifInit().
  *
  * The application must ensure that \a tickPeriod is not too short. RTC ticks will be skipped silently
  * if the Sensor Controller does not complete its tasks within a single tick interval.
  *
  * \param[in]      tickPeriod
  *     Interval at which subsequent ticks are generated:
  *     - Bits 31:16 = seconds
  *     - Bits 15:0 = 1/65536 of a second
  */
void scifStartRtcTicksNow(uint32_t tickPeriod) {
    uint32_t key, sec, subsec;
    key = scifOsalEnterCriticalSection();
    sec = HWREG(AON_RTC_BASE + AON_RTC_O_SEC);
    subsec = HWREG(AON_RTC_BASE + AON_RTC_O_SUBSEC);
    scifStartRtcTicks(((sec << 16) | (subsec >> 16)) + 8, tickPeriod);
    scifOsalLeaveCriticalSection(key);
} // scifStartRtcTicksNow




/** \brief Stops RTC-based task scheduling tick generation
  *
  * The application must call this function before calling \ref scifUninit().
  */
void scifStopRtcTicks(void) {
    HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) &= ~(AON_RTC_CHCTL_CH2_EN_M | AON_RTC_CHCTL_CH2_CONT_EN_M);
    HWREG(AON_EVENT_BASE + AON_EVENT_O_AUXWUSEL) =
        (HWREG(AON_EVENT_BASE + AON_EVENT_O_AUXWUSEL) & ~AON_EVENT_AUXWUSEL_WU0_EV_M) |
        (AON_EVENT_AUXWUSEL_WU0_EV_NONE);
    HWREG(AON_RTC_BASE + AON_RTC_O_SYNC);
} // scifStopRtcTicks


//@}


// Generated by HP-ZBOOK-15 at 2025-01-30 14:44:27.275
