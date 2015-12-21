/*******************************************************************************
* Copyright (C) 2013 Spansion LLC. All Rights Reserved. 
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
/**
 ******************************************************************************
 **
 ** \file udp_echoserver.c
 **
 ** \brief UDP echo server demo
 **
 ** \author FSLA AE Team 
 **
 ** \version V0.1
 **
 ** \date 2012-7-09
 **
 ******************************************************************************
 **
 ** \note Other information.
 **
 ******************************************************************************
 */

/*---------------------------------------------------------------------------*/
/* include files                                                             								  */
/*---------------------------------------------------------------------------*/

#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"
#include <string.h>
#include <stdio.h>

/*---------------------------------------------------------------------------*/
/* local defines                                                                                                                 */
/*---------------------------------------------------------------------------*/
#define UDP_SERVER_PORT    7   /* define the UDP local connection port */

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                                                              */
/*---------------------------------------------------------------------------*/

void echo_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, struct ip_addr *addr, u16_t port);

/*!
 ******************************************************************************
 ** \brief  Initialize the server application.
 **
 ** \param None
 **
 ******************************************************************************
 */
void udp_echo_init(void)
{
   struct udp_pcb *upcb;
   err_t err;
   
   /* Create a new UDP control block  */
   upcb = udp_new();
   
   if (upcb)
   {
     /* Bind the upcb to the UDP_PORT port */
     /* Using IP_ADDR_ANY allow the upcb to be used by any local interface */
      err = udp_bind(upcb, IP_ADDR_ANY, UDP_SERVER_PORT);
      
      if(err == ERR_OK)
      {
        /* Set a receive callback for the upcb */
        udp_recv(upcb, echo_receive_callback, NULL);
      }
      else
      {
        printf("can not bind pcb");
      }
   }
   else
   {
     printf("can not create pcb");
   } 
}
/*!
 ******************************************************************************
 ** \brief  Called when an UDP datagrm has been received on the port UDP_PORT..
 **
 ** \param arg user supplied argument (udp_pcb.recv_arg)
 ** \param pcb the udp_pcb which received data
 ** \param p the packet buffer that was received
 ** \param addr the remote IP address from which the packet was received
 ** \param port the remote port from which the packet was received
 ******************************************************************************
 */
void echo_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, struct ip_addr *addr, u16_t port)
{

  /* Connect to the remote client */
  udp_connect(upcb, addr,port );
    
  /* Tell the client that we have accepted it */
  udp_send(upcb, p);

  /* free the UDP connection, so we can accept new clients */
  udp_disconnect(upcb);
	
  /* Free the p buffer */
  pbuf_free(p);
   
}


/*****************************************************************************/
/* END OF FILE */

