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
 #ifdef __INTERRUPTS_FM4_TYPE_A_C__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/

#include "interrupts_fm4.h"

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

    // 0: IRQ003SEL, 1: IRQ004SEL, 2: IRQ005SEL, 3: IRQ006SEL, 4: IRQ007SEL, 
    // 5: IRQ008SEL, 6: IRQ009SEL, 7: IRQ010SEL, 8: EXTIF, 9: UPLL, 
    // 10: I2SPLL, 11: USB0_DEVICE, 12: USB0_HOST|USB0_DEVICE, 13: DSTC, 
    // 14: SD0, 15: FLASH, 

    while (1u)
    { }
}

/******************************************************************************/
/********************************** FM4: CSV **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CSV == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: CSV IRQ handler (IRQ#0) Type a
 ******************************************************************************/
#if (1u == IRQ_CSV_AVAILABLE)
void CSV_IRQHandler(void)
{
    Csv_IrqHandler();

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: SWWDG *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_SWWDG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: SWWDG IRQ handler (IRQ#1) Type a
 ******************************************************************************/
#if (1u == IRQ_SWDT_AVAILABLE)
void SWDT_IRQHandler(void)
{
    SwwdgIrqHandler();

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: LVD **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_LVD == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: LVD IRQ handler (IRQ#2) Type a
 ******************************************************************************/
#if (1u == IRQ_LVD_AVAILABLE)
void LVD_IRQHandler(void)
{
    Lvd_IrqHandler();

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: IRQ003SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ003SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: IRQ003SEL IRQ handler (IRQ#3) Type a
 ******************************************************************************/
#if (1u == IRQ_IRQ003SEL_AVAILABLE)
void IRQ003SEL_IRQHandler(void)
{
    PDL_DummyHandler(0ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: IRQ004SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ004SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: IRQ004SEL IRQ handler (IRQ#4) Type a
 ******************************************************************************/
#if (1u == IRQ_IRQ004SEL_AVAILABLE)
void IRQ004SEL_IRQHandler(void)
{
    PDL_DummyHandler(1ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: IRQ005SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ005SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: IRQ005SEL IRQ handler (IRQ#5) Type a
 ******************************************************************************/
#if (1u == IRQ_IRQ005SEL_AVAILABLE)
void IRQ005SEL_IRQHandler(void)
{
    PDL_DummyHandler(2ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: IRQ006SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ006SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: IRQ006SEL IRQ handler (IRQ#6) Type a
 ******************************************************************************/
#if (1u == IRQ_IRQ006SEL_AVAILABLE)
void IRQ006SEL_IRQHandler(void)
{
    PDL_DummyHandler(3ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: IRQ007SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ007SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: IRQ007SEL IRQ handler (IRQ#7) Type a
 ******************************************************************************/
#if (1u == IRQ_IRQ007SEL_AVAILABLE)
void IRQ007SEL_IRQHandler(void)
{
    PDL_DummyHandler(4ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: IRQ008SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ008SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: IRQ008SEL IRQ handler (IRQ#8) Type a
 ******************************************************************************/
#if (1u == IRQ_IRQ008SEL_AVAILABLE)
void IRQ008SEL_IRQHandler(void)
{
    PDL_DummyHandler(5ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: IRQ009SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ009SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: IRQ009SEL IRQ handler (IRQ#9) Type a
 ******************************************************************************/
#if (1u == IRQ_IRQ009SEL_AVAILABLE)
void IRQ009SEL_IRQHandler(void)
{
    PDL_DummyHandler(6ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: IRQ010SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ010SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: IRQ010SEL IRQ handler (IRQ#10) Type a
 ******************************************************************************/
#if (1u == IRQ_IRQ010SEL_AVAILABLE)
void IRQ010SEL_IRQHandler(void)
{
    PDL_DummyHandler(7ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT0 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT0 IRQ handler (IRQ#11) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT0_AVAILABLE)
void EXINT0_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT0))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT0);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT0 != PDL_ON)

        Exint_IrqHandler(0u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT1 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT1 IRQ handler (IRQ#12) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT1_AVAILABLE)
void EXINT1_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT1)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT1))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT1);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT1 != PDL_ON)

        Exint_IrqHandler(1u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT2 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT2 IRQ handler (IRQ#13) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT2_AVAILABLE)
void EXINT2_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT2)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT2))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT2);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT2 != PDL_ON)

        Exint_IrqHandler(2u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT3 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT3 IRQ handler (IRQ#14) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT3_AVAILABLE)
void EXINT3_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT3)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT3))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT3);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT3 != PDL_ON)

        Exint_IrqHandler(3u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT4 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT4 IRQ handler (IRQ#15) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT4_AVAILABLE)
void EXINT4_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT4)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT4))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT4);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT4 != PDL_ON)

        Exint_IrqHandler(4u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT5 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT5 IRQ handler (IRQ#16) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT5_AVAILABLE)
void EXINT5_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT5)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT5))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT5);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT5 != PDL_ON)

        Exint_IrqHandler(5u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT6 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT6 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT6 IRQ handler (IRQ#17) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT6_AVAILABLE)
void EXINT6_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT6)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT6))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT6);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT6 != PDL_ON)

        Exint_IrqHandler(6u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT7 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT7 IRQ handler (IRQ#18) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT7_AVAILABLE)
void EXINT7_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT7)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT7))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT7);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT7 != PDL_ON)

        Exint_IrqHandler(7u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: QPRC0 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_QPRC0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: QPRC0 IRQ handler (IRQ#19) Type a
 ******************************************************************************/
#if (1u == IRQ_QPRC0_AVAILABLE)
void QPRC0_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_COUNT_INVERSION)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_COUNT_INVERSION))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_COUNT_INVERSION);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_OUT_OF_RANGE)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_OUT_OF_RANGE))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_OUT_OF_RANGE);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_PC_MATCH)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_PC_MATCH_RC_MATCH)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH_RC_MATCH))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH_RC_MATCH);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_PC_RC_MATCH)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_PC_RC_MATCH))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_PC_RC_MATCH);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_UFL_OFL_Z)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_UFL_OFL_Z))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_UFL_OFL_Z);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_QPRC0_COUNT_INVERSION != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_OUT_OF_RANGE != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_PC_MATCH != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_PC_MATCH_RC_MATCH != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_PC_RC_MATCH != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_UFL_OFL_Z != PDL_ON)

        Qprc_IrqHandler((stc_qprcn_t*)&QPRC0, &m_astcQprcInstanceDataLut[QprcInstanceIndexQprc0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: QPRC1 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_QPRC1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: QPRC1 IRQ handler (IRQ#20) Type a
 ******************************************************************************/
#if (1u == IRQ_QPRC1_AVAILABLE)
void QPRC1_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_COUNT_INVERSION)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_COUNT_INVERSION))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_COUNT_INVERSION);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_OUT_OF_RANGE)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_OUT_OF_RANGE))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_OUT_OF_RANGE);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_PC_MATCH)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_PC_MATCH_RC_MATCH)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH_RC_MATCH))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH_RC_MATCH);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_PC_RC_MATCH)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_PC_RC_MATCH))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_PC_RC_MATCH);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_UFL_OFL_Z)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_UFL_OFL_Z))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_UFL_OFL_Z);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_QPRC0_COUNT_INVERSION != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_OUT_OF_RANGE != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_PC_MATCH != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_PC_MATCH_RC_MATCH != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_PC_RC_MATCH != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_UFL_OFL_Z != PDL_ON)

        Qprc_IrqHandler((stc_qprcn_t*)&QPRC1, &m_astcQprcInstanceDataLut[QprcInstanceIndexQprc1].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT0_WFG ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_WFG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT0_WFG IRQ handler (IRQ#21) Type a
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

        Mft_Wfg_IrqHandler((stc_mftn_wfg_t*)&MFT0_WFG, &m_astcMftWfgInstanceDataLut[WfgInstanceIndexWfg0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT1_WFG ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT1_WFG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT1_WFG IRQ handler (IRQ#22) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT1_WFG_DTIF_AVAILABLE)
void MFT1_WFG_DTIF_IRQHandler(void)
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

        Mft_Wfg_IrqHandler((stc_mftn_wfg_t*)&MFT0_WFG, &m_astcMftWfgInstanceDataLut[WfgInstanceIndexWfg0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT2_WFG ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT2_WFG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT2_WFG IRQ handler (IRQ#23) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT2_WFG_DTIF_AVAILABLE)
void MFT2_WFG_DTIF_IRQHandler(void)
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

        Mft_Wfg_IrqHandler((stc_mftn_wfg_t*)&MFT0_WFG, &m_astcMftWfgInstanceDataLut[WfgInstanceIndexWfg0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT0_FRT ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_FRT == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT0_FRT IRQ handler (IRQ#24) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT0_FRT_PEAK_AVAILABLE)
void MFT0_FRT_PEAK_IRQHandler(void)
{
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

#if (PDL_DSTC_ENABLE_MFT0_FRT0_PEAK != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT1_PEAK != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT2_PEAK != PDL_ON)

        Mft_Frt_IrqHandler((stc_mftn_frt_t*)&MFT0_FRT, &m_astcMftFrtInstanceDataLut[FrtInstanceIndexFrt0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT0_FRT ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_FRT == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT0_FRT IRQ handler (IRQ#25) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT0_FRT_ZERO_AVAILABLE)
void MFT0_FRT_ZERO_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT0_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT0_ZERO))
    {
        Dstc_MftFrtZeroIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT0_ZERO);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT1_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT1_ZERO))
    {
        Dstc_MftFrtZeroIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT1_ZERO);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT2_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT2_ZERO))
    {
        Dstc_MftFrtZeroIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT2_ZERO);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFT0_FRT0_ZERO != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT1_ZERO != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT2_ZERO != PDL_ON)

        Mft_Frt_IrqHandler((stc_mftn_frt_t*)&MFT0_FRT, &m_astcMftFrtInstanceDataLut[FrtInstanceIndexFrt0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT0_ICU ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_ICU == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT0_ICU IRQ handler (IRQ#26) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT0_ICU_AVAILABLE)
void MFT0_ICU_IRQHandler(void)
{
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

#if (PDL_DSTC_ENABLE_MFT0_ICU0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU1 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU3 != PDL_ON)

        Mft_Icu_IrqHandler((stc_mftn_icu_t*)&MFT0_ICU, &m_astcMftIcuInstanceDataLut[IcuInstanceIndexIcu0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT0_OCU ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_OCU == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT0_OCU IRQ handler (IRQ#27) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT0_OCU_AVAILABLE)
void MFT0_OCU_IRQHandler(void)
{
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

#if (PDL_DSTC_ENABLE_MFT0_OCU0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU1 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU3 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU4 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU5 != PDL_ON)

        Mft_Ocu_IrqHandler((stc_mftn_ocu_t*)&MFT0_OCU, &m_astcMftOcuInstanceDataLut[OcuInstanceIndexOcu0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT1_FRT ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT1_FRT == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT1_FRT IRQ handler (IRQ#28) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT1_FRT_PEAK_AVAILABLE)
void MFT1_FRT_PEAK_IRQHandler(void)
{
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

#if (PDL_DSTC_ENABLE_MFT0_FRT0_PEAK != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT1_PEAK != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT2_PEAK != PDL_ON)

        Mft_Frt_IrqHandler((stc_mftn_frt_t*)&MFT0_FRT, &m_astcMftFrtInstanceDataLut[FrtInstanceIndexFrt0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT1_FRT ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT1_FRT == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT1_FRT IRQ handler (IRQ#29) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT1_FRT_ZERO_AVAILABLE)
void MFT1_FRT_ZERO_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT0_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT0_ZERO))
    {
        Dstc_MftFrtZeroIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT0_ZERO);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT1_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT1_ZERO))
    {
        Dstc_MftFrtZeroIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT1_ZERO);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT2_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT2_ZERO))
    {
        Dstc_MftFrtZeroIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT2_ZERO);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFT0_FRT0_ZERO != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT1_ZERO != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT2_ZERO != PDL_ON)

        Mft_Frt_IrqHandler((stc_mftn_frt_t*)&MFT0_FRT, &m_astcMftFrtInstanceDataLut[FrtInstanceIndexFrt0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT1_ICU ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT1_ICU == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT1_ICU IRQ handler (IRQ#30) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT1_ICU_AVAILABLE)
void MFT1_ICU_IRQHandler(void)
{
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

#if (PDL_DSTC_ENABLE_MFT0_ICU0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU1 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU3 != PDL_ON)

        Mft_Icu_IrqHandler((stc_mftn_icu_t*)&MFT0_ICU, &m_astcMftIcuInstanceDataLut[IcuInstanceIndexIcu0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT1_OCU ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT1_OCU == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT1_OCU IRQ handler (IRQ#31) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT1_OCU_AVAILABLE)
void MFT1_OCU_IRQHandler(void)
{
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

#if (PDL_DSTC_ENABLE_MFT0_OCU0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU1 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU3 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU4 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU5 != PDL_ON)

        Mft_Ocu_IrqHandler((stc_mftn_ocu_t*)&MFT0_OCU, &m_astcMftOcuInstanceDataLut[OcuInstanceIndexOcu0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT2_FRT ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT2_FRT == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT2_FRT IRQ handler (IRQ#32) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT2_FRT_PEAK_AVAILABLE)
void MFT2_FRT_PEAK_IRQHandler(void)
{
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

#if (PDL_DSTC_ENABLE_MFT0_FRT0_PEAK != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT1_PEAK != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT2_PEAK != PDL_ON)

        Mft_Frt_IrqHandler((stc_mftn_frt_t*)&MFT0_FRT, &m_astcMftFrtInstanceDataLut[FrtInstanceIndexFrt0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT2_FRT ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT2_FRT == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT2_FRT IRQ handler (IRQ#33) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT2_FRT_ZERO_AVAILABLE)
void MFT2_FRT_ZERO_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT0_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT0_ZERO))
    {
        Dstc_MftFrtZeroIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT0_ZERO);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT1_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT1_ZERO))
    {
        Dstc_MftFrtZeroIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT1_ZERO);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFT0_FRT2_ZERO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFT0_FRT2_ZERO))
    {
        Dstc_MftFrtZeroIrqHandler(DSTC_IRQ_NUMBER_MFT0_FRT2_ZERO);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFT0_FRT0_ZERO != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT1_ZERO != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_FRT2_ZERO != PDL_ON)

        Mft_Frt_IrqHandler((stc_mftn_frt_t*)&MFT0_FRT, &m_astcMftFrtInstanceDataLut[FrtInstanceIndexFrt0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT2_ICU ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT2_ICU == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT2_ICU IRQ handler (IRQ#34) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT2_ICU_AVAILABLE)
void MFT2_ICU_IRQHandler(void)
{
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

#if (PDL_DSTC_ENABLE_MFT0_ICU0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU1 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_ICU3 != PDL_ON)

        Mft_Icu_IrqHandler((stc_mftn_icu_t*)&MFT0_ICU, &m_astcMftIcuInstanceDataLut[IcuInstanceIndexIcu0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM4: MFT2_OCU ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT2_OCU == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFT2_OCU IRQ handler (IRQ#35) Type a
 ******************************************************************************/
#if (1u == IRQ_MFT2_OCU_AVAILABLE)
void MFT2_OCU_IRQHandler(void)
{
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

#if (PDL_DSTC_ENABLE_MFT0_OCU0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU1 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU3 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU4 != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFT0_OCU5 != PDL_ON)

        Mft_Ocu_IrqHandler((stc_mftn_ocu_t*)&MFT0_OCU, &m_astcMftOcuInstanceDataLut[OcuInstanceIndexOcu0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: PPG **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_PPG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: PPG IRQ handler (IRQ#36) Type a
 ******************************************************************************/
#if (1u == IRQ_PPG00_02_04_AVAILABLE)
void PPG00_02_04_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_PPG0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_PPG0))
    {
        Dstc_PpgIrqHandler(DSTC_IRQ_NUMBER_PPG0);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_PPG2)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_PPG2))
    {
        Dstc_PpgIrqHandler(DSTC_IRQ_NUMBER_PPG2);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_PPG4)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_PPG4))
    {
        Dstc_PpgIrqHandler(DSTC_IRQ_NUMBER_PPG4);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_PPG0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_PPG2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_PPG4 != PDL_ON)

        Ppg_IrqHandler();
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: PPG **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_PPG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: PPG IRQ handler (IRQ#37) Type a
 ******************************************************************************/
#if (1u == IRQ_PPG08_10_12_AVAILABLE)
void PPG08_10_12_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_PPG8)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_PPG8))
    {
        Dstc_PpgIrqHandler(DSTC_IRQ_NUMBER_PPG8);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_PPG10)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_PPG10))
    {
        Dstc_PpgIrqHandler(DSTC_IRQ_NUMBER_PPG10);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_PPG12)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_PPG12))
    {
        Dstc_PpgIrqHandler(DSTC_IRQ_NUMBER_PPG12);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_PPG8 != PDL_ON) && \
    (PDL_DSTC_ENABLE_PPG10 != PDL_ON) && \
    (PDL_DSTC_ENABLE_PPG12 != PDL_ON)

        Ppg_IrqHandler();
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: PPG **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_PPG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: PPG IRQ handler (IRQ#38) Type a
 ******************************************************************************/
#if (1u == IRQ_PPG16_18_20_AVAILABLE)
void PPG16_18_20_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_PPG16)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_PPG16))
    {
        Dstc_PpgIrqHandler(DSTC_IRQ_NUMBER_PPG16);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_PPG18)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_PPG18))
    {
        Dstc_PpgIrqHandler(DSTC_IRQ_NUMBER_PPG18);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_PPG20)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_PPG20))
    {
        Dstc_PpgIrqHandler(DSTC_IRQ_NUMBER_PPG20);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_PPG16 != PDL_ON) && \
    (PDL_DSTC_ENABLE_PPG18 != PDL_ON) && \
    (PDL_DSTC_ENABLE_PPG20 != PDL_ON)

        Ppg_IrqHandler();
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: BT0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: BT0 IRQ handler (IRQ#39) Type a
 ******************************************************************************/
#if (1u == IRQ_BT0_AVAILABLE)
void BT0_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_BT0_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT0_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT0_IRQ0, DSTC_IRQ_NUMBER_BT0_IRQ1);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_BT0_IRQ0 != PDL_ON)

        Bt_IrqHandler((stc_btn_t*)&BT0, &m_astcBtInstanceDataLut[BtInstanceIndexBt0].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: BT1 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: BT1 IRQ handler (IRQ#40) Type a
 ******************************************************************************/
#if (1u == IRQ_BT1_AVAILABLE)
void BT1_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_BT1_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT1_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT1_IRQ0, DSTC_IRQ_NUMBER_BT1_IRQ1);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_BT1_IRQ0 != PDL_ON)

        Bt_IrqHandler((stc_btn_t*)&BT1, &m_astcBtInstanceDataLut[BtInstanceIndexBt1].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: BT2 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: BT2 IRQ handler (IRQ#41) Type a
 ******************************************************************************/
#if (1u == IRQ_BT2_AVAILABLE)
void BT2_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_BT2_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT2_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT2_IRQ0, DSTC_IRQ_NUMBER_BT2_IRQ1);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_BT2_IRQ0 != PDL_ON)

        Bt_IrqHandler((stc_btn_t*)&BT2, &m_astcBtInstanceDataLut[BtInstanceIndexBt2].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: BT3 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: BT3 IRQ handler (IRQ#42) Type a
 ******************************************************************************/
#if (1u == IRQ_BT3_AVAILABLE)
void BT3_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_BT3_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT3_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT3_IRQ0, DSTC_IRQ_NUMBER_BT3_IRQ1);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_BT3_IRQ0 != PDL_ON)

        Bt_IrqHandler((stc_btn_t*)&BT3, &m_astcBtInstanceDataLut[BtInstanceIndexBt3].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: BT4 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: BT4 IRQ handler (IRQ#43) Type a
 ******************************************************************************/
#if (1u == IRQ_BT4_AVAILABLE)
void BT4_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_BT4_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT4_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT4_IRQ0, DSTC_IRQ_NUMBER_BT4_IRQ1);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_BT4_IRQ0 != PDL_ON)

        Bt_IrqHandler((stc_btn_t*)&BT4, &m_astcBtInstanceDataLut[BtInstanceIndexBt4].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: BT5 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: BT5 IRQ handler (IRQ#44) Type a
 ******************************************************************************/
#if (1u == IRQ_BT5_AVAILABLE)
void BT5_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_BT5_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT5_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT5_IRQ0, DSTC_IRQ_NUMBER_BT5_IRQ1);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_BT5_IRQ0 != PDL_ON)

        Bt_IrqHandler((stc_btn_t*)&BT5, &m_astcBtInstanceDataLut[BtInstanceIndexBt5].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: BT6 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT6 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: BT6 IRQ handler (IRQ#45) Type a
 ******************************************************************************/
#if (1u == IRQ_BT6_AVAILABLE)
void BT6_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_BT6_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT6_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT6_IRQ0, DSTC_IRQ_NUMBER_BT6_IRQ1);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_BT6_IRQ0 != PDL_ON)

        Bt_IrqHandler((stc_btn_t*)&BT6, &m_astcBtInstanceDataLut[BtInstanceIndexBt6].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: BT7 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: BT7 IRQ handler (IRQ#46) Type a
 ******************************************************************************/
#if (1u == IRQ_BT7_AVAILABLE)
void BT7_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_BT7_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT7_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT7_IRQ0, DSTC_IRQ_NUMBER_BT7_IRQ1);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_BT7_IRQ0 != PDL_ON)

        Bt_IrqHandler((stc_btn_t*)&BT7, &m_astcBtInstanceDataLut[BtInstanceIndexBt7].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: DT0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DT0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DT0 IRQ handler (IRQ#47) Type a
 ******************************************************************************/
#if (1u == IRQ_DT_AVAILABLE)
void DT_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ047MON;

    #if (PDL_INTERRUPT_ENABLE_DT0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        DtIrqHandler(DtChannel0);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_DT0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        DtIrqHandler(DtChannel1);
    
    }
    #endif
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: WC0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_WC0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: WC0 IRQ handler (IRQ#48) Type a
 ******************************************************************************/
#if (1u == IRQ_WC_AVAILABLE)
void WC_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_WC)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_WC))
    {
        Dstc_WcIrqHandler();
    
    }
    #endif

#if (PDL_DSTC_ENABLE_WC != PDL_ON)

        Wc_IrqHandler((stc_wcn_t*)&WC0);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: EXTIF *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXTIF == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXTIF IRQ handler (IRQ#49) Type a
 ******************************************************************************/
#if (1u == IRQ_EXTBUS_ERR_AVAILABLE)
void EXTBUS_ERR_IRQHandler(void)
{
    PDL_DummyHandler(8ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: RTC0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RTC0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: RTC0 IRQ handler (IRQ#50) Type a
 ******************************************************************************/
#if (1u == IRQ_RTC_AVAILABLE)
void RTC_IRQHandler(void)
{
    Rtc_IrqHandler((stc_rtcn_t*)&RTC0, &(m_astcRtcInstanceDataLut[RtcInstanceIndexRtc0].stcInternData));

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT8 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT8 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT8 IRQ handler (IRQ#51) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT8_AVAILABLE)
void EXINT8_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT8)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT8))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT8);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT8 != PDL_ON)

        Exint_IrqHandler(8u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT9 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT9 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT9 IRQ handler (IRQ#52) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT9_AVAILABLE)
void EXINT9_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT9)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT9))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT9);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT9 != PDL_ON)

        Exint_IrqHandler(9u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT10 ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT10 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT10 IRQ handler (IRQ#53) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT10_AVAILABLE)
void EXINT10_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT10)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT10))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT10);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT10 != PDL_ON)

        Exint_IrqHandler(10u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT11 ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT11 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT11 IRQ handler (IRQ#54) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT11_AVAILABLE)
void EXINT11_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT11)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT11))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT11);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT11 != PDL_ON)

        Exint_IrqHandler(11u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT12 ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT12 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT12 IRQ handler (IRQ#55) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT12_AVAILABLE)
void EXINT12_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT12)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT12))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT12);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT12 != PDL_ON)

        Exint_IrqHandler(12u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT13 ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT13 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT13 IRQ handler (IRQ#56) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT13_AVAILABLE)
void EXINT13_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT13)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT13))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT13);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT13 != PDL_ON)

        Exint_IrqHandler(13u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT14 ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT14 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT14 IRQ handler (IRQ#57) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT14_AVAILABLE)
void EXINT14_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT14)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT14))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT14);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT14 != PDL_ON)

        Exint_IrqHandler(14u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM4: EXINT15 ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT15 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT15 IRQ handler (IRQ#58) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT15_AVAILABLE)
void EXINT15_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT15)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT15))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT15);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT15 != PDL_ON)

        Exint_IrqHandler(15u);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/*************************** FM4: CLK, UPLL, I2SPLL ***************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CLK == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_UPLL == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_I2SPLL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: CLK, UPLL, I2SPLL IRQ handler (IRQ#59) Type a
 ******************************************************************************/
#if (1u == IRQ_TIM_AVAILABLE)
void TIM_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ059MON;

    #if (PDL_INTERRUPT_ENABLE_CLK == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000007ul))
    {
        Clk_IrqHandler();
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_UPLL == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000008ul))
    {
        PDL_DummyHandler(9ul);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_I2SPLL == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000010ul))
    {
        PDL_DummyHandler(10ul);
    
    }
    #endif
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: MFS0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS0 IRQ handler (IRQ#60) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS0_RX_AVAILABLE)
void MFS0_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ060MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS0_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS0_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS0_RX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS0_RX != PDL_ON)

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
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: MFS0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS0 IRQ handler (IRQ#61) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS0_TX_AVAILABLE)
void MFS0_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ061MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS0_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS0_TX))
    {
        Dstc_MfsTxIrqHandler(DSTC_IRQ_NUMBER_MFS0_TX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS0_TX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
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
    if (0ul != (u32IrqMon & 0x00000002ul))
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
/********************************* FM4: MFS1 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS1 IRQ handler (IRQ#62) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS1_RX_AVAILABLE)
void MFS1_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ062MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS1_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS1_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS1_RX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS1_RX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));
    
                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));
    
                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));
    
                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN1, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs1].stcInternData));
    
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
/********************************* FM4: MFS1 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS1 IRQ handler (IRQ#63) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS1_TX_AVAILABLE)
void MFS1_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ063MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS1_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS1_TX))
    {
        Dstc_MfsTxIrqHandler(DSTC_IRQ_NUMBER_MFS1_TX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS1_TX != PDL_ON)

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
/********************************* FM4: MFS2 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS2 IRQ handler (IRQ#64) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS2_RX_AVAILABLE)
void MFS2_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ064MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS2_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS2_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS2_RX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS2_RX != PDL_ON)

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
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: MFS2 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS2 IRQ handler (IRQ#65) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS2_TX_AVAILABLE)
void MFS2_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ065MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS2_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS2_TX))
    {
        Dstc_MfsTxIrqHandler(DSTC_IRQ_NUMBER_MFS2_TX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS2_TX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
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
    if (0ul != (u32IrqMon & 0x00000002ul))
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
/********************************* FM4: MFS3 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS3 IRQ handler (IRQ#66) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS3_RX_AVAILABLE)
void MFS3_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ066MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS3_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS3_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS3_RX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS3_RX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));
    
                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));
    
                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));
    
                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN3, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs3].stcInternData));
    
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
/********************************* FM4: MFS3 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS3 IRQ handler (IRQ#67) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS3_TX_AVAILABLE)
void MFS3_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ067MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS3_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS3_TX))
    {
        Dstc_MfsTxIrqHandler(DSTC_IRQ_NUMBER_MFS3_TX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS3_TX != PDL_ON)

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
/********************************* FM4: MFS4 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS4 IRQ handler (IRQ#68) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS4_RX_AVAILABLE)
void MFS4_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ068MON;

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
/********************************* FM4: MFS4 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS4 IRQ handler (IRQ#69) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS4_TX_AVAILABLE)
void MFS4_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ069MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS4_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS4_TX))
    {
        Dstc_MfsTxIrqHandler(DSTC_IRQ_NUMBER_MFS4_TX);
    
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
/********************************* FM4: MFS5 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS5 IRQ handler (IRQ#70) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS5_RX_AVAILABLE)
void MFS5_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ070MON;

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
/********************************* FM4: MFS5 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS5 IRQ handler (IRQ#71) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS5_TX_AVAILABLE)
void MFS5_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ071MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS5_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS5_TX))
    {
        Dstc_MfsTxIrqHandler(DSTC_IRQ_NUMBER_MFS5_TX);
    
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
/********************************* FM4: MFS6 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS6 IRQ handler (IRQ#72) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS6_RX_AVAILABLE)
void MFS6_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ072MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS6_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS6_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS6_RX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS6_RX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON)
    if (0ul != (u32IrqMon & 0x000000012ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
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
/********************************* FM4: MFS6 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS6 IRQ handler (IRQ#73) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS6_TX_AVAILABLE)
void MFS6_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ073MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS6_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS6_TX))
    {
        Dstc_MfsTxIrqHandler(DSTC_IRQ_NUMBER_MFS6_TX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS6_TX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }
    
                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN6, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs6].stcInternData));
    
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
/********************************* FM4: MFS7 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS7 IRQ handler (IRQ#74) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS7_RX_AVAILABLE)
void MFS7_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ074MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS7_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS7_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS7_RX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS7_RX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS7 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
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
/********************************* FM4: MFS7 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: MFS7 IRQ handler (IRQ#75) Type a
 ******************************************************************************/
#if (1u == IRQ_MFS7_TX_AVAILABLE)
void MFS7_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ075MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS7_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS7_TX))
    {
        Dstc_MfsTxIrqHandler(DSTC_IRQ_NUMBER_MFS7_TX);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_MFS7_TX != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_MFS7 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS7 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }
    
                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN7, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs7].stcInternData));
    
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
/********************************* FM4: ADC0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ADC0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: ADC0 IRQ handler (IRQ#76) Type a
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

        AdcIrqHandler((stc_adcn_t*)&ADC0, &(m_astcAdcInstanceDataLut[AdcInstanceIndexAdc0].stcInternData));
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: ADC1 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ADC1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: ADC1 IRQ handler (IRQ#77) Type a
 ******************************************************************************/
