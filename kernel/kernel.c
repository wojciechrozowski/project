#include <stdbool.h>
#include <stdint.h>
#include "screen.h"
void kernel_main(void)
{
	screen_init();
	screen_write("Hello world!\n");
	while(true)
	{

	}
}
