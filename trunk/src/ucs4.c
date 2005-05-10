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

#include "ucs4.h"

void putucs4char(int c)
{
	putchar (c >> 24 & 0xFF); /* group */
	putchar (c >> 16 & 0xFF); /* plane */
	putchar (c >>  8 & 0xFF); /* row   */
	putchar (c       & 0xFF); /* cell  */
}
