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

#include <printk.h>

#include <spinlock.h>
#include <types.h>
#include <uart.h>

static struct spinlock printk_lk;

void _printk_lock_init() {
    _lock_init(&printk_lk, "printk_lk");
}

static const char digits_lowercase[] = "0123456789abcdef";
static const char digits_uppercase[] = "0123456789ABCDEF";

static void _printk_int32(int32_t x) {

}

static void _printk_uint_b10(uint64_t x) {
    if(x == 0) { _uart_putc('0'); return; }

    uint8_t buf[32];
    int i;

    for(i = 0; x > 0; x /= 10) buf[i++] = '0' + x % 10;

    while(i > 0) _uart_putc(buf[--i]);
}

static void _printk_uint_b16_lc(uint64_t x) {
    if(x == 0) { _uart_putc('0'); return; }

    uint8_t buf[32];
    int i;

    for(i = 0; x > 0; x >>= 4) buf[i++] = x & 0xf;

    while(i > 0) _uart_putc(digits_lowercase[buf[--i]]);
}

static void _printk_uint_b16_uc(uint64_t x) {
    if(x == 0) { _uart_putc('0'); return; }

    uint8_t buf[32];
    size_t i;

    for(i = 0; x > 0; x >>= 4) buf[i++] = x & 0xf;

    while(i > 0) _uart_putc(digits_uppercase[buf[--i]]);
}

void _printk_char(char c) { _uart_putc(c); }

void _printk_str(const char* p) {
    while(*p) _uart_putc(*p++);
}

void _printk_ptr(uint64_t ptr) {
    _printk_str("0x");
    _printk_uint_b16_lc(ptr);
}

void _printk(const char* fmt, ...) {
    uint64_t* varg;
    asm volatile("mv %0, s0" : "=r"(varg));

    _lock_acquire(&printk_lk);
    while(*fmt) {
        if(*fmt != '%') _uart_putc(*fmt++);
        else {
            switch(fmt[1]) {
                case 'd': _printk_int32(*++varg); fmt += 2; break;
                case 'i': _printk_int32(*++varg); fmt += 2; break;
                case 'u': _printk_uint_b10(*++varg); fmt += 2; break;
                case 'x': _printk_uint_b16_lc(*++varg); fmt += 2; break;
                case 'X': _printk_uint_b16_uc(*++varg); fmt += 2; break;
                case 'c': _printk_char(*++varg); fmt += 2; break;
                case 's': _printk_str((const char*)*++varg); fmt += 2; break;
                case 'p': _printk_ptr(*++varg); fmt += 2; break;
                case '%': _printk_char('%'); fmt += 2; break;

                default: _uart_putc(*fmt++);
            }
        }
    }
    _lock_release(&printk_lk);
}
