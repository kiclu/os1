/* Copyright (c)  2024 Nikola Lukić
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. */

#ifndef _OS1_TYPES_H_
#define _OS1_TYPES_H_

#define NULL                (void*)0

typedef unsigned long int   uint64_t;
typedef unsigned int        uint32_t;
typedef unsigned short int  uint16_t;
typedef unsigned char       uint8_t;

typedef signed long int     int64_t;
typedef signed int          int32_t;
typedef signed short int    int16_t;
typedef signed char         int8_t;

typedef unsigned long int   size_t;


typedef struct clint_context {
    uint64_t scratch0;
    uint64_t scratch1;
    uint64_t scratch2;
    uint64_t mtimecmp;
    uint64_t interval;
} clint_context_t;

#endif//_OS1_TYPES_H_
