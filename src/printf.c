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

#include <uart.h>

static void _uart_putstr(const char* str) {
    for(const char* i = str; *i; ++i) _uart_putc(*i);
}

#include <spinlock.h>

static struct spinlock printf_lk;

void _printf_lock_init() {
    _lock_init(&printf_lk, "printf_lk");
}

void _kinfo(const char* str) {
    _lock_acquire(&printf_lk);
    _uart_putstr("[INFO]: ");
    _uart_putstr(str);
    _lock_release(&printf_lk);
}

void _kwarn(const char* str) {
    _lock_acquire(&printf_lk);
    _uart_putstr("[WARNING]: ");
    _uart_putstr(str);
    _lock_release(&printf_lk);
}

void _kerr(const char* str) {
    _lock_acquire(&printf_lk);
    _uart_putstr("[ERROR]: ");
    _uart_putstr(str);
    _lock_release(&printf_lk);
}
