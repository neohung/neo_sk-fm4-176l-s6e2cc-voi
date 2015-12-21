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
 #ifdef __INTERRUPTS_FM0P_TYPE_1_B_C__

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

    // 0: IRQ003SEL, 1: IRQ004SEL, 2: IRQ005SEL, 3: IRQ006SEL, 4: IRQ007SEL, 
    // 5: IRQ008SEL, 6: IRQ009SEL, 7: IRQ010SEL, 8: LCD, 9: FLASH, 

    while (1u)
    { }
}

/******************************************************************************/
/********************************* FM0P: CSV **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CSV == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: CSV IRQ handler (IRQ#0) Type 1-b
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
 ** \brief FM0P: SWWDG IRQ handler (IRQ#1) Type 1-b
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
 ** \brief FM0P: LVD IRQ handler (IRQ#2) Type 1-b
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
/****************************** FM0P: IRQ003SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ003SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: IRQ003SEL IRQ handler (IRQ#3) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_IRQ003SEL_AVAILABLE)
void IRQ003SEL_IRQHandler(void)
{
    PDL_DummyHandler(0ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: IRQ004SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ004SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: IRQ004SEL IRQ handler (IRQ#4) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_IRQ004SEL_AVAILABLE)
void IRQ004SEL_IRQHandler(void)
{
    PDL_DummyHandler(1ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: IRQ005SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ005SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: IRQ005SEL IRQ handler (IRQ#5) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_IRQ005SEL_AVAILABLE)
void IRQ005SEL_IRQHandler(void)
{
    PDL_DummyHandler(2ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: IRQ006SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ006SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: IRQ006SEL IRQ handler (IRQ#6) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_IRQ006SEL_AVAILABLE)
void IRQ006SEL_IRQHandler(void)
{
    PDL_DummyHandler(3ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: IRQ007SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ007SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: IRQ007SEL IRQ handler (IRQ#7) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_IRQ007SEL_AVAILABLE)
void IRQ007SEL_IRQHandler(void)
{
    PDL_DummyHandler(4ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: IRQ008SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ008SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: IRQ008SEL IRQ handler (IRQ#8) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_IRQ008SEL_AVAILABLE)
void IRQ008SEL_IRQHandler(void)
{
    PDL_DummyHandler(5ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: IRQ009SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ009SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: IRQ009SEL IRQ handler (IRQ#9) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_IRQ009SEL_AVAILABLE)
void IRQ009SEL_IRQHandler(void)
{
    PDL_DummyHandler(6ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: IRQ010SEL *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_IRQ010SEL == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: IRQ010SEL IRQ handler (IRQ#10) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_IRQ010SEL_AVAILABLE)
void IRQ010SEL_IRQHandler(void)
{
    PDL_DummyHandler(7ul);
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/************************* FM0P: MFT0_WFG_DTIF, MFS8 **************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_WFG_DTIF == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS8 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFT0_WFG_DTIF, MFS8 IRQ handler (IRQ#11) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_MFT0_WFG_DTIF_MFS8_RX_TX_AVAILABLE)
void MFT0_WFG_DTIF_MFS8_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ11MON;

    #if (PDL_INTERRUPT_ENABLE_MFT0_WFG_DTIF == PDL_ON)
    if (0ul != (u32IrqMon & 0x0000000Ful))
    {
        Mft_Wfg_IrqHandler((volatile stc_mftn_wfg_t*)&MFT0_WFG, &m_astcMftWfgInstanceDataLut[WfgInstanceIndexWfg0].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS8 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000010ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS8 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS8 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000040ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN8, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs8].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
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
 ** \brief FM0P: EXINT0, EXINT1, EXINT2, EXINT3, EXINT4, EXINT5, EXINT6, EXINT7 IRQ handler (IRQ#12) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_EXINT0_7_AVAILABLE)
void EXINT0_7_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ12MON;

    #if (PDL_INTERRUPT_ENABLE_EXINT0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint0);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint1);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT2 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint2);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT3 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000008ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint3);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT4 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000010ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint4);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT5 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint5);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT6 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000040ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint6);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT7 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000080ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint7);

    }
    #endif
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/* FM0P: EXINT8, EXINT9, EXINT10, EXINT11, EXINT12, EXINT13, EXINT14, EXINT15, EXINT16, EXINT17, EXINT18, EXINT19, EXINT20, EXINT21, EXINT22, EXINT23, EXINT24, EXINT25, EXINT26, EXINT27, EXINT28, EXINT30, EXINT31 */
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
    (PDL_INTERRUPT_ENABLE_EXINT23 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT24 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT25 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT26 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT27 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT28 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT30 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT31 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: EXINT8, EXINT9, EXINT10, EXINT11, EXINT12, EXINT13, EXINT14, EXINT15, EXINT16, EXINT17, EXINT18, EXINT19, EXINT20, EXINT21, EXINT22, EXINT23, EXINT24, EXINT25, EXINT26, EXINT27, EXINT28, EXINT30, EXINT31 IRQ handler (IRQ#13) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_EXINT8_31_AVAILABLE)
void EXINT8_31_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ13MON;

    #if (PDL_INTERRUPT_ENABLE_EXINT8 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint8);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT9 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint9);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT10 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint10);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT11 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000008ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint11);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT12 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000010ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint12);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT13 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint13);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT14 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000040ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint14);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT15 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000080ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint15);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT16 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000100ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint16);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT17 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000200ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint17);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT18 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000400ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint18);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT19 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000800ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint19);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT20 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00001000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint20);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT21 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00002000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint21);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT22 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00004000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint22);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT23 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00008000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint23);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT24 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00010000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint24);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT25 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00020000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint25);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT26 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00040000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint26);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT27 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00080000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint27);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT28 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00100000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint28);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT28 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00020000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint29);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT30 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00040000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint30);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT31 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00080000ul))
    {
        Exint_IrqHandler(ExintInstanceIndexExint31);

    }
    #endif
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: DT0, QPRC0 ******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DT0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_QPRC0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: DT0, QPRC0 IRQ handler (IRQ#14) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_DT_QPRC0_AVAILABLE)
void DT_QPRC0_IRQHandler(void)
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
    
    #if (PDL_INTERRUPT_ENABLE_QPRC0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x000000FCul))
    {
        Qprc_IrqHandler((volatile stc_qprcn_t*)&QPRC0, &m_astcQprcInstanceDataLut[QprcInstanceIndexQprc0].stcInternData);

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
 ** \brief FM0P: MFS0 IRQ handler (IRQ#15) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_MFS0_RX_TX_AVAILABLE)
void MFS0_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ15MON;

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
 ** \brief FM0P: MFS1 IRQ handler (IRQ#16) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_MFS1_RX_TX_AVAILABLE)
void MFS1_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ16MON;

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
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: MFS2, MFS3 ******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS2, MFS3 IRQ handler (IRQ#17) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_MFS2_RX_TX_AVAILABLE)
void MFS2_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ17MON;

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
 ** \brief FM0P: MFS3 IRQ handler (IRQ#18) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_MFS3_RX_TX_AVAILABLE)
void MFS3_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ18MON;

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
 ** \brief FM0P: MFS4 IRQ handler (IRQ#19) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_MFS4_RX_AVAILABLE)
void MFS4_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ19MON;

#if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
if (0ul != (u32IrqMon & 0x00000001ul))
{
    switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData.enMode)
    {
        case MfsUartMode:
            MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));
    #warning debugging!
            break;
        case MfsCsioMode:
            MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));
    #warning debugging!
            break;
        case MfsI2cMode:
            MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));
    #warning debugging!
            break;
        case MfsLinMode:
            MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN4, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs4].stcInternData));
    #warning debugging!
            break;
        default:
            break;
    }
}
#endif

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
 ** \brief FM0P: MFS4 IRQ handler (IRQ#20) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_MFS4_TX_AVAILABLE)
void MFS4_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ20MON;

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
 ** \brief FM0P: MFS5 IRQ handler (IRQ#21) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_MFS5_RX_AVAILABLE)
void MFS5_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ21MON;

#if (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON)
if (0ul != (u32IrqMon & 0x00000001ul))
{
    switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData.enMode)
    {
        case MfsUartMode:
            MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));
    #warning debugging!
            break;
        case MfsCsioMode:
            MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));
    #warning debugging!
            break;
        case MfsI2cMode:
            MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));
    #warning debugging!
            break;
        case MfsLinMode:
            MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN5, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs5].stcInternData));
    #warning debugging!
            break;
        default:
            break;
    }
}
#endif

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
 ** \brief FM0P: MFS5 IRQ handler (IRQ#22) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_MFS5_TX_AVAILABLE)
void MFS5_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ22MON;

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
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: PPG **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_PPG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: PPG IRQ handler (IRQ#23) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_PPG00_02_04_08_10_12_14_16_18_20_AVAILABLE)
void PPG00_02_04_08_10_12_14_16_18_20_IRQHandler(void)
{
    Ppg_IrqHandler();
    #warning debugging!
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/**************************** FM0P: RTC0, WC0, CLK ****************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RTC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_WC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_CLK == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: RTC0, WC0, CLK IRQ handler (IRQ#24) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_TIM_AVAILABLE)
void TIM_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ24MON;

    #if (PDL_INTERRUPT_ENABLE_RTC0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        Rtc_IrqHandler((stc_rtcn_t*)&RTC0, &(m_astcRtcInstanceDataLut[RtcInstanceIndexRtc0].stcInternData));

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_WC0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000010ul))
    {
        Wc_IrqHandler(&WC0);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_CLK == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000007ul))
    {
        Clk_IrqHandler();

    }
    #endif
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: ADC0, MFS9 ******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ADC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS9 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: ADC0, MFS9 IRQ handler (IRQ#25) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_ADC0_MFS9_RX_TX_AVAILABLE)
void ADC0_MFS9_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ25MON;

    #if (PDL_INTERRUPT_ENABLE_ADC0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x0000001Ful))
    {
        AdcIrqHandler((volatile stc_adcn_t*)&ADC0, &(m_astcAdcInstanceDataLut[AdcInstanceIndexAdc0].stcInternData));

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS9 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS9 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000040ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS9 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000080ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN9, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs9].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/***************************** FM0P: ADC1, MFS10 ******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ADC1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS10 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: ADC1, MFS10 IRQ handler (IRQ#26) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_ADC1_MFS10_RX_TX_AVAILABLE)
void ADC1_MFS10_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ26MON;

    #if (PDL_INTERRUPT_ENABLE_ADC1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x0000001Ful))
    {
        AdcIrqHandler((volatile stc_adcn_t*)&ADC1, &(m_astcAdcInstanceDataLut[AdcInstanceIndexAdc1].stcInternData));

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS10 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS10 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000040ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS10 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000080ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN10, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs10].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/*************************** FM0P: ADC2, LCD, MFS11 ***************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ADC2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_LCD == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_MFS11 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: ADC2, LCD, MFS11 IRQ handler (IRQ#27) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_ADC2_LCDC_MFS11_RX_TX_AVAILABLE)
void ADC2_LCDC_MFS11_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ27MON;

    #if (PDL_INTERRUPT_ENABLE_ADC2 == PDL_ON)
    if (0ul != (u32IrqMon & 0x0000001Ful))
    {
        AdcIrqHandler((volatile stc_adcn_t*)&ADC2, &(m_astcAdcInstanceDataLut[AdcInstanceIndexAdc2].stcInternData));

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_LCD == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        PDL_DummyHandler(8ul);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS11 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000040ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerRx((stc_mfsn_uart_t*)&UART11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerRx((stc_mfsn_csio_t*)&CSIO11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerRx((stc_mfsn_i2c_t*)&I2C11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerRx((stc_mfsn_lin_t*)&LIN11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS11 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000080ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData.enMode)
        {
            case MfsUartMode:
                MfsUartIrqHandlerTx((stc_mfsn_uart_t*)&UART11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerTx((stc_mfsn_csio_t*)&CSIO11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerTx((stc_mfsn_i2c_t*)&I2C11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerTx((stc_mfsn_lin_t*)&LIN11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_MFS11 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000100ul))
    {
        switch(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData.enMode)
        {
            case MfsUartMode:
                // should never happen
                while (1u)
                { }

                break;
            case MfsCsioMode:
                MfsCsioIrqHandlerStatus((stc_mfsn_csio_t*)&CSIO11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            case MfsI2cMode:
                MfsI2cIrqHandlerStatus((stc_mfsn_i2c_t*)&I2C11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            case MfsLinMode:
                MfsLinIrqHandlerStatus((stc_mfsn_lin_t*)&LIN11, &(m_astcMfsInstanceDataLut[MfsInstanceIndexMfs11].stcInternData));

                break;
            default:
                break;
        }
    }
    #endif
    
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
 ** \brief FM0P: BT0, BT1, BT2, BT3, BT4, BT5, BT6, BT7, FLASH IRQ handler (IRQ#31) Type 1-b
 ******************************************************************************/
#if (1u == IRQ_BT0_7_FLASHIF_AVAILABLE)
void BT0_7_FLASHIF_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ31MON;

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
        PDL_DummyHandler(9ul);

    }
    #endif
    
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
 ** \brief FM0P: NMI, HWWDG IRQ handler (EXC#2) Type 1-b
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


#endif // #ifdef __INTERRUPTS_FM0P_TYPE_1-B_C__

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
