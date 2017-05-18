#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include "vsprintf.h"
#include "screen.h"

static char buf[1024];

int printk(const char *fmt, ...)
{
	va_list args;
	int i;

	va_start(args, fmt);
	i=vsprintf(buf, fmt, args);
	va_end(args);

	screen_write(buf);

	return i;
}
