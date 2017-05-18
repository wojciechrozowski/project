#ifndef SCREEN_H
#define SCREEN_H

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
void write_number(uint32_t n);
void write_dec(uint32_t n);

#endif
