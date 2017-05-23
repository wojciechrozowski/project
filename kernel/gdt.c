#include "kernel.h"

void init_gdt()
{
	gdt_ptr.limit = (sizeof(gdt_entry_t)*GDT_SIZE)-1;
	gdt_ptr.base = (uint32_t)&gdt_entries;

	set_gdt_gate(0, 0, 0, 0, 0);
	set_gdt_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	set_gdt_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	set_gdt_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
	set_gdt_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
    load_gdt((uint32_t) &gdt_ptr );

}

void set_gdt_gate(int32_t number, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity)
{
	gdt_entries[number].base_low = (base & 0xFFFF);
	gdt_entries[number].base_middle = (base >> 16) & 0xFF;
	gdt_entries[number].base_high = (base >> 24) & 0xFF;

	gdt_entries[number].limit_low   = (limit & 0xFFFF);
	gdt_entries[number].granularity = (limit >> 16) & 0x0F;

	gdt_entries[number].granularity |= granularity & 0xF0;
	gdt_entries[number].access = access;

}
gdt_ptr_t gdt_ptr;
