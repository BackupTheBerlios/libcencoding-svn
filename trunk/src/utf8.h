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

#ifndef UTF8_H
#define UTF8_H

typedef struct
{
	unsigned int length; // how many bytes are used;
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
	unsigned char byte4;
} utf8_t;

void pututf8char(unsigned int c);
utf8_t chartoutf8(unsigned int c);
void printutf8(utf8_t val);

#endif
