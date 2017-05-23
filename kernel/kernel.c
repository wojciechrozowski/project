#include "kernel.h"

//extern uint32_t _MULTIBOOT_START_;
//uint32_t multiboot_start = (uint32_t)&_MULTIBOOT_START_;
//
//extern uint32_t _MULTIBOOT_END_;
//uint32_t multiboot_end = (uint32_t)&_MULTIBOOT_END_;
//
//extern uint32_t _TEXT_START_;
//uint32_t text_start = (uint32_t)&_TEXT_START_;
//
//extern uint32_t _TEXT_END_;
//uint32_t text_end = (uint32_t)&_TEXT_END_;
//
//extern uint32_t _RODATA_START_;
//uint32_t rodata_start = (uint32_t)&_RODATA_START_;
//
//extern uint32_t _RODATA_END_;
//uint32_t rodata_end = (uint32_t)&_RODATA_END_;
//
//extern uint32_t _DATA_START_;
//uint32_t data_start = (uint32_t)&_DATA_START_;
//
//extern uint32_t _DATA_END_;
//uint32_t data_end = (uint32_t)&_DATA_END_;
//
//extern uint32_t _COMMON_START_;
//uint32_t common_start = (uint32_t)&_COMMON_START_;
//
//extern uint32_t _COMMON_END_;
//uint32_t common_end = (uint32_t)&_COMMON_END_;
//
//extern uint32_t _BSS_START_;
//uint32_t bss_start = (uint32_t)&_BSS_START_;
//
//extern uint32_t _BSS_END_;
//uint32_t bss_end = (uint32_t)&_BSS_END_;

void kernel_main(void)
{
	screen_init();
//	printk("multiboot_start: 0x%x\n", multiboot_start);
//	printk("multiboot_end: 0x%x\n", multiboot_end);
//	printk("text_start: 0x%x\n", text_start);
//	printk("text_end: 0x%x\n", text_end);
//	printk("rodata_start: 0x%x\n", rodata_start);
//	printk("rodata_end: 0x%x\n", rodata_end);
//	printk("data_start: 0x%x\n", data_start);
//	printk("data_end: 0x%x\n", data_end);
//	printk("common_start: 0x%x\n", common_start);
//	printk("common_end: 0x%x\n", common_end);
//	printk("bss_start: 0x%x\n", bss_start);
//	printk("bss_end: 0x%x\n", bss_end);
	printk("loaded.\n");
	init_gdt();

}
