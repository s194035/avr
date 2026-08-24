#ifndef usart_hal
#define usart_hal

typedef struct usart_msg_t usart_msg_t;

typedef enum
{
	USART_OK,
	USART_BAUD_ERR,
	USART_UNEXPECTED
} usart_status_t;

typedef enum {USART_PARITY_NONE,USART_PARITY_EVEN, USART_PARITY_ODD} usart_parity_t;
typedef enum {USART_STOPBITS_1,USART_STOPBITS_2} usart_stopbits_t;
typedef enum {USART_DATABITS_5, USART_DATABITS_6, USART_DATABITS_7, USART_DATABITS_8} usart_databits_t;

#endif
