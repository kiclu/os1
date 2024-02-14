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

#ifndef _OS1_CONTEXT_H_
#define _OS1_CONTEXT_H_

#include <types.h>

typedef struct reg {
    uint64_t    ra;
    uint64_t    sp;
    uint64_t    gp;
    uint64_t    tp;
    uint64_t    t0;
    uint64_t    t1;
    uint64_t    t2;
    uint64_t    s0;
    uint64_t    s1;
    uint64_t    a0;
    uint64_t    a1;
    uint64_t    a2;
    uint64_t    a3;
    uint64_t    a4;
    uint64_t    a5;
    uint64_t    a6;
    uint64_t    a7;
    uint64_t    s2;
    uint64_t    s3;
    uint64_t    s4;
    uint64_t    s5;
    uint64_t    s6;
    uint64_t    s7;
    uint64_t    s8;
    uint64_t    s9;
    uint64_t    s10;
    uint64_t    s11;
    uint64_t    t3;
    uint64_t    t4;
    uint64_t    t5;
    uint64_t    t6;
} reg_t;

typedef struct context {
    struct reg  reg;
    uint64_t    pc;
} context_t;

#endif//_OS1_CONTEXT_H_
