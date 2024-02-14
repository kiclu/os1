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

#include <riscv.h>

#define I (1UL << 63)

#define SSI 1
#define STI 5
#define SEI 9

extern void _user_trap_vec();
extern void _kernel_trap_vec();

void _trap_init() {
    w_stvec((uint64_t)_user_trap_vec);
    w_sie(r_sie() | SIE_SEIE | SIE_STIE | SIE_SSIE);
    w_sstatus(r_sstatus() | SSTATUS_SIE);
}

void _trap_init_hart() {
    w_stvec((uint64_t)_user_trap_vec);
    w_sie(r_sie() | SIE_SEIE | SIE_STIE | SIE_SSIE);
    w_sstatus(r_sstatus() | SSTATUS_SIE);
}

#include <printf.h>
#include <hart.h>

static int _intr_handler() {
    uint64_t scause = r_scause();
    switch(scause & 0xff) {
        case SSI: {

            struct hart* hart = (struct hart*)r_sscratch();
            switch(hart->id) {
                case 0: _kinfo("HART 0: timer interrupt\n"); break;
                case 1: _kinfo("HART 1: timer interrupt\n"); break;
            }

            w_sip(r_sip() & ~SIP_SSIP);
            return SSI;
        }
        case STI: {

            w_sip(r_sip() & ~SIP_STIP);
            return STI;
        }
        case SEI: {

            w_sip(r_sip() & ~SIP_SEIP);
            return SEI;
        }
    }
    return 0;
}

static void _user_trap_ret() {
    //intr_off();
    w_stvec((uint64_t)_user_trap_vec);
}

void _user_trap_handler() {

    w_stvec((uint64_t)_kernel_trap_vec);

    if(_intr_handler() == 0) {
        //intr_on();
        switch(r_scause()) {

        }
    }

    _user_trap_ret();
}
