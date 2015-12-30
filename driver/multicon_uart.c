#include "multicon_uart.h"
#include <string.h>

static uint8_t u8DefaultUart = 0;
const char_t ASCII[] = "0123456789ABCDEF";

char_t line_buffer[255];
char_t *line_buffer_ptr;


static stc_multicon_mfs_uart_t* UART_BASE[] = {
        #if defined(FM4_MFS0_BASE)          
          ((stc_multicon_mfs_uart_t *)FM4_MFS0_BASE),
        #else
           #error "For SK-FM4-176L-S6E2CC UART Should be FM4_MFS0_BASE"
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS1_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS1_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS2_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS2_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS3_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS3_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS4_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS4_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS5_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS5_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS6_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS6_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS7_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS7_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS8_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS8_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS9_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS9_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS10_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS10_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS11_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS11_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS12_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS12_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS13_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS13_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS14_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS14_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS15_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS15_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
};

//----------------------------------------------------------------------------------
boolean_t Uart_Init(uint8_t u8Uart, uint32_t Baudrate)
{
    if (UART_BASE[u8Uart] == NULL)
    {
        return FALSE;
    }
    UART_BASE[u8Uart]->SCR =  0x80;
    UART_BASE[u8Uart]->SMR =  0x01;
    UART_BASE[u8Uart]->SSR =  0x00;
    UART_BASE[u8Uart]->ESCR = 0x00;
    UART_BASE[u8Uart]->BGR = (uint16_t)Baudrate; //(uint16_t)BGRTemp;
    UART_BASE[u8Uart]->SCR = 0x03;
    // Here to set uart default to 0
    u8DefaultUart = u8Uart;
     switch (u8Uart)
        {
            case 0:
                /* SIN Pin */               
                bFM4_GPIO_PFR2_P1 = 1;
                FM4_GPIO->EPFR07 &= ~(0x03 << 4);
                FM4_GPIO->EPFR07 |= (0x01 << 4);                
                /* SOT Pin */
                FM4_GPIO->ADE &= ~(1u << 31u); 
                bFM4_GPIO_PFR2_P2 = 1;
                FM4_GPIO->EPFR07 &= ~(0x03 << 6);
                FM4_GPIO->EPFR07 |= (0x01 << 6);
                break;
            default:
                // not supported by eva board, but may usable
                return FALSE;
        }
    return TRUE;
}

void Uart_Putch(uint8_t u8Uart, char_t c)
{
    if (UART_BASE[u8Uart] == NULL)
    {
        return;
    }
    while (!(UART_BASE[u8Uart]->SSR & (1 << 1)));		/* wait for transmit buffer empty 	*/
    UART_BASE[u8Uart]->RDR = c;            /* put ch into buffer	*/
}

void Uart_Puts(uint8_t u8Uart, char_t* String)
{
	while (*String != '\0')
	{ 
        //if(*String == '\n') Uart_Putch(u8Uart,'\r');
        Uart_Putch(u8Uart,*String++);        /* send every char of string */
    }
}


char_t Uart_Getch(uint8_t u8Uart)
{
    if (UART_BASE[u8Uart] == NULL)
    {
        return 0;
    }
    while(!(UART_BASE[u8Uart]->SSR & (1 << 2)));			/* wait for data in buffer */
    if (UART_BASE[u8Uart]->SSR & 0x38) 
    {	/* overrun or parity error */
        UART_BASE[u8Uart]->SSR |= (1 << 7);
        return 0;//(-1);
    } 
    else
    {
	return (UART_BASE[u8Uart]->RDR);
    }
}

boolean_t Multicon_UartHasData(uint8_t u8Uart)
{
    //uint8_t u8Dummy;
    if (UART_BASE[u8Uart] == NULL)
    {
        return FALSE;
    }
    if ((UART_BASE[u8Uart]->SSR & (1 << 2)))
    {
        if (UART_BASE[u8Uart]->SSR & 0x38) 
        {	// overrun or parity error
            UART_BASE[u8Uart]->SSR |= (1 << 7);
            return FALSE;//(-1);
        } 
        else
        {
            return TRUE;
        }
    }
    return FALSE;
}
//-----------------------------------
//USE uart default
//-----------------------------------
boolean_t Uart_DefaultHasData(void)
{
    return Multicon_UartHasData(u8DefaultUart);
}


void putch(char_t c)
{
    Uart_Putch(u8DefaultUart, c);
}

char_t getch()
{
    return Uart_Getch(u8DefaultUart);
}

int puts(const char_t* String)
{
    Uart_Puts(u8DefaultUart,(char_t*)String);
    return 0;
}

