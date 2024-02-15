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

#include <spinlock.h>

#include <hart.h>
#include <riscv.h>

static void __push_off() {
    int intena = intr_get();

    intr_off();
    if(HART->noff == 0) HART->intena = intena;
    HART->noff += 1;
}

static void __pop_off() {
    HART->noff -= 1;
    if(HART->noff == 0 && HART->intena) intr_on();
}

void _lock_init(struct spinlock* lk, char* name) {
    lk->locked = 0;
    lk->name = name;
    lk->hart = HART;
}

void _lock_acquire(struct spinlock* lk) {
    __push_off();
    while(__sync_lock_test_and_set(&lk->locked, 1) != 0);
    __sync_synchronize();
    lk->hart = HART;
}

void _lock_release(struct spinlock* lk) {
    lk->hart = NULL;
    __sync_synchronize();
    __sync_lock_release(&lk->locked);
    __pop_off();
}
