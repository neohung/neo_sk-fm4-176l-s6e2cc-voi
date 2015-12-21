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
 #ifdef __INTERRUPTS_FM0P_TYPE_3_C__

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

    // 0: USB0_DEVICE, 1: USB0_DEVICE, 2: USB0_DEVICE, 3: USB0_HOST, 4: ICC1, 
    // 5: FLASH, 6: DSTC, 

    while (1u)
    { }
}

/******************************************************************************/
/*************************** FM0P: CSV, SWWDG, LVD ****************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CSV == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_SWWDG == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_LVD == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: CSV, SWWDG, LVD IRQ handler (IRQ#0) Type 3
 ******************************************************************************/
#if (1u == IRQ_CSV_SWDT_LVD_AVAILABLE)
void CSV_SWDT_LVD_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ00MON;

    #if (PDL_INTERRUPT_ENABLE_CSV == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Csv_IrqHandler();

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_SWWDG == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        SwwdgIrqHandler();

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_LVD == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        Lvd_IrqHandler();

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
 ** \brief FM0P: MFS0 IRQ handler (IRQ#1) Type 3
 ******************************************************************************/
#if (1u == IRQ_MFS0_RX_TX_AVAILABLE)
void MFS0_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ01MON;

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
 ** \brief FM0P: MFS1 IRQ handler (IRQ#2) Type 3
 ******************************************************************************/
#if (1u == IRQ_MFS1_RX_TX_AVAILABLE)
void MFS1_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ02MON;

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
/********************************* FM0P: MFS3 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS3 IRQ handler (IRQ#4) Type 3
 ******************************************************************************/
#if (1u == IRQ_MFS3_RX_TX_AVAILABLE)
void MFS3_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ04MON;

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
 ** \brief FM0P: MFS4 IRQ handler (IRQ#5) Type 3
 ******************************************************************************/
#if (1u == IRQ_MFS4_RX_TX_AVAILABLE)
void MFS4_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ05MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS4_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS4_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS4_RX);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFS4_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS4_TX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS4_TX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS4_RX != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFS4_TX != PDL_ON)

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
    
    #if (PDL_INTERRUPT_ENABLE_MFS4 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
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
    if (0ul != (u32IrqMon & 0x00000004ul))
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
/***************************** FM0P: MFS6, I2CS0 ******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_I2CS0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS6, I2CS0 IRQ handler (IRQ#7) Type 3
 ******************************************************************************/
#if (1u == IRQ_MFS6_RX_TX_I2CSLAVE_AVAILABLE)
void MFS6_RX_TX_I2CSLAVE_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ07MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS6_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS6_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS6_RX);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFS6_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS6_TX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS6_TX);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_I2CS0_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_I2CS0_TX))
    {
        Dstc_I2csIrqHandler(DSTC_IRQ_NUMBER_I2CS0_TX);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_I2CS0_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_I2CS0_RX))
    {
        Dstc_I2csIrqHandler(DSTC_IRQ_NUMBER_I2CS0_RX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS6_RX != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFS6_TX != PDL_ON) && \
    (PDL_DSTC_ENABLE_I2CS0_TX != PDL_ON) && \
    (PDL_DSTC_ENABLE_I2CS0_RX != PDL_ON)

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
    
    #if (PDL_INTERRUPT_ENABLE_MFS6 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
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
    if (0ul != (u32IrqMon & 0x00000004ul))
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
    
    #if (PDL_INTERRUPT_ENABLE_I2CS0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        I2csIrqHandlerRx((stc_i2csn_t*) &I2CS0, m_astcI2csInstanceDataLut[0u]);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_I2CS0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        I2csIrqHandlerTx((stc_i2csn_t*) &I2CS0, m_astcI2csInstanceDataLut[0u]);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_I2CS0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000004ul))
    {
        I2csIrqHandlerStatus((stc_i2csn_t*) &I2CS0, m_astcI2csInstanceDataLut[0u]);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: MFS7 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_MFS7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: MFS7 IRQ handler (IRQ#8) Type 3
 ******************************************************************************/
#if (1u == IRQ_MFS7_RX_TX_AVAILABLE)
void MFS7_RX_TX_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ08MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_MFS7_RX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS7_RX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS7_RX);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_MFS7_TX)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_MFS7_TX))
    {
        Dstc_MfsRxIrqHandler(DSTC_IRQ_NUMBER_MFS7_TX);

    }
    #endif

