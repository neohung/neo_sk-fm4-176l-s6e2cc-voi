/*******************************************************************************
* Copyright (C) 2015 Spansion LLC. All Rights Reserved. 
*
* This software is owned and published by: 
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with Spansion 
* components. This software is licensed by Spansion to be adapted only 
* for use in systems utilizing Spansion components. Spansion shall not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein.  Spansion is providing this software "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the software.  
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
* WARRANTY OF NONINFRINGEMENT.  
* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
* SAVINGS OR PROFITS, 
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
* FROM, THE SOFTWARE.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Disclaimer and Copyright notice must be 
* included with each copy of this software, whether used in part or whole, 
* at all times.  
*/

/******************************************************************************/
/** \file interrupts.c
 **
 ** PDL Interrupt Handler
 **
 ** A detailed description is available at 
 ** @link PdlInterrupts PDL Interrupt handling description @endlink
 **
 ** History:
 **   - 2015-06-17  1.0  MWi   First version for universal PDL        
 **
 ******************************************************************************/
 #ifdef __INTERRUPTS_FM0P_TYPE_2_B_C__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/

#include "interrupts_fm0p.h"

/******************************************************************************/
/******************************* Dummy Handler ********************************/
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief Dummy Handler for not implemented peripheral handlers. During
 **        debugging a breakpoint may be set here. The argument #u32Caller
 **        contains the caller index from the handlers above.
 ******************************************************************************/

static void PDL_DummyHandler(uint32_t u32Caller)
{

    // 0: RCINTSEL0, 1: RCINTSEL1, 2: RCINTSEL2, 3: RCINTSEL3, 4: RCINTSEL4, 
    // 5: RCINTSEL5, 6: RCINTSEL6, 7: RCINTSEL7, 8: ICC0, 9: DSTC, 10: ICC1, 
    // 11: USB0_HOST|USB0_DEVICE, 12: LCD, 13: USB0_DEVICE, 14: FLASH, 

    while (1u)
    { }
}

