#include <stdbool.h>
#include <stdint.h>
#include "screen.h"
#include "string.h"
#include "printk.h"
void kernel_main(void)
{
	screen_init();
	printk("Hello World!: 0x%x \n", 1234);
	while(true)
	{

	}
}
