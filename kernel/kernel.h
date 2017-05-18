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

pte_t entry_page_table[1024];
pde_t entry_page_directory[1024];

void *pdir;


#endif
