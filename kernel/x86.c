#include "x86.h"

void outb(uint16_t port, uint8_t value)
{
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}
uint8_t inb(uint16_t port)
{
	uint8_t return_value;
	asm volatile("inb %1, %0" : "=a" (return_value) : "dN" (port));
	return return_value;
}
uint16_t inw(uint16_t port)
{
	uint16_t return_value;
	asm volatile("inw %1, %0" : "=a" (return_value) : "dN" (port));
	return return_value;
}
