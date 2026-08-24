#include <avr/io.h>
#include <stdint.h>

#include "usarthal.h"

typedef enum {USART_NORMALSPEED, USART_DOUBLESPEED} usart_doublespeed_t;

usart_status_t usart_init_port(volatile void* port,
								uint32_t sysclk_hz,
								uint32_t baudrate,
								usart_parity_t parity,
								usart_stopbits_t stopbits,
								usart_databits_t databits)
{
	volatile uint8_t* usart_port = port;

	if(usart_port != &UCSR0A && usart_port != &UCSR1A)
	{
		return USART_ERR;
	}

	volatile uint8_t* ucsrna_ptr = usart_port;
	volatile uint8_t* ucsrnb_ptr = ucsrna_ptr + 1u;
	volatile uint8_t* ucsrnc_ptr = ucsrna_ptr + 2u;

	uint8_t ucsrna = *ucsrna_ptr;
	uint8_t ucsrnb = *ucsrnb_ptr;
	uint8_t ucsrnc = *ucsrnc_ptr;
	/* Set up temporary "register" variables below ... */



	/* Finally, assign values to actual hardware registers */
	*ucsrna_ptr = ucsrna;
	*ucsrnb_ptr = ucsrnb;
	*ucsrnc_ptr = ucsrnc;
}
