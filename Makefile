AS	:=	nasm
CC  :=	i686-elf-gcc
LD	:=	i686-elf-ld
EMU	:=	qemu-system-i386

ASFLAGS	:= -felf32
CFLAGS	:= -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS :=-ffreestanding -O2 -nostdlib -lgcc

SRCFILES := $(shell find kernel -type f -name "*.c" -o -name "*.s")
OBJECTS  :=$(SRCFILES:.c=.o)
OBJECTS  :=$(OBJECTS:.s=.o) 
OBJECTS  := $(OBJECTS)

all: $(OBJECTS) link test

.asm.o:
	@$(AS) $(ASFLAGS) -o $*.o $<
.c.o:
	$(CC) $(CFLAGS) -c -o $*.o $<
link:
	$(CC) -T link.ld -o kernel.elf $(LDFLAGS) $(OBJECTS)
test:
	$(EMU) -kernel kernel.elf
clean:
	rm $(OBJECTS) kernel.elf		