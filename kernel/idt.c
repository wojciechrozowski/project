#include "kernel.h"

void init_idt()
{
	idt_ptr.limit = (sizeof(idt_entry_t)*256)-1;
	idt_ptr.base = (uint32_t)&idt_entries;
	memset(&idt_entries, 0, sizeof(idt_entry_t)*256);

	idt_set_gate(0, (uint32_t) isr0, 0x08, 0x8E);

	load_idt((uint32_t) &idt_ptr);
}

void idt_set_gate(uint8_t number, uint32_t base, uint16_t selector, uint8_t flags)
{
	idt_entries[number].base_low = base & 0xFFFF;
	idt_entries[number].base_high = (base>>16) & 0xFFFF;

	idt_entries[number].selector = selector;
	idt_entries[number].always0 = 0;

	idt_entries[number].flags = flags;
}