/******************************************************************************/
/********************************* FM0P: CSV **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CSV == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: CSV IRQ handler (IRQ#0) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_CSV_AVAILABLE)
void CSV_IRQHandler(void)
{
    Csv_IrqHandler();
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM0P: SWWDG *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_SWWDG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: SWWDG IRQ handler (IRQ#1) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_SWDT_AVAILABLE)
void SWDT_IRQHandler(void)
{
    SwwdgIrqHandler();
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: LVD **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_LVD == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: LVD IRQ handler (IRQ#2) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_LVD_AVAILABLE)
void LVD_IRQHandler(void)
{
    Lvd_IrqHandler();
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: RCINTSEL0 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RCINTSEL0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: RCINTSEL0 IRQ handler (IRQ#3) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_RCINTSEL0_AVAILABLE)
void RCINTSEL0_IRQHandler(void)
{
    PDL_DummyHandler(0ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: RCINTSEL1 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RCINTSEL1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: RCINTSEL1 IRQ handler (IRQ#4) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_RCINTSEL1_AVAILABLE)
void RCINTSEL1_IRQHandler(void)
{
    PDL_DummyHandler(1ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: RCINTSEL2 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RCINTSEL2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: RCINTSEL2 IRQ handler (IRQ#5) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_RCINTSEL2_AVAILABLE)
void RCINTSEL2_IRQHandler(void)
{
    PDL_DummyHandler(2ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: RCINTSEL3 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RCINTSEL3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: RCINTSEL3 IRQ handler (IRQ#6) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_RCINTSEL3_AVAILABLE)
void RCINTSEL3_IRQHandler(void)
{
    PDL_DummyHandler(3ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: RCINTSEL4 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RCINTSEL4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: RCINTSEL4 IRQ handler (IRQ#7) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_RCINTSEL4_AVAILABLE)
void RCINTSEL4_IRQHandler(void)
{
    PDL_DummyHandler(4ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: RCINTSEL5 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RCINTSEL5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: RCINTSEL5 IRQ handler (IRQ#8) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_RCINTSEL5_AVAILABLE)
void RCINTSEL5_IRQHandler(void)
{
    PDL_DummyHandler(5ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: RCINTSEL6 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RCINTSEL6 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: RCINTSEL6 IRQ handler (IRQ#9) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_RCINTSEL6_AVAILABLE)
void RCINTSEL6_IRQHandler(void)
{
    PDL_DummyHandler(6ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: RCINTSEL7 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RCINTSEL7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: RCINTSEL7 IRQ handler (IRQ#10) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_RCINTSEL7_AVAILABLE)
void RCINTSEL7_IRQHandler(void)
{
    PDL_DummyHandler(7ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM0P: MFT0_WFG *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_WFG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFT0_WFG IRQ handler (IRQ#11) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_MFT0_WFG_DTIF_AVAILABLE)
void MFT0_WFG_DTIF_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_WFG10)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_WFG10))
    {
        Dstc_MftWfgIrqHandler(DSTC_IRQ_NUMBER_MFT0_WFG10);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_WFG32)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_WFG32))
    {
        Dstc_MftWfgIrqHandler(DSTC_IRQ_NUMBER_MFT0_WFG32);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_WFG54)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_WFG54))
    {
        Dstc_MftWfgIrqHandler(DSTC_IRQ_NUMBER_MFT0_WFG54);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFT0_WFG10 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_WFG32 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_WFG54 != PDL_ON)

        Mft_Wfg_IrqHandler((volatile stc_mftn_wfg_t*)&MFT0_WFG, &m_astcMftWfgInstanceDataLut[WfgInstanceIndexWfg0].stcInternData);


#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/**** FM0P: EXINT0, EXINT1, EXINT2, EXINT3, EXINT4, EXINT5, EXINT6, EXINT7 ****/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT3 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT4 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT5 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT6 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: EXINT0, EXINT1, EXINT2, EXINT3, EXINT4, EXINT5, EXINT6, EXINT7 IRQ handler (IRQ#12) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_EXINT0_7_AVAILABLE)
void EXINT0_7_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ12MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT0))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT0);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT1)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT1))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT2)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT2))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT2);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT3)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT3))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT3);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT4)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT4))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT4);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT5)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT5))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT5);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT6)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT6))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT6);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT7)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT7))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT7);

    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT1 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT3 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT4 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT5 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT6 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT7 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_EXINT0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(0u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(1u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT2 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        Exint_IrqHandler(2u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT3 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000008ul))
    {
        Exint_IrqHandler(3u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT4 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000010ul))
    {
        Exint_IrqHandler(4u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT5 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        Exint_IrqHandler(5u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT6 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000040ul))
    {
        Exint_IrqHandler(6u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT7 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000080ul))
    {
        Exint_IrqHandler(7u);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/* FM0P: EXINT8, EXINT9, EXINT10, EXINT11, EXINT12, EXINT13, EXINT14, EXINT15, EXINT16, EXINT17, EXINT18, EXINT19, EXINT20, EXINT21, EXINT22, EXINT23 */
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT8 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT9 == PDL_ON) || \
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
    (PDL_INTERRUPT_ENABLE_EXINT20 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT21 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT22 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT23 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: EXINT8, EXINT9, EXINT10, EXINT11, EXINT12, EXINT13, EXINT14, EXINT15, EXINT16, EXINT17, EXINT18, EXINT19, EXINT20, EXINT21, EXINT22, EXINT23 IRQ handler (IRQ#13) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_EXINT8_23_AVAILABLE)
void EXINT8_23_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ13MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT8)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT8))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT8);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT9)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT9))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT9);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT10)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT10))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT10);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT11)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT11))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT11);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT12)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT12))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT12);

    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT8 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT9 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT10 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT11 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT12 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_EXINT8 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(8u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT9 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(9u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT10 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        Exint_IrqHandler(10u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT11 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000008ul))
    {
        Exint_IrqHandler(11u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT12 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000010ul))
    {
        Exint_IrqHandler(12u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT13 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        Exint_IrqHandler(13u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT14 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000040ul))
    {
        Exint_IrqHandler(14u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT15 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000080ul))
    {
        Exint_IrqHandler(15u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT16 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000100ul))
    {
        Exint_IrqHandler(16u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT17 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000200ul))
    {
        Exint_IrqHandler(17u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT18 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000400ul))
    {
        Exint_IrqHandler(18u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT19 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000800ul))
    {
        Exint_IrqHandler(19u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT20 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00001000ul))
    {
        Exint_IrqHandler(20u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT21 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00002000ul))
    {
        Exint_IrqHandler(21u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT22 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00004000ul))
    {
        Exint_IrqHandler(22u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT23 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00008000ul))
    {
        Exint_IrqHandler(23u);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: DT0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DT0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: DT0 IRQ handler (IRQ#14) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_DT_AVAILABLE)
void DT_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ14MON;

    #if (PDL_INTERRUPT_ENABLE_DT0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        DtIrqHandler(0u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_DT0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        DtIrqHandler(1u);

    }
    #endif
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: MFS0 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS0 IRQ handler (IRQ#15) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_MFS0_RX_TX_AVAILABLE)
void MFS0_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ15MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS0_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS0_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS0_RX);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFS0_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS0_TX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS0_TX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS0_RX != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFS0_TX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN0, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs0].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: MFS1 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS1 IRQ handler (IRQ#16) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_MFS1_RX_TX_AVAILABLE)
void MFS1_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ16MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS1_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS1_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS1_RX);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFS1_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS1_TX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS1_TX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS1_RX != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFS1_TX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: MFS2 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS2 IRQ handler (IRQ#17) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_MFS2_RX_TX_AVAILABLE)
void MFS2_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ17MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS2_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS2_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS2_RX);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFS2_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS2_TX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS2_TX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS2_RX != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFS2_TX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN2, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs2].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: MFS3 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS3 IRQ handler (IRQ#18) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_MFS3_RX_TX_AVAILABLE)
void MFS3_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ18MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS3_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS3_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS3_RX);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFS3_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS3_TX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS3_TX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS3_RX != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFS3_TX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: MFS4 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS4 IRQ handler (IRQ#19) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_MFS4_RX_AVAILABLE)
void MFS4_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ19MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS4_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS4_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS4_RX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS4_RX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: MFS4 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS4 IRQ handler (IRQ#20) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_MFS4_TX_AVAILABLE)
void MFS4_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ20MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS4_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS4_TX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS4_TX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS4_TX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: MFS5 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS5 IRQ handler (IRQ#21) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_MFS5_RX_AVAILABLE)
void MFS5_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ21MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS5_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS5_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS5_RX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS5_RX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: MFS5 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS5 IRQ handler (IRQ#22) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_MFS5_TX_AVAILABLE)
void MFS5_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ22MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS5_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS5_TX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS5_TX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS5_TX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/************************* FM0P: PPG, RC0, ICC0, DSTC *************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_PPG == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_ICC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_DSTC == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: PPG, RC0, ICC0, DSTC IRQ handler (IRQ#23) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_PPG00_02_04_DSTC_SMCIF0_HDMICEC0_AVAILABLE)
void PPG00_02_04_DSTC_SMCIF0_HDMICEC0_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ23MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_PPG4)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_PPG4))
    {
        Dstc_PpgIrqHandler(DSTC_IRQ_NUMBER_PPG4);

    }
    #endif

#if (PDL_DSTC_ENABLE_PPG4 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_PPG == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000007ul))
    {
        Ppg_IrqHandler();

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_RC0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000100ul))
    {
        RcIrqHandler((stc_rcn_t*) &RC0, &(m_astcRcInstanceDataLut[RcInstanceIndexRc0].stcInternData));

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_ICC0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000200ul))
    {
        PDL_DummyHandler(8ul);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_DSTC == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000200ul))
    {
        PDL_DummyHandler(9ul);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************** FM0P: ICC1, RC1, RTC0, WC0, CLK ***********************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ICC1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RC1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RTC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_WC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_CLK == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: ICC1, RC1, RTC0, WC0, CLK IRQ handler (IRQ#24) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_TIM_SMCIF1_HDMICEC1_AVAILABLE)
void TIM_SMCIF1_HDMICEC1_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ24MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_WC0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_WC0))
    {
        Dstc_WcIrqHandler();

    }
    #endif

#if (PDL_DSTC_ENABLE_WC0 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_ICC1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000400ul))
    {
        PDL_DummyHandler(10ul);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_RC1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000200ul))
    {
        RcIrqHandler((stc_rcn_t*) &RC1, &(m_astcRcInstanceDataLut[RcInstanceIndexRc1].stcInternData));

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_RTC0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        Rtc_IrqHandler((stc_rtcn_t*)&RTC0, &(m_astcRtcInstanceDataLut[RtcInstanceIndexRtc0].stcInternData));

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_WC0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000010ul))
    {
        Wc_IrqHandler((stc_wcn_t*)&WC0);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_CLK == PDL_ON)
    if (0ul != (u32IrqMon & 0x0000000Ful))
    {
        Clk_IrqHandler();

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: ADC0 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ADC0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: ADC0 IRQ handler (IRQ#25) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_ADC0_AVAILABLE)
void ADC0_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_ADC0_PRIO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_ADC0_PRIO))
    {
        Dstc_AdcIrqHandler(DSTC_IRQ_NUMBER_ADC0_PRIO, DSTC_IRQ_NUMBER_ADC0_SCAN);

    }
    #endif

#if (PDL_DSTC_ENABLE_ADC0_PRIO != PDL_ON)

        AdcIrqHandler((volatile stc_adcn_t*)&ADC0, &(m_astcAdcInstanceDataLut[AdcInstanceIndexAdc0].stcInternData));


#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/************************ FM0P: USB0_HOST, USB0_DEVICE ************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_USB0_HOST == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_USB0_DEVICE == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: USB0_HOST, USB0_DEVICE IRQ handler (IRQ#26) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_USB0_H_F_AVAILABLE)
void USB0_H_F_IRQHandler(void)
{
    PDL_DummyHandler(11ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: LCD **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_LCD == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: LCD IRQ handler (IRQ#27) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_LCDC_AVAILABLE)
void LCDC_IRQHandler(void)
{
    PDL_DummyHandler(12ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************* FM0P: MFT0_FRT, MFT0_ICU, MFT0_OCU *********************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_FRT == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFT0_ICU == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFT0_OCU == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFT0_FRT, MFT0_ICU, MFT0_OCU IRQ handler (IRQ#28) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_MFT0_FRT_ICU_OCU_AVAILABLE)
void MFT0_FRT_ICU_OCU_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ28MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT0_PEAK)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT0_PEAK))
    {
        Dstc_MftFrtPeakIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT0_PEAK);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT1_PEAK)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT1_PEAK))
    {
        Dstc_MftFrtPeakIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT1_PEAK);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT2_PEAK)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT2_PEAK))
    {
        Dstc_MftFrtPeakIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT2_PEAK);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT0_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT0_ZERO))
    {
        Dstc_MftFrtPeakIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT0_ZERO);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT1_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT1_ZERO))
    {
        Dstc_MftFrtPeakIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT1_ZERO);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT2_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT2_ZERO))
    {
        Dstc_MftFrtPeakIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT2_ZERO);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_ICU0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_ICU0))
    {
        Dstc_MftIcuIrqHandler(DSTC_IRQ_NUMBER_MFT0_ICU0);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_ICU1)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_ICU1))
    {
        Dstc_MftIcuIrqHandler(DSTC_IRQ_NUMBER_MFT0_ICU1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_ICU2)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_ICU2))
    {
        Dstc_MftIcuIrqHandler(DSTC_IRQ_NUMBER_MFT0_ICU2);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_ICU3)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_ICU3))
    {
        Dstc_MftIcuIrqHandler(DSTC_IRQ_NUMBER_MFT0_ICU3);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_OCU0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_OCU0))
    {
        Dstc_MftOcuIrqHandler(DSTC_IRQ_NUMBER_MFT0_OCU0);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_OCU1)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_OCU1))
    {
        Dstc_MftOcuIrqHandler(DSTC_IRQ_NUMBER_MFT0_OCU1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_OCU2)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_OCU2))
    {
        Dstc_MftOcuIrqHandler(DSTC_IRQ_NUMBER_MFT0_OCU2);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_OCU3)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_OCU3))
    {
        Dstc_MftOcuIrqHandler(DSTC_IRQ_NUMBER_MFT0_OCU3);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_OCU4)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_OCU4))
    {
        Dstc_MftOcuIrqHandler(DSTC_IRQ_NUMBER_MFT0_OCU4);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_OCU5)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_OCU5))
    {
        Dstc_MftOcuIrqHandler(DSTC_IRQ_NUMBER_MFT0_OCU5);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFT0_FRT0_PEAK != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT1_PEAK != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT2_PEAK != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT0_ZERO != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT1_ZERO != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT2_ZERO != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU1 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU3 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU1 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU3 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU4 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU5 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFT0_FRT == PDL_ON)
    if (0ul != (u32IrqMon & 0x0000003Ful))
    {
        Mft_Frt_IrqHandler((volatile stc_mftn_frt_t*)&MFT0_FRT, &m_astcMftFrtInstanceDataLut[FrtInstanceIndexFrt0].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFT0_ICU == PDL_ON)
    if (0ul != (u32IrqMon & 0x000003C0ul))
    {
        Mft_Icu_IrqHandler((stc_mftn_icu_t*)&MFT0_ICU, &m_astcMftIcuInstanceDataLut[IcuInstanceIndexIcu0].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFT0_OCU == PDL_ON)
    if (0ul != (u32IrqMon & 0x0000FC00ul))
    {
        Mft_Ocu_IrqHandler((stc_mftn_ocu_t*)&MFT0_OCU, &m_astcMftOcuInstanceDataLut[OcuInstanceIndexOcu0].stcInternData);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/***************************** FM0P: USB0_DEVICE ******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_USB0_DEVICE == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: USB0_DEVICE IRQ handler (IRQ#29) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_USB0_F_AVAILABLE)
void USB0_F_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EP1_DRQ)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EP1_DRQ))
    {
        Dstc_Usb0_F_IrqHandler(DSTC_IRQ_NUMBER_EP1_DRQ);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EP2_DRQ)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EP2_DRQ))
    {
        Dstc_Usb0_F_IrqHandler(DSTC_IRQ_NUMBER_EP2_DRQ);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EP3_DRQ)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EP3_DRQ))
    {
        Dstc_Usb0_F_IrqHandler(DSTC_IRQ_NUMBER_EP3_DRQ);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EP4_DRQ)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EP4_DRQ))
    {
        Dstc_Usb0_F_IrqHandler(DSTC_IRQ_NUMBER_EP4_DRQ);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EP5_DRQ)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EP5_DRQ))
    {
        Dstc_Usb0_F_IrqHandler(DSTC_IRQ_NUMBER_EP5_DRQ);

    }
    #endif

#if (PDL_DSTC_ENABLE_EP1_DRQ != PDL_ON) && \
    (PDL_DSTC_ENABLE_EP2_DRQ != PDL_ON) && \
    (PDL_DSTC_ENABLE_EP3_DRQ != PDL_ON) && \
    (PDL_DSTC_ENABLE_EP4_DRQ != PDL_ON) && \
    (PDL_DSTC_ENABLE_EP5_DRQ != PDL_ON)

        PDL_DummyHandler(13ul);


#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/************ FM0P: BT0, BT1, BT2, BT3, BT4, BT5, BT6, BT7, FLASH *************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT3 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT4 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT5 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT6 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT7 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_FLASH == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: BT0, BT1, BT2, BT3, BT4, BT5, BT6, BT7, FLASH IRQ handler (IRQ#31) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_BT0_7_FLASHIF_AVAILABLE)
void BT0_7_FLASHIF_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ31MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_BT0_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT0_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT0_IRQ0, DSTC_IRQ_NUMBER_BT0_IRQ1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_BT1_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT1_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT1_IRQ0, DSTC_IRQ_NUMBER_BT1_IRQ1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_BT2_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT2_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT2_IRQ0, DSTC_IRQ_NUMBER_BT2_IRQ1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_BT3_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT3_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT3_IRQ0, DSTC_IRQ_NUMBER_BT3_IRQ1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_BT4_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT4_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT4_IRQ0, DSTC_IRQ_NUMBER_BT6_IRQ0);

    }
    #endif

#if (PDL_DSTC_ENABLE_BT0_IRQ0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_BT1_IRQ0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_BT2_IRQ0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_BT3_IRQ0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_BT4_IRQ0 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_BT0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000003ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT0, &m_astcBtInstanceDataLut[BtInstanceIndexBt0].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x0000000Cul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT1, &m_astcBtInstanceDataLut[BtInstanceIndexBt1].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT2 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000030ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT2, &m_astcBtInstanceDataLut[BtInstanceIndexBt2].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT3 == PDL_ON)
    if (0ul != (u32IrqMon & 0x000000C0ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT3, &m_astcBtInstanceDataLut[BtInstanceIndexBt3].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT4 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000300ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT4, &m_astcBtInstanceDataLut[BtInstanceIndexBt4].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT5 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000C00ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT5, &m_astcBtInstanceDataLut[BtInstanceIndexBt5].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT6 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00003000ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT6, &m_astcBtInstanceDataLut[BtInstanceIndexBt6].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT7 == PDL_ON)
    if (0ul != (u32IrqMon & 0x0000C000ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT7, &m_astcBtInstanceDataLut[BtInstanceIndexBt7].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_FLASH == PDL_ON)
    if (0ul != (u32IrqMon & 0x08000000ul))
    {
        PDL_DummyHandler(14ul);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: NMI, HWWDG ******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_NMI == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_HWWDG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: NMI, HWWDG IRQ handler (EXC#2) Type 2-b
 ******************************************************************************/
#if (1u == IRQ_NMI_AVAILABLE)
void NMI_Handler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->EXC02MON;

    #if (PDL_INTERRUPT_ENABLE_NMI == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_Nmi_IrqHandler();

    }
    #endif
    #if (PDL_INTERRUPT_ENABLE_HWWDG == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        HwwdgIrqHandler();

    }
    #endif
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


#endif // #ifdef __INTERRUPTS_FM0P_TYPE_2-B_C__

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
