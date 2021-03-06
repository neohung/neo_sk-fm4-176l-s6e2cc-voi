#ifndef __INTERRUPTS_FM3_H__
#define __INTERRUPTS_FM3_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/

#include "pdl_user.h"

#if (PDL_MCU_CORE == PDL_FM3_CORE)

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup PdlInterrupts PDL Interrupt handling
 **
 ** \brief Description of the PDL Interrupt handling
 **
 ** Each device group of the FM3 MCUs may have individual interrupt service
 ** routine vector names. For this reason this file defines the device
 ** depenent vectors, if it corresponding resource is set to active in pdl.h.
 **
 ** Interrupt and Callback flow in PDL:
 ** \image html Interrupt_flow.png
 **
 ******************************************************************************/
//@{

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/

/*****************************************************************************/
/* Check whether interrupt is enable when peripheral is inactive             */
/*****************************************************************************/

// Include adc\adc.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_ADC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_ADC1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_ADC2 == PDL_ON)
    #if defined(PDL_PERIPHERAL_ADC_ACTIVE)
        #include "adc\adc.h"
    #else
        #error Dont enable ADC interrupt when it is inactive!
    #endif
#endif

// Include bt\bt.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_BT0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT10 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT11 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT12 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT13 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT14 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT15 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT3 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT4 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT5 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT6 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT7 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT8 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT9 == PDL_ON)
    #if defined(PDL_PERIPHERAL_BT_ACTIVE)
        #include "bt\bt.h"
    #else
        #error Dont enable BT interrupt when it is inactive!
    #endif
#endif

// Include can\can.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_CAN0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_CAN1 == PDL_ON)
    #if defined(PDL_PERIPHERAL_CAN_ACTIVE)
        #include "can\can.h"
    #else
        #error Dont enable CAN interrupt when it is inactive!
    #endif
#endif

// Include cec\cec.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_CEC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_CEC1 == PDL_ON)
    #if defined(PDL_PERIPHERAL_CEC_ACTIVE)
        #include "cec\cec.h"
    #else
        #error Dont enable CEC interrupt when it is inactive!
    #endif
#endif

// Include clk\clk.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_CLK == PDL_ON)
    #if defined(PDL_PERIPHERAL_CLK_ACTIVE)
        #include "clk\clk.h"
    #else
        #error Dont enable CLK interrupt when it is inactive!
    #endif
#endif

// Include csv\csv.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_CSV == PDL_ON)
    #if defined(PDL_PERIPHERAL_CSV_ACTIVE)
        #include "csv\csv.h"
    #else
        #error Dont enable CSV interrupt when it is inactive!
    #endif
#endif

// Include dma\dma.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_DMA0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_DMA1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_DMA2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_DMA3 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_DMA4 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_DMA5 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_DMA6 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_DMA7 == PDL_ON)
    #if defined(PDL_PERIPHERAL_DMA_ACTIVE)
        #include "dma\dma.h"
    #else
        #error Dont enable DMA interrupt when it is inactive!
    #endif
#endif

// Include dt\dt.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_DT0 == PDL_ON)
    #if defined(PDL_PERIPHERAL_DT_ACTIVE)
        #include "dt\dt.h"
    #else
        #error Dont enable DT interrupt when it is inactive!
    #endif
#endif

// Include ether\ether.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_ETHER0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_ETHER1 == PDL_ON)
    #if defined(PDL_PERIPHERAL_ETHER_ACTIVE)
        #include "ether\ether.h"
    #else
        #error Dont enable ETHER interrupt when it is inactive!
    #endif
#endif

// Include exint\exint.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_EXINT0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT10 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT11 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT12 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT13 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT14 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT15 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT16 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT17 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT18 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT19 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT20 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT21 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT22 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT23 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT24 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT25 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT26 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT27 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT28 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT3 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT30 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT31 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT4 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT5 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT6 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT7 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT8 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT9 == PDL_ON)
    #if defined(PDL_PERIPHERAL_EXINT_ACTIVE)
        #include "exint\exint.h"
    #else
        #error Dont enable EXINT interrupt when it is inactive!
    #endif
#endif

// Include flash\dualflash.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_DUALFLASH == PDL_ON)
    #if defined(PDL_PERIPHERAL_DUALFLASH_ACTIVE)
        #include "flash\dualflash.h"
    #else
        #error Dont enable DUALFLASH interrupt when it is inactive!
    #endif
#endif

// Include flash\mainflash.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_MAINFLASH == PDL_ON)
    #if defined(PDL_PERIPHERAL_MAINFLASH_ACTIVE)
        #include "flash\mainflash.h"
    #else
        #error Dont enable MAINFLASH interrupt when it is inactive!
    #endif
#endif

// Include flash\workflash.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_WORKFLASH == PDL_ON)
    #if defined(PDL_PERIPHERAL_WORKFLASH_ACTIVE)
        #include "flash\workflash.h"
    #else
        #error Dont enable WORKFLASH interrupt when it is inactive!
    #endif
