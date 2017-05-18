/* The bootloader will look at this image and start execution at the symbol
   designated as the entry point. */
ENTRY(_start)

/* Tell where the various sections of the object files will be put in the final
   kernel image. */
SECTIONS
{
	/* Begin putting sections at 1 MiB, a conventional place for kernels to be
	   loaded at by the bootloader. */
	. = 1M;

	/* First put the multiboot header, as it is required to be put very early
	   early in the image or the bootloader won't recognize the file format.
	   Next we'll put the .text section. */
	.text BLOCK(4K) : ALIGN(4K)
	{
		_MULTIBOOT_START_ = .;
		*(.multiboot)
		_MULTIBOOT_END_ = .;
		_TEXT_START_ = .;
		*(.text)
		_TEXT_END_ = .;
	}

	/* Read-only data. */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
	    _RODATA_START_ = .;
		*(.rodata)
		_RODATA_END_ = .;
	}

	/* Read-write data (initialized) */
	.data BLOCK(4K) : ALIGN(4K)
	{
		_DATA_START_ = .;
		*(.data)
		_DATA_END_ = .;
	}

	/* Read-write data (uninitialized) and stack */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		_COMMON_START_ = .;
		*(COMMON)
		_COMMON_END_ = .;
		_BSS_START_ = .;
		*(.bss)
		_BSS_END_ = .;
	}

	/* The compiler may produce other sections, by default it will put them in
	   a segment with the same name. Simply add stuff here as needed. */
}