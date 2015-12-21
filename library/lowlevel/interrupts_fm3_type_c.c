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
 #ifdef __INTERRUPTS_FM3_TYPE_C_C__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/

#include "interrupts_fm3.h"

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

    // 

    while (1u)
    { }
}

/******************************************************************************/
/********************************** FM3: CSV **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CSV == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: CSV IRQ handler (IRQ#0) Type c
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
/********************************* FM3: SWWDG *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_SWWDG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: SWWDG IRQ handler (IRQ#1) Type c
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
/********************************** FM3: LVD **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_LVD == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: LVD IRQ handler (IRQ#2) Type c
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
/******************************* FM3: MFT0_WFG ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_WFG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFT0_WFG IRQ handler (IRQ#3) Type c
 ******************************************************************************/
#if (1u == IRQ_MFT0_WFG_AVAILABLE)
void MFT0_WFG_IRQHandler(void)
{
    Mft_Wfg_IrqHandler((volatile stc_mftn_wfg_t*)&MFT0_WFG, &m_astcMftWfgInstanceDataLut[WfgInstanceIndexWfg0].stcInternData);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/**** FM3: EXINT0, EXINT1, EXINT2, EXINT3, EXINT4, EXINT5, EXINT6, EXINT7 *****/
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
 ** \brief FM3: EXINT0, EXINT1, EXINT2, EXINT3, EXINT4, EXINT5, EXINT6, EXINT7 IRQ handler (IRQ#4) Type c
 ******************************************************************************/
#if (1u == IRQ_EXINT0_7_AVAILABLE)
void EXINT0_7_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ04MON;

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
/* FM3: EXINT8, EXINT9, EXINT10, EXINT11, EXINT12, EXINT13, EXINT14, EXINT15 **/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT8 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT9 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT10 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT11 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT12 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT13 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT14 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT15 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: EXINT8, EXINT9, EXINT10, EXINT11, EXINT12, EXINT13, EXINT14, EXINT15 IRQ handler (IRQ#5) Type c
 ******************************************************************************/
#if (1u == IRQ_EXINT8_15_AVAILABLE)
void EXINT8_15_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ05MON;

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
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS0 IRQ handler (IRQ#6) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS0_RX_AVAILABLE)
void MFS0_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ06MON;

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

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS0 IRQ handler (IRQ#7) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS0_TX_AVAILABLE)
void MFS0_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ07MON;

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
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS1 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS1 IRQ handler (IRQ#8) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS1_RX_AVAILABLE)
void MFS1_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ08MON;

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

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS1 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS1 IRQ handler (IRQ#9) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS1_TX_AVAILABLE)
void MFS1_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ09MON;

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
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS2 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS2 IRQ handler (IRQ#10) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS2_RX_AVAILABLE)
void MFS2_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ10MON;

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

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS2 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS2 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS2 IRQ handler (IRQ#11) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS2_TX_AVAILABLE)
void MFS2_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ11MON;

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
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS3 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS3 IRQ handler (IRQ#12) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS3_RX_AVAILABLE)
void MFS3_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ12MON;

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

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS3 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS3 IRQ handler (IRQ#13) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS3_TX_AVAILABLE)
void MFS3_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ13MON;

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
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS4 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS4 IRQ handler (IRQ#14) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS4_RX_AVAILABLE)
void MFS4_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ14MON;

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

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS4 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS4 IRQ handler (IRQ#15) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS4_TX_AVAILABLE)
void MFS4_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ15MON;

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
/********************************* FM3: MFS5 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS5 IRQ handler (IRQ#16) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS5_RX_AVAILABLE)
void MFS5_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ16MON;

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

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS5 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS5 IRQ handler (IRQ#17) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS5_TX_AVAILABLE)
void MFS5_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ17MON;

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
/********************************* FM3: MFS6 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS6 IRQ handler (IRQ#18) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS6_RX_AVAILABLE)
void MFS6_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ18MON;

#if (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON)
if (0ul != (u32IrqMon & 0x00000001ul))
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

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS6 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS6 IRQ handler (IRQ#19) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS6_TX_AVAILABLE)
void MFS6_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ19MON;

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
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS7 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS7 IRQ handler (IRQ#20) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS7_RX_AVAILABLE)
void MFS7_RX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ20MON;

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

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: MFS7 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFS7 IRQ handler (IRQ#21) Type c
 ******************************************************************************/
#if (1u == IRQ_MFS7_TX_AVAILABLE)
void MFS7_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ21MON;

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
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************** FM3: PPG0_20 ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_PPG0_20 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: PPG0_20 IRQ handler (IRQ#22) Type c
 ******************************************************************************/
#if (1u == IRQ_PPG00_02_20_AVAILABLE)
void PPG00_02_20_IRQHandler(void)
{
    Ppg_IrqHandler();

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM3: RTC, CLK ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RTC == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_CLK == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: RTC, CLK IRQ handler (IRQ#23) Type c
 ******************************************************************************/
#if (1u == IRQ_TIM_AVAILABLE)
void TIM_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ23MON;

    #if (PDL_INTERRUPT_ENABLE_RTC == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000020ul))
    {
        Rtc_IrqHandler((stc_rtcn_t*)&RTC0, &(m_astcRtcInstanceDataLut[RtcInstanceIndexRtc0].stcInternData));
    
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
/********************************* FM3: ADC0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ADC0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: ADC0 IRQ handler (IRQ#24) Type c
 ******************************************************************************/
#if (1u == IRQ_ADC0_AVAILABLE)
void ADC0_IRQHandler(void)
{
    AdcIrqHandler((volatile stc_adcn_t*)&ADC0, &(m_astcAdcInstanceDataLut[AdcInstanceIndexAdc0].stcInternData));

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM3: MFT0_FRT ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_FRT == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFT0_FRT IRQ handler (IRQ#25) Type c
 ******************************************************************************/
#if (1u == IRQ_MFT0_FRT_AVAILABLE)
void MFT0_FRT_IRQHandler(void)
{
    Mft_Frt_IrqHandler((volatile stc_mftn_frt_t*)&MFT0_FRT, &m_astcMftFrtInstanceDataLut[FrtInstanceIndexFrt0].stcInternData);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM3: MFT0_ICU ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_ICU == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFT0_ICU IRQ handler (IRQ#26) Type c
 ******************************************************************************/
#if (1u == IRQ_MFT0_ICU_AVAILABLE)
void MFT0_ICU_IRQHandler(void)
{
    Mft_Icu_IrqHandler((volatile stc_mftn_icu_t*)&MFT0_ICU, &m_astcMftIcuInstanceDataLut[IcuInstanceIndexIcu0].stcInternData);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM3: MFT0_OCU ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFT0_OCU == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: MFT0_OCU IRQ handler (IRQ#27) Type c
 ******************************************************************************/
#if (1u == IRQ_MFT0_OCU_AVAILABLE)
void MFT0_OCU_IRQHandler(void)
{
    Mft_Ocu_IrqHandler((volatile stc_mftn_ocu_t*)&MFT0_OCU, &m_astcMftOcuInstanceDataLut[OcuInstanceIndexOcu0].stcInternData);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/**************** FM3: BT0, BT1, BT2, BT3, BT4, BT5, BT6, BT7 *****************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT3 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT4 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT5 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT6 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: BT0, BT1, BT2, BT3, BT4, BT5, BT6, BT7 IRQ handler (IRQ#28) Type c
 ******************************************************************************/
#if (1u == IRQ_BT0_7_AVAILABLE)
void BT0_7_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ28MON;

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
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************** FM3: LCD **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_LCD == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: LCD IRQ handler (IRQ#29) Type c
 ******************************************************************************/
#if (1u == IRQ_LCDC_AVAILABLE)
void LCDC_IRQHandler(void)
{
    Lcd_IrqHandler();

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: CEC0 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CEC0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: CEC0 IRQ handler (IRQ#30) Type c
 ******************************************************************************/
#if (1u == IRQ_HDMICEC0_AVAILABLE)
void HDMICEC0_IRQHandler(void)
{
    Rc_IrqHandler(0u);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM3: CEC1 **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CEC1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: CEC1 IRQ handler (IRQ#31) Type c
 ******************************************************************************/
#if (1u == IRQ_HDMICEC1_AVAILABLE)
void HDMICEC1_IRQHandler(void)
{
    Rc_IrqHandler(1u);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM3: NMI, HWWDG *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_NMI == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_HWWDG == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM3: NMI, HWWDG IRQ handler (EXC#2) Type c
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


#endif // #ifdef __INTERRUPTS_FM3_TYPE_C_C__

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
