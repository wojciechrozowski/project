#ifndef kernel_h
#define kernel_h

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
//x86.c
void outb(uint16_t port, uint8_t value);
uint8_t inb(uint16_t port);
uint16_t inw(uint16_t port);
//screen.c
#define BLACK		0
#define BLUE		1
#define GREEN		2
#define CYAN		3
#define RED			4
#define	MAGENTA		5
#define BROWN		6
#define L_GRAY		7
#define D_GRAY		8
#define L_BLUE		9
#define L_GREEN		10
#define L_CYAN		11
#define L_RED		12
#define	L_MAGENTA	13
#define YELLOW		14
#define WHITE		15

void clear_screen(void);
void set_cursor (uint8_t row, uint8_t col);
void scroll(void);
void set_background(uint8_t colour);
void set_foreground(uint8_t colour);
void screen_put(char sign);
void screen_write(char *string);
void set_background(uint8_t colour);
void set_foreground(uint8_t colour);
void screen_init();
void write_number(uint32_t n);
void write_dec(uint32_t n);
//string.c
int strlen (char *str);
void *memset(void *dst, int c, size_t n);
void * memcpy (void * dst, const void * src, size_t n);
//vsprintf.c
int vsprintf(char *buf, const char *fmt, va_list args);
//printk.c
int printk(const char *fmt, ...);
//paging.c

typedef uint32_t pte_t;
typedef uint32_t pde_t;

#define kernel_virtual_base 0xC0000000

pte_t entry_page_table[1024];
pde_t entry_page_directory[1024];

void *pdir;

//gdt.c

#define GDT_SIZE 5

struct gdt_entry
{
	uint16_t	limit_low;
	uint16_t	base_low;
	uint8_t		base_middle;
	uint8_t		access;
	uint8_t		granularity;
	uint8_t		base_high;
}__attribute__((packed));
typedef struct gdt_entry gdt_entry_t;

gdt_entry_t gdt_entries[GDT_SIZE];

struct gdt_pointer
{
	uint16_t limit;
	uint32_t base;
}__attribute__((packed));
typedef struct gdt_pointer gdt_ptr_t;

gdt_ptr_t gdt_ptr;

void init_gdt();
void set_gdt_gate(int32_t number, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity);
extern void load_gdt();

//load_gdt.s
extern void load_gdt(uint32_t addr);

//idt.c

struct idt_entry
{
	uint16_t base_low;
	uint16_t selector;
	uint8_t always0;
	uint8_t flags;
	uint16_t base_high;
} __attribute__((packed));

typedef struct idt_entry idt_entry_t;

idt_entry_t idt_entries[256];

struct idt_pointer
{
	uint16_t limit;
	uint32_t base;
}__attribute__((packed));

typedef struct idt_pointer idt_ptr_t;

idt_ptr_t idt_ptr;

void init_idt();
void idt_set_gate(uint8_t number, uint32_t base, uint16_t selector, uint8_t flags);


extern void load_idt();

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
#endif
