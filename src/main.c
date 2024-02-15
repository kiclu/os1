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

#include <hart.h>
#include <kinfo.h>
#include <printk.h>
#include <riscv.h>
#include <trap.h>
#include <types.h>
#include <uart.h>

static volatile int hart0_init_done = 0;

void _main() {
    if(HARTID == 0) {
        _uart_init();
        _printk_lock_init();
        _printk("OS1 kernel booting...\n");

        _trap_init();

        KINFO_TARGET("ksvinit.target");
        __sync_synchronize();
        hart0_init_done = 1;
    }
    else {
        while(!hart0_init_done);
        __sync_synchronize();
        _trap_init_hart();
    }

    for(;;);
}
