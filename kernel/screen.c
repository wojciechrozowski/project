#include <stdint.h>
#include <stdbool.h>
#include "screen.h"
#include "x86.h"
uint16_t *video_memory = (uint16_t *) 0xB8000;
uint8_t screen_x = 0;
uint8_t screen_y = 0;
uint8_t back;
uint8_t fore;
void clear_screen(void)
{
	for(int i = 0; i<80; i++)
	{
		for(int j = 0; j<25; j++)
		{
			video_memory[(j*80)+i]=((back<<4)|(fore&0x0F))<<8 | ' ';
		}
	}
}

void set_cursor (uint8_t row, uint8_t col)
{
	uint16_t position = (row*80)+col;
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (position&0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((position>>8)&0xFF));
}

void scroll(void)
{
	for(int j=0;j<24;j++)
	{
		for(int i = 0; i<80; i++)
		{
				video_memory[j*80+i]=video_memory[j*80+i+80];
		}
	}
	for(int i = 0; i<80; i++)
	{
		video_memory[1920+i] = (back<<4 | (fore&0xF))<<8 | ' ';
	}
	screen_y = 24;
}

void screen_put(char sign)
{
	if (sign=='\n')
	{
		screen_y++;
		screen_x=0;
	}
	if(screen_x >= 80)
	{
		screen_x=0;
		screen_y++;
	}

	if(screen_y>=25)
	{
		scroll();
	}

	if(sign>=' ')
	{
		video_memory[(screen_y*80)+screen_x] = (back<<4 | (fore&0xF))<<8 | sign;
		screen_x++;
	}
	set_cursor(screen_y, screen_x);

}

void set_background(uint8_t colour)
{
	back = colour;
}

void set_foreground(uint8_t colour)
{
	fore = colour;
}

void screen_init()
{
	back = BLACK;
	fore = L_GRAY;
	clear_screen();
	set_cursor(0, 0);
	screen_x=0;
	screen_y=0;
}

void screen_write(char *string)
{
	int i = 0;
	while(string[i])
	{
		screen_put(string[i]);
		i++;
	}
}

void write_number(uint32_t n)
{
	switch(n)
	{
	case 0:
		screen_put('0');
		break;
	case 1:
		screen_put('1');
		break;
	case 2:
		screen_put('2');
		break;
	case 3:
		screen_put('3');
		break;
	case 4:
		screen_put('4');
		break;
	case 5:
		screen_put('5');
		break;
	case 6:
		screen_put('6');
		break;
	case 7:
		screen_put('7');
		break;
	case 8:
		screen_put('8');
		break;
	case 9:
		screen_put('9');
		break;
	default:
		screen_write("nan");
	}
}

void write_dec(uint32_t n)
{
	if(n==0)
		return;
	write_dec(n/10);
	write_number(n%10);

}