#if (1u == IRQ_ADC1_AVAILABLE)
void ADC1_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_ADC1_PRIO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_ADC1_PRIO))
    {
        Dstc_AdcIrqHandler(DSTC_IRQ_NUMBER_ADC1_PRIO, DSTC_IRQ_NUMBER_ADC1_SCAN);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_ADC1_PRIO != PDL_ON)

        AdcIrqHandler((stc_adcn_t*)&ADC1, &(m_astcAdcInstanceDataLut[AdcInstanceIndexAdc1].stcInternData));
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM4: USB0_DEVICE ******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_USB0_DEVICE == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: USB0_DEVICE IRQ handler (IRQ#78) Type a
 ******************************************************************************/
#if (1u == IRQ_USB0_F_AVAILABLE)
void USB0_F_IRQHandler(void)
{
    PDL_DummyHandler(11ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/************************ FM4: USB0_HOST, USB0_DEVICE *************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_USB0_HOST == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_USB0_DEVICE == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: USB0_HOST, USB0_DEVICE IRQ handler (IRQ#79) Type a
 ******************************************************************************/
#if (1u == IRQ_USB0_H_F_AVAILABLE)
void USB0_H_F_IRQHandler(void)
{
    PDL_DummyHandler(12ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: CAN0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CAN0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: CAN0 IRQ handler (IRQ#80) Type a
 ******************************************************************************/
#if (1u == IRQ_CAN0_AVAILABLE)
void CAN0_IRQHandler(void)
{
    CanIrqHandler((stc_cann_t*) &CAN0, &(m_astcCanInstanceDataLut[CanInstanceIndexCan0].stcInternData));

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: CAN1 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CAN1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: CAN1 IRQ handler (IRQ#81) Type a
 ******************************************************************************/
#if (1u == IRQ_CAN1_AVAILABLE)
void CAN1_IRQHandler(void)
{
    CanIrqHandler((stc_cann_t*) &CAN1, &(m_astcCanInstanceDataLut[CanInstanceIndexCan1].stcInternData));

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: DMA0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DMA0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DMA0 IRQ handler (IRQ#83) Type a
 ******************************************************************************/
#if (1u == IRQ_DMAC0_AVAILABLE)
void DMAC0_IRQHandler(void)
{
    DmaIrqHandler(0u);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: DMA1 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DMA1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DMA1 IRQ handler (IRQ#84) Type a
 ******************************************************************************/
#if (1u == IRQ_DMAC1_AVAILABLE)
void DMAC1_IRQHandler(void)
{
    DmaIrqHandler(1u);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: DMA2 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DMA2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DMA2 IRQ handler (IRQ#85) Type a
 ******************************************************************************/
#if (1u == IRQ_DMAC2_AVAILABLE)
void DMAC2_IRQHandler(void)
{
    DmaIrqHandler(2u);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: DMA3 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DMA3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DMA3 IRQ handler (IRQ#86) Type a
 ******************************************************************************/
#if (1u == IRQ_DMAC3_AVAILABLE)
void DMAC3_IRQHandler(void)
{
    DmaIrqHandler(3u);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: DMA4 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DMA4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DMA4 IRQ handler (IRQ#87) Type a
 ******************************************************************************/
#if (1u == IRQ_DMAC4_AVAILABLE)
void DMAC4_IRQHandler(void)
{
    DmaIrqHandler(4u);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: DMA5 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DMA5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DMA5 IRQ handler (IRQ#88) Type a
 ******************************************************************************/
#if (1u == IRQ_DMAC5_AVAILABLE)
void DMAC5_IRQHandler(void)
{
    DmaIrqHandler(5u);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: DMA6 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DMA6 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DMA6 IRQ handler (IRQ#89) Type a
 ******************************************************************************/
#if (1u == IRQ_DMAC6_AVAILABLE)
void DMAC6_IRQHandler(void)
{
    DmaIrqHandler(6u);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: DMA7 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DMA7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DMA7 IRQ handler (IRQ#90) Type a
 ******************************************************************************/
#if (1u == IRQ_DMAC7_AVAILABLE)
void DMAC7_IRQHandler(void)
{
    DmaIrqHandler(7u);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: DSTC **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DSTC == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DSTC IRQ handler (IRQ#91) Type a
 ******************************************************************************/
#if (1u == IRQ_DSTC_AVAILABLE)
void DSTC_IRQHandler(void)
{
    PDL_DummyHandler(13ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************** FM4: EXINT16, EXINT17, EXINT18, EXINT19 *******************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT16 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT17 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT18 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT19 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT16, EXINT17, EXINT18, EXINT19 IRQ handler (IRQ#92) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT16_19_AVAILABLE)
void EXINT16_19_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ092MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT16)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT16))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT16);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT17)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT17))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT17);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT18)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT18))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT18);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT19)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT19))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT19);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT16 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT17 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT18 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT19 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_EXINT16 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(16u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT17 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(17u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT18 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        Exint_IrqHandler(18u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT19 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000008ul))
    {
        Exint_IrqHandler(19u);
    
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************** FM4: EXINT20, EXINT21, EXINT22, EXINT23 *******************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT20 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT21 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT22 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT23 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT20, EXINT21, EXINT22, EXINT23 IRQ handler (IRQ#93) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT20_23_AVAILABLE)
void EXINT20_23_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ093MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT20)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT20))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT20);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT21)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT21))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT21);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT22)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT22))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT22);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT23)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT23))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT23);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT20 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT21 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT22 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT23 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_EXINT20 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(20u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT21 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(21u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT22 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        Exint_IrqHandler(22u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT23 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000008ul))
    {
        Exint_IrqHandler(24u);
    
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************** FM4: EXINT24, EXINT25, EXINT26, EXINT27 *******************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT24 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT25 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT26 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT27 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT24, EXINT25, EXINT26, EXINT27 IRQ handler (IRQ#94) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT24_27_AVAILABLE)
void EXINT24_27_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ094MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT24)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT24))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT24);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT25)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT25))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT25);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT26)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT26))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT26);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT27)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT27))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT27);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT24 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT25 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT26 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT27 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_EXINT24 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(24u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT25 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(25u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT26 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        Exint_IrqHandler(26u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT27 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000008ul))
    {
        Exint_IrqHandler(27u);
    
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************** FM4: EXINT28, EXINT29, EXINT30, EXINT31 *******************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT28 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT29 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT30 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT31 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: EXINT28, EXINT29, EXINT30, EXINT31 IRQ handler (IRQ#95) Type a
 ******************************************************************************/
#if (1u == IRQ_EXINT28_31_AVAILABLE)
void EXINT28_31_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ095MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT28)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT28))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT28);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT29)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT29))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT29);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT30)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT30))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT30);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT31)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXINT31))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXINT31);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT28 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT29 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT30 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT31 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_EXINT28 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(28u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT29 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(29u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT30 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        Exint_IrqHandler(30u);
    
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT31 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000008ul))
    {
        Exint_IrqHandler(31u);
    
    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: QPRC2 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_QPRC2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: QPRC2 IRQ handler (IRQ#96) Type a
 ******************************************************************************/
#if (1u == IRQ_QPRC2_AVAILABLE)
void QPRC2_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_COUNT_INVERSION)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_COUNT_INVERSION))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_COUNT_INVERSION);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_OUT_OF_RANGE)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_OUT_OF_RANGE))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_OUT_OF_RANGE);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_PC_MATCH)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_PC_MATCH_RC_MATCH)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH_RC_MATCH))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_PC_MATCH_RC_MATCH);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_PC_RC_MATCH)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_PC_RC_MATCH))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_PC_RC_MATCH);
    
    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_QPRC0_UFL_OFL_Z)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_QPRC0_UFL_OFL_Z))
    {
        Dstc_QprcIrqHandler(DSTC_IRQ_NUMBER_QPRC0_UFL_OFL_Z);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_QPRC0_COUNT_INVERSION != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_OUT_OF_RANGE != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_PC_MATCH != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_PC_MATCH_RC_MATCH != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_PC_RC_MATCH != PDL_ON) && \
    (PDL_DSTC_ENABLE_QPRC0_UFL_OFL_Z != PDL_ON)

        Qprc_IrqHandler((stc_qprcn_t*)&QPRC2, &m_astcQprcInstanceDataLut[QprcInstanceIndexQprc2].stcInternData);
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: ADC2 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ADC2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: ADC2 IRQ handler (IRQ#111) Type a
 ******************************************************************************/
#if (1u == IRQ_ADC2_AVAILABLE)
void ADC2_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_ADC2_PRIO)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_ADC2_PRIO))
    {
        Dstc_AdcIrqHandler(DSTC_IRQ_NUMBER_ADC2_PRIO, DSTC_IRQ_NUMBER_ADC2_SCAN);
    
    }
    #endif