//output dec number as ascii char
void putdec(uint32_t x)
{
	int i;
	char buf[9];	
	buf[8]='\0';				/* end sign of string */
	
	for (i=8; i>0; i--) 
	{
     buf[i-1] = ASCII[x % 10];
	   x = x/10;
	}

	for (i=0; buf[i]=='0'; i++) // no print of zero 
	{
	   buf[i] = ' ';
  }
	puts(buf);					/* send string */
}

//output dec_number: "n" to hex present and digits means ths size is how long
void puthex(uint32_t n, uint8_t digits)
{
	unsigned char i,ch,div=0;
	puts("0x");				/* hex string */
	div=(digits-1) << 2;	/* init shift divisor */

	for (i=0; i<digits; i++) {
	  ch = (n >> div) & 0xF;/* get hex-digit value */
	  putch(ASCII[ch]);		/* prompt to terminal as ASCII */
	  div-=4;				/* next digit shift */
   }
}

//Convert ASCII '0' to int 0
//Convert ASCII 'A' ot a to int 10
unsigned long ASCIItobin(unsigned char k)
{
  char d=(char) -1;
  if ((k > 47) & (k < 58)) d = k - 48;  /* 0..9 */
  if ((k > 64) & (k < 71)) d = k - 55;  /* A..F */
  if ((k > 96) & (k < 103)) d = k - 87; /* a..f */
  return d;
}

char* receive_line_echo(int *cnt)
{ 
  unsigned char ch;
  unsigned short i=0;
  memset(line_buffer,0,sizeof(line_buffer));
	do {
		ch = getch(); 
        //Here to deside output key or not
        putch(ch);
        if((ch == 13) | (ch==27)) break;
        line_buffer[i++] = ch;
   } while(1);

   line_buffer[i]='\0';
   line_buffer_ptr = line_buffer + i;
   if (cnt) *cnt = i;
   //BufferPtr = (char)  &line_buffer;
   return (char*) &line_buffer;
}

//---------------------------------------------------------------
//PRINTF

typedef struct 
{
 short level ;
 short token ;
 short bsize ;
 char fd ;
 unsigned flags ;
 unsigned char hold ;
 unsigned char *buffer ;
 unsigned char * curp ;
 unsigned istemp; 
}FILE ;

#include <stdarg.h> //for va_list,  va_start() and va_end()
//number convert
static char *num_convert(unsigned int num, int base)
{
  static char buff[33];
  char *ptr;
  ptr=&buff[sizeof(buff)-1];
  *ptr='\0';
  do
  {
    //*--ptr="0123456789abcdef"[num%base];
    *--ptr="0123456789ABCDEF"[num%base];
    num/=base;
  }while(num!=0);
  return(ptr);
}

static int fputc(int ch, FILE *f)
{
    if(((uint8_t)ch) == '\n')
    {
        while (Uart_DefaultHasData()); /* wait until TX buffer empty */
        putch('\r');
    }
    while (Uart_DefaultHasData()); /* wait until TX buffer empty */
    putch(ch);
    return ch;
}

static int vfprintf (FILE *s, const char *format, va_list vlist)
{
  int done = 0;
  while(*format != '\0')
  {
     if(*format == '%')
     {
       format++;
       switch (*format)
       {
         case 'd':
         {
            char acTemp[256] = "";
            int iTemp = 0;
            iTemp = va_arg(vlist, int);
            itoa(iTemp, acTemp, 10); 
            int i;
            for(i = 0; i < 256; i++)
            {
                if(acTemp[i] == '\0') break;
                fputc(acTemp[i],NULL);
                done++;
            }
         }
         break;
         case 's':
         {
           char* pcTemp = NULL;
           pcTemp = va_arg(vlist, char*);
           while(*pcTemp != '\0')
           {
                fputc(*pcTemp,NULL);
                done++;
                pcTemp++;
           }
         }
         break;
         case 'c':
         {
            int cTemp;
            cTemp = va_arg(vlist, int);  
            fputc(cTemp,NULL);
            done++;
         }
         break;
         case 'x':
         {
           unsigned int u=va_arg(vlist, unsigned int);
           char* pcTemp = NULL;
           pcTemp = num_convert(u,16); 
            while(*pcTemp != '\0')
           {
                fputc(*pcTemp,NULL);
                done++;
                pcTemp++;
           }
           break;
         }
         break;
         default:
         break;
       }
       format++;
     }else{
       fputc(*format,NULL);
       format++;
       done++;
     }
  }
  return done;
}

int printf(const char* format, ...)
{
  int done;
  va_list arg;
  va_start(arg, format);
    done = vfprintf(NULL, format, arg); 
  va_end(arg);
  return done;
}


