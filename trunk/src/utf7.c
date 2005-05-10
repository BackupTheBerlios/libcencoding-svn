/*
 *  libcencoding - APPLICATION-DESCRIPTION
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

#include <stdio.h>

#include "utf7.h"

void pututf7char(int c)
{
	if (c == '+') { 
		putchar('+');
		putchar('-');
	}
	else if (c < 0x80) {
		putchar(c);
	}
	else if (c < 0x10000) {
		putchar('+');
		putchar(base64[c>>10&63]);
		putchar(base64[c>>4&63]);
		putchar(base64[c<<2&63]);
		putchar('-');
	}
	else if (c < 0x110000) {
		c = 0xD7C0DC00 + (c >> 10 << 16 | c & 0x3FF);
		putchar('+');
		putchar(base64[c>>26&63]);
		putchar(base64[c>>20&63]);
		putchar(base64[c>>14&63]);
		putchar(base64[c>>8&63]);
		putchar(base64[c>>2&63]);
		putchar(base64[c<<4&63]);
		putchar('-');
	}
}
