ENTRY(_start)
OUTPUT_FORMAT("elf32-i386", "elf32-i386", "elf32-i386")
OUTPUT_ARCH(i386)

SECTIONS {
   /* The kernel will live at 3GB + 1MB in the virtual
      address space, which will be mapped to 1MB in the
      physical address space. */
   . = 0xC0100000;

   .text : AT(0x100000) {
       *(.text)
       *(.rodata*)
   }

   .data : ALIGN (0x1000){
       *(.data)
   }

   .bss : {
       _sbss = .;
       *(COMMON)
       *(.bss)
       _ebss = .;
   }
}