#if (PDL_DSTC_ENABLE_MFS7_RX != PDL_ON) && \
    (PDL_DSTC_ENABLE_MFS7_TX != PDL_ON)

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
    
    #if (PDL_INTERRUPT_ENABLE_MFS7 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
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
    if (0ul != (u32IrqMon & 0x00000004ul))
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
/********************************* FM0P: ADC0 *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ADC0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: ADC0 IRQ handler (IRQ#9) Type 3
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
/***************************** FM0P: USB0_DEVICE ******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_USB0_DEVICE == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: USB0_DEVICE IRQ handler (IRQ#10) Type 3
 ******************************************************************************/
#if (1u == IRQ_USB0_F_ED123_AVAILABLE)
void USB0_F_ED123_IRQHandler(void)
{
    PDL_DummyHandler(0ul);

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
 ** \brief FM0P: USB0_DEVICE IRQ handler (IRQ#11) Type 3
 ******************************************************************************/
#if (1u == IRQ_USB0_F_ED450I_AVAILABLE)
void USB0_F_ED450I_IRQHandler(void)
{
    PDL_DummyHandler(1ul);

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
 ** \brief FM0P: USB0_DEVICE IRQ handler (IRQ#12) Type 3
 ******************************************************************************/
#if (1u == IRQ_USB0_F_ED0O_ST_AVAILABLE)
void USB0_F_ED0O_ST_IRQHandler(void)
{
    PDL_DummyHandler(2ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/****************************** FM0P: USB0_HOST *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_USB0_HOST == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: USB0_HOST IRQ handler (IRQ#13) Type 3
 ******************************************************************************/
#if (1u == IRQ_USB0_H_AVAILABLE)
void USB0_H_IRQHandler(void)
{
    PDL_DummyHandler(3ul);

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: CLK **********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_CLK == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: CLK IRQ handler (IRQ#14) Type 3
 ******************************************************************************/
#if (1u == IRQ_TIM_AVAILABLE)
void TIM_IRQHandler(void)
{
    Clk_IrqHandler();

}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/***************************** FM0P: WC, RTC, DT0 *****************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_WC == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RTC == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_DT0 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: WC, RTC, DT0 IRQ handler (IRQ#15) Type 3
 ******************************************************************************/
#if (1u == IRQ_WC_RTC_DT_AVAILABLE)
void WC_RTC_DT_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ15MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_WC0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_WC0))
    {
        Dstc_WcIrqHandler();

    }
    #endif

#if (PDL_DSTC_ENABLE_WC0 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_WC == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Wc_IrqHandler((stc_wcn_t*)&WC0);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_RTC == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Rtc_IrqHandler((stc_rtcn_t*)&RTC0, &(m_astcRtcInstanceDataLut[RtcInstanceIndexRtc0].stcInternData));

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_DT0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
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
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/**************************** FM0P: EXINT0, EXINT1 ****************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: EXINT0, EXINT1 IRQ handler (IRQ#16) Type 3
 ******************************************************************************/
#if (1u == IRQ_EXINT0_1_AVAILABLE)
void EXINT0_1_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ16MON;

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

#if (PDL_DSTC_ENABLE_EXINT0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT1 != PDL_ON)

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
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/**************************** FM0P: EXINT2, EXINT3 ****************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT3 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: EXINT2, EXINT3 IRQ handler (IRQ#17) Type 3
 ******************************************************************************/
#if (1u == IRQ_EXINT2_3_AVAILABLE)
void EXINT2_3_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ17MON;

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

#if (PDL_DSTC_ENABLE_EXINT2 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT3 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_EXINT2 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(2u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT3 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(3u);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/**************************** FM0P: EXINT4, EXINT5 ****************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT4 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: EXINT4, EXINT5 IRQ handler (IRQ#18) Type 3
 ******************************************************************************/
#if (1u == IRQ_EXINT4_5_AVAILABLE)
void EXINT4_5_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ18MON;

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

#if (PDL_DSTC_ENABLE_EXINT4 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT5 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_EXINT4 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(4u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT5 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(5u);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/**************************** FM0P: EXINT6, EXINT7 ****************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT6 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: EXINT6, EXINT7 IRQ handler (IRQ#19) Type 3
 ******************************************************************************/
#if (1u == IRQ_EXINT6_7_AVAILABLE)
void EXINT6_7_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ19MON;

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

#if (PDL_DSTC_ENABLE_EXINT6 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT7 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_EXINT6 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(6u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT7 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
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
/******************************** FM0P: EXINT8 ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT8 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: EXINT8 IRQ handler (IRQ#20) Type 3
 ******************************************************************************/
#if (1u == IRQ_EXINT8_AVAILABLE)
void EXINT8_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT8)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT8))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT8);

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
/*************************** FM0P: EXINT12, EXINT13 ***************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT12 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_EXINT13 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: EXINT12, EXINT13 IRQ handler (IRQ#22) Type 3
 ******************************************************************************/
#if (1u == IRQ_EXINT12_13_AVAILABLE)
void EXINT12_13_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ22MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT12)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT12))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT12);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT13)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT13))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT13);

    }
    #endif

