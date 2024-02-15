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

#include <clint.h>
#include <hart.h>
#include <riscv.h>
#include <types.h>

extern void     _main();
extern void     _timervec();
static void     _timer_init();

extern struct hart _hart[NHART];

void _start() {
    uint64_t mstatus = r_mstatus();
    mstatus &= ~MSTATUS_MPP_MASK;
    mstatus |= MSTATUS_MPP_S;
    w_mstatus(mstatus);

    w_mepc((uint64_t)_main);

    w_medeleg(0xffff);
    w_mideleg(0xffff);

    w_pmpaddr0(0x3fffffffffffffull);
    w_pmpcfg0(0xf);

    _hart[r_mhartid()].id = r_mhartid();
    w_sscratch((uint64_t)&_hart[r_mhartid()]);

    _timer_init();

    asm volatile("mret");
}

static struct clint_context cc[NHART];

void _timer_init() {
    uint64_t interval = 1000000;
    uint64_t mtime = *(uint64_t*)CLINT_MTIME;
    uint64_t mtimecmp = mtime + interval;
    *(uint64_t*)CLINT_MTIMECMP(HARTID) = mtimecmp;

    cc[HARTID].mtimecmp = CLINT_MTIMECMP(HARTID);
    cc[HARTID].interval = interval;
    w_mscratch((uint64_t)&cc[HARTID]);

    w_mtvec((uint64_t)_timervec);
    w_mstatus(r_mstatus() | MSTATUS_MIE);
    w_mie(r_mie() | MIE_MTIE);
}