#if (PDL_DSTC_ENABLE_ADC2_PRIO != PDL_ON)

        AdcIrqHandler((stc_adcn_t*)&ADC2, &(m_astcAdcInstanceDataLut[AdcInstanceIndexAdc2].stcInternData));
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/**************************** FM4: DSTC_HWINT_NEW *****************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DSTC_HWINT_NEW == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: DSTC_HWINT_NEW IRQ handler (IRQ#112) Type a
 ******************************************************************************/
#if (1u == IRQ_DSTC_HWINT_AVAILABLE)
void DSTC_HWINT_IRQHandler(void)
{
    Dstc_IrqHandler();

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM4: SD0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_SD0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: SD0 IRQ handler (IRQ#118) Type a
 ******************************************************************************/
#if (1u == IRQ_SD_AVAILABLE)
void SD_IRQHandler(void)
{
    PDL_DummyHandler(14ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM4: FLASH *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_FLASH == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: FLASH IRQ handler (IRQ#119) Type a
 ******************************************************************************/
#if (1u == IRQ_FLASHIF_AVAILABLE)
void FLASHIF_IRQHandler(void)
{
    PDL_DummyHandler(15ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM4: NMI, HWWDG *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_NMI == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_HWWDG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM4: NMI, HWWDG IRQ handler (EXC#2) Type a
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


#endif // #ifdef __INTERRUPTS_FM4_TYPE_A_C__

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