#if (PDL_DSTC_ENABLE_EXINT12 != PDL_ON) && \
    (PDL_DSTC_ENABLE_EXINT13 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_EXINT12 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Exint_IrqHandler(12u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_EXINT13 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Exint_IrqHandler(13u);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM0P: EXINT15 ********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_EXINT15 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: EXINT15 IRQ handler (IRQ#23) Type 3
 ******************************************************************************/
#if (1u == IRQ_EXINT15_AVAILABLE)
void EXINT15_IRQHandler(void)
{
    #if (PDL_ON == PDL_DSTC_ENABLE_EXINT15)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_EXTINT15))
    {
        Dstc_ExintIrqHandler(DSTC_IRQ_NUMBER_EXTINT15);

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
/******************************* FM0P: BT0, BT4 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT4 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: BT0, BT4 IRQ handler (IRQ#24) Type 3
 ******************************************************************************/
#if (1u == IRQ_BT0_4_AVAILABLE)
void BT0_4_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ24MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_BT0_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT0_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT0_IRQ0, DSTC_IRQ_NUMBER_BT0_IRQ1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_BT4_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT4_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT4_IRQ0, DSTC_IRQ_NUMBER_BT4_IRQ1);

    }
    #endif

#if (PDL_DSTC_ENABLE_BT0_IRQ0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_BT4_IRQ0 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_BT0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT0, &m_astcBtInstanceDataLut[BtInstanceIndexBt0].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT4 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT4, &m_astcBtInstanceDataLut[BtInstanceIndexBt4].stcInternData);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM0P: BT1, BT5 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT5 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: BT1, BT5 IRQ handler (IRQ#25) Type 3
 ******************************************************************************/
#if (1u == IRQ_BT1_5_AVAILABLE)
void BT1_5_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ25MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_BT1_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT1_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT1_IRQ0, DSTC_IRQ_NUMBER_BT1_IRQ1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_BT5_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT5_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT5_IRQ0, DSTC_IRQ_NUMBER_BT5_IRQ1);

    }
    #endif

#if (PDL_DSTC_ENABLE_BT1_IRQ0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_BT5_IRQ0 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_BT1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT1, &m_astcBtInstanceDataLut[BtInstanceIndexBt1].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT5 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT5, &m_astcBtInstanceDataLut[BtInstanceIndexBt5].stcInternData);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM0P: BT2, BT6 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT2 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT6 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: BT2, BT6 IRQ handler (IRQ#26) Type 3
 ******************************************************************************/
#if (1u == IRQ_BT2_6_AVAILABLE)
void BT2_6_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ26MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_BT2_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT2_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT2_IRQ0, DSTC_IRQ_NUMBER_BT2_IRQ1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_BT6_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT6_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT6_IRQ0, DSTC_IRQ_NUMBER_BT6_IRQ1);

    }
    #endif

