#include <avr/io.h>
#include <avr/boot.h>
#include <stdint.h>

#define BOOT_SENTINEL 0xFFu
#define BUFFER_SZ 32
#define HALF_BUFFER_SZ (BUFFER_SZ / 2)
uint8_t cmd = 0;

static void poll(void)
{
	while(counter < 200ms)
	{
		if(usart_avaliable() > 0)
		{
			cmd = usart_rx();
			return;
		}
	}
}

int main(void)
{
	sei();
	poll();
	if(cmd == BOOT_SENTINEL)
	{
		uint8_t buffer1[HALF_BUFFER_SZ];
		uint8_t buffer2[HALF_BUFFER_SZ];
		bool filling_buffer1 = true;

		while()

	}
	cli();
	boot_rww_enable();
	asm volatile "jmp(0x0000");
	return 0;
}
