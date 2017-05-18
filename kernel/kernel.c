#include "kernel.h"

void kernel_main(void)
{
	screen_init();
	printk("Hello World!: %d \n", 1234);

}