#if (PDL_DSTC_ENABLE_BT2_IRQ0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_BT6_IRQ0 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_BT2 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT2, &m_astcBtInstanceDataLut[BtInstanceIndexBt2].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT6 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT6, &m_astcBtInstanceDataLut[BtInstanceIndexBt6].stcInternData);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM0P: BT3, BT7 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_BT3 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_BT7 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: BT3, BT7 IRQ handler (IRQ#27) Type 3
 ******************************************************************************/
#if (1u == IRQ_BT3_7_AVAILABLE)
void BT3_7_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ27MON;

    #if (PDL_ON == PDL_DSTC_ENABLE_BT3_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT3_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT3_IRQ0, DSTC_IRQ_NUMBER_BT3_IRQ1);

    }
    #endif
    #if (PDL_ON == PDL_DSTC_ENABLE_BT7_IRQ0)
    if (TRUE == Dstc_ReadHwintBit(DSTC_IRQ_NUMBER_BT7_IRQ0))
    {
        Dstc_BtIrqHandler(DSTC_IRQ_NUMBER_BT7_IRQ0, DSTC_IRQ_NUMBER_BT7_IRQ1);

    }
    #endif

#if (PDL_DSTC_ENABLE_BT3_IRQ0 != PDL_ON) && \
    (PDL_DSTC_ENABLE_BT7_IRQ0 != PDL_ON)

    #if (PDL_INTERRUPT_ENABLE_BT3 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT3, &m_astcBtInstanceDataLut[BtInstanceIndexBt3].stcInternData);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_BT7 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Bt_IrqHandler((volatile stc_btn_t*)&BT7, &m_astcBtInstanceDataLut[BtInstanceIndexBt7].stcInternData);

    }
    #endif
    

#endif // #if (PDL_DSTC_ENABLE_... != PDL_ON)
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/******************************* FM0P: RC0, RC1 *******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_RC0 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_RC1 == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: RC0, RC1 IRQ handler (IRQ#28) Type 3
 ******************************************************************************/
#if (1u == IRQ_HDMICEC0_1_AVAILABLE)
void HDMICEC0_1_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ28MON;

    #if (PDL_INTERRUPT_ENABLE_RC0 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        Rc_IrqHandler(0u);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_RC1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        Rc_IrqHandler(1u);

    }
    #endif
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/***************************** FM0P: ICC1, FLASH ******************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_ICC1 == PDL_ON) || \
    (PDL_INTERRUPT_ENABLE_FLASH == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: ICC1, FLASH IRQ handler (IRQ#29) Type 3
 ******************************************************************************/
#if (1u == IRQ_SMCIF1_FLASHIF_AVAILABLE)
void SMCIF1_FLASHIF_IRQHandler(void)
{
    uint32_t u32IrqMon = FM_INTREQ->IRQ29MON;

    #if (PDL_INTERRUPT_ENABLE_ICC1 == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000001ul))
    {
        PDL_DummyHandler(4ul);

    }
    #endif
    
    #if (PDL_INTERRUPT_ENABLE_FLASH == PDL_ON)
    if (0ul != (u32IrqMon & 0x00000002ul))
    {
        PDL_DummyHandler(5ul);

    }
    #endif
    
}
#else
    #error No IRQ handler found.
#endif // #if (1u == IRQ_ ... _AVAILABLE)
#endif // #if (PDL_INTERRUPT_ENABLE_ ... == PDL_ON)


/******************************************************************************/
/********************************* FM0P: DSTC *********************************/
/******************************************************************************/
#if (PDL_INTERRUPT_ENABLE_DSTC == PDL_ON)
/**
 ******************************************************************************
 ** \brief FM0P: DSTC IRQ handler (IRQ#30) Type 3
 ******************************************************************************/
#if (1u == IRQ_DSTC_AVAILABLE)
void DSTC_IRQHandler(void)
{
    PDL_DummyHandler(6ul);

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
 ** \brief FM0P: NMI, HWWDG IRQ handler (EXC#2) Type 3
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


#endif // #ifdef __INTERRUPTS_FM0P_TYPE_3_C__

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
