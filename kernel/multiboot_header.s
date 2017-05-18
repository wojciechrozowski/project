MULTIBOOT_ALIGN 		equ 	1<<0
MULTIBOOT_MEMORY_INFO 	equ 	1<<1
MULTIBOOT_FLAGS			equ		MULTIBOOT_ALIGN | MULTIBOOT_FLAGS
MULTIBOOT_MAGIC			equ		0x1BADB002
MULTIBOOT_CHECKSUM		equ		-(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

section .multiboot
align 4
	dd MULTIBOOT_MAGIC
	dd MULTIBOOT_FLAGS
	dd MULTIBOOT_CHECKSUM

section .bss
align 4
stack_bottom:
resb 16384
stack_top:

section .text

global _start
_start:
	mov esp, stack_top
	extern kernel_main
	extern pdir
	mov ecx, [pdir]
	mov cr3, ecx


	mov ecx, cr0
	or ecx, 0x80000000
	mov cr0, ecx

	call kernel_main

	cli
.1:	hlt
jmp .1
.end:
