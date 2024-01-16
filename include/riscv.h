/* Copyright (c)  2024 Nikola Lukić
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. */

#ifndef _OS1_RISCV_H_
#define _OS1_RISCV_H_

#include <types.h>

uint64_t    r_mvendorid();
uint64_t    r_misa();
uint64_t    r_mimpid();
uint64_t    r_mhartid();
uint64_t    r_mconfigptr();

uint64_t    r_mstatus();
void        w_mstatus(uint64_t);

uint64_t    r_misa();
void        w_misa(uint64_t);

uint64_t    r_medeleg();
void        w_medeleg(uint64_t);

uint64_t    r_mideleg();
void        w_mideleg(uint64_t);

uint64_t    r_mie();
void        w_mie(uint64_t);

uint64_t    r_mtvec();
void        w_mtvec(uint64_t);

uint64_t    r_mcounteren();
void        w_mcounteren(uint64_t);

#endif//_OS1_RISCV_H
