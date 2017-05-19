AS	:=	i686-elf-as
CC  :=	i686-elf-gcc
LD	:=	i686-elf-ld
EMU	:=	qemu-system-i386

ASFLAGS	:= 
CFLAGS	:= -std=gnu99 -ffreestanding -O2 -Wall -Wextra 
LDFLAGS :=-ffreestanding -O2 -nostdlib -lgcc

SRCFILES := $(shell find kernel -type f -name "*.c" -o -name "*.s")
OBJECTS  :=$(SRCFILES:.c=.o)
OBJECTS  :=$(OBJECTS:.s=.o) 
OBJECTS  := $(OBJECTS)

all: $(OBJECTS) link test
debug: $(OBJECTS) link test-debug
.asm.o:
	@$(AS) $(ASFLAGS) -o $*.o $<
.c.o:
	$(CC) $(CFLAGS) -c -o $*.o $<
link:
	$(CC) -T link.ld -o kernel.elf $(LDFLAGS) $(OBJECTS)
test:
	$(EMU) -kernel kernel.elf
	
strip:
	objcopy --only-keep-debug kernel.elf kernel.sym	
	objcopy --strip-debug kernel.elf
	
test-debug:
	$(EMU) -S -s -kernel kernel.elf
clean:
	rm $(OBJECTS) kernel.elf		