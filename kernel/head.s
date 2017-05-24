#include "kernel.h"

.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)


.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .text
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM


.global _start
_start = entry - 0xC0000000

.global entry

entry:
	movl $(entry_page_directory), %ecx
	subl $0xC0000000, %ecx
	movl %ecx, %cr3

	movl %cr0, %ecx
	orl $0x80000001, %ecx
	movl %ecx, %cr0
	mov $stack_top, %esp

	movl $(entry_page_directory), %ecx
	movl $0, (%ecx)
	invlpg (0)

	mov $kernel_main, %ecx
	jmp *%ecx
	#call kernel_main

	cli
1:	hlt
	jmp 1b

.size _start, . - _start