#endif

// Include lcd\lcd.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_LCD == PDL_ON)
    #if defined(PDL_PERIPHERAL_LCD_ACTIVE)
        #include "lcd\lcd.h"
    #else
        #error Dont enable LCD interrupt when it is inactive!
    #endif
#endif

// Include lvd\lvd.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_LVD == PDL_ON)
    #if defined(PDL_PERIPHERAL_LVD_ACTIVE)
        #include "lvd\lvd.h"
    #else
        #error Dont enable LVD interrupt when it is inactive!
    #endif
#endif

// Include mfs\mfs.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_MFS0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS10 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS11 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS12 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS13 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS14 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS15 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS7 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS8 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS9 == PDL_ON)
    #if defined(PDL_PERIPHERAL_MFS_ACTIVE)
        #include "mfs\mfs.h"
    #else
        #error Dont enable MFS interrupt when it is inactive!
    #endif
#endif

// Include mft\mft_frt.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_MFT0_FRT == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFT1_FRT == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFT2_FRT == PDL_ON)
    #if defined(PDL_PERIPHERAL_MFT_FRT_ACTIVE)
        #include "mft\mft_frt.h"
    #else
        #error Dont enable MFT_FRT interrupt when it is inactive!
    #endif
#endif

// Include mft\mft_icu.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_MFT0_ICU == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFT1_ICU == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFT2_ICU == PDL_ON)
    #if defined(PDL_PERIPHERAL_MFT_ICU_ACTIVE)
        #include "mft\mft_icu.h"
    #else
        #error Dont enable MFT_ICU interrupt when it is inactive!
    #endif
#endif

// Include mft\mft_ocu.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_MFT0_OCU == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFT1_OCU == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFT2_OCU == PDL_ON)
    #if defined(PDL_PERIPHERAL_MFT_OCU_ACTIVE)
        #include "mft\mft_ocu.h"
    #else
        #error Dont enable MFT_OCU interrupt when it is inactive!
    #endif
#endif

// Include mft\mft_wfg.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_MFT0_WFG == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFT1_WFG == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFT2_WFG == PDL_ON)
    #if defined(PDL_PERIPHERAL_MFT_WFG_ACTIVE)
        #include "mft\mft_wfg.h"
    #else
        #error Dont enable MFT_WFG interrupt when it is inactive!
    #endif
#endif

// Include ppg\ppg.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_PPG == PDL_ON)
    #if defined(PDL_PERIPHERAL_PPG_ACTIVE)
        #include "ppg\ppg.h"
    #else
        #error Dont enable PPG interrupt when it is inactive!
    #endif
#endif

// Include qprc\qprc.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_QPRC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_QPRC1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_QPRC2 == PDL_ON)
    #if defined(PDL_PERIPHERAL_QPRC_ACTIVE)
        #include "qprc\qprc.h"
    #else
        #error Dont enable QPRC interrupt when it is inactive!
    #endif
#endif

// Include rcintsel\rcintsel.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_RCINTSEL0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RCINTSEL1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RCINTSEL2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RCINTSEL3 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RCINTSEL4 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RCINTSEL5 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RCINTSEL6 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RCINTSEL7 == PDL_ON)
    #if defined(PDL_PERIPHERAL_RCINTSEL_ACTIVE)
        #include "rcintsel\rcintsel.h"
    #else
        #error Dont enable RCINTSEL interrupt when it is inactive!
    #endif
#endif

// Include rtc\rtc.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_RTC == PDL_ON)
    #if defined(PDL_PERIPHERAL_RTC_ACTIVE)
        #include "rtc\rtc.h"
    #else
        #error Dont enable RTC interrupt when it is inactive!
    #endif
#endif

// Include wc\wc.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_WC == PDL_ON)
    #if defined(PDL_PERIPHERAL_WC_ACTIVE)
        #include "wc\wc.h"
    #else
        #error Dont enable WC interrupt when it is inactive!
    #endif
#endif

// Include wdg\wdg.h.h if active and interrupts are enabled.
#if (PDL_INTERRUPT_ENABLE_SWWDG == PDL_ON)
    #if defined(PDL_PERIPHERAL_WDG_ACTIVE)
        #include "wdg\wdg.h"
    #else
        #error Dont enable WDG interrupt when it is inactive!
    #endif
#endif

    #if (PDL_INTERRUPT_ENABLE_DSTC == PDL_ON)
        #if defined(PDL_PERIPHERAL_DSTC_ACTIVE)
            #include "dstc\dstc.h"
        #else
            #error Dont enable DSTC interrupt when it is inactive!
        #endif
    #endif
//@} // PdlInterrupts
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"
{
#endif
#endif // PDL_MCU_CORE == PDL_FM3_CORE)

#endif // #ifndef __INTERRUPTS_FM3_H__
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
