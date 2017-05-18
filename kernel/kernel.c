#include "kernel.h"

void kernel_main(void)
{
	screen_init();
	printk("Hello World!: 0x%x \n", 1234);
	printk("Black is not Black\rWhite\n");
	printk("HELLO\tHOW ARE YOU\n");
}
