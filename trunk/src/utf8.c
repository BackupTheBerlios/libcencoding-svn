/*
 *  UTF8 - A simple utf8 encoding lib
 *
 *  Copyright (c) 2005 Daniel Ulbricht, <daniel.ulbricht@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Found
 */

/**
 * WARNING: This code is in a very very early version.
 */

#include <stdio.h>

#include "utf8.h"

#define UTF8_DEBUG

void pututf8char(unsigned int c)
{
	if (c < 0x80)
	{
#ifdef UTF8_DEBUG
		printf("1 byte character: ");
#endif
    		putchar (c);				/* ASCII character */
  	}
  	else if (c < 0x800)
	{
#ifdef UTF8_DEBUG
		printf("2 byte character: ");
#endif
    		putchar (0xC0 | c>>6);
    		putchar (0x80 | c & 0x3F);
  	}
  	else if (c < 0x10000)
	{
#ifdef UTF8_DEBUG
		printf("3 byte character: ");
#endif
    		putchar (0xE0 | c>>12);
    		putchar (0x80 | c>>6 & 0x3F);
    		putchar (0x80 | c & 0x3F);
  	}
  	else if (c < 0x200000)
	{
#ifdef UTF8_DEBUG
		printf("4 byte character: ");
#endif
    		putchar (0xF0 | c>>18);
    		putchar (0x80 | c>>12 & 0x3F);
    		putchar (0x80 | c>>6 & 0x3F);
    		putchar (0x80 | c & 0x3F);
  	}
}

utf8_t chartoutf8(unsigned int c)
{
	utf8_t utfcharacter;

	if (c < 0x80)
	{
		utfcharacter.length = 1;
		utfcharacter.byte1 = (c);				/* ASCII character */
  	}
  	else if (c < 0x800)							/* c = 0..127 */
	{
		utfcharacter.length = 2;
		utfcharacter.byte1 = (0xC0 | c>>6);
		utfcharacter.byte2 = (0x80 | c & 0x3F);
  	}
  	else if (c < 0x10000)						/* c = 128..65536 */
	{
		utfcharacter.length = 3;
		utfcharacter.byte1 = (0xE0 | c>>12);
		utfcharacter.byte2 = (0x80 | c>>6 & 0x3F);
		utfcharacter.byte3 = (0x80 | c & 0x3F);
  	}
  	else if (c < 0x200000)						/* c = 65537..*/
	{
		utfcharacter.length = 4;
		utfcharacter.byte1 = (0xF0 | c>>18);
		utfcharacter.byte2 = (0x80 | c>>12 & 0x3F);
		utfcharacter.byte3 = (0x80 | c>>6 & 0x3F);
		utfcharacter.byte4 = (0x80 | c & 0x3F);
  	}

	return utfcharacter;
}

/**
 * \brief print out an utf8 value as 1-4 chars.
 *
 * \param val: the value which should be printed out.
 */
void printutf8(utf8_t val)
{
#ifdef UTF8_DEBUG
	printf("length of characer in bytes: %i\n",val.length);
#endif
}
