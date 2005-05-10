/*
 *  convertions - APPLICATION-DESCRIPTION
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

#ifndef CONVERTIONS_H
#define CONVERTIONS_H

#include <stdio.h>

enum format { ENC_EUC, ENC_UCS4, ENC_UTF7, ENC_UTF8 };

typedef struct
{
	format from;
	format to;
} encoding;

char* encode(encoding form, char* value);

#endif
