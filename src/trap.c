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

#include <hart.h>
#include <kinfo.h>

#define I (1UL << 63)

#define SSI 1
#define STI 5
#define SEI 9

#define INSN_ADDRESS_MISALIGNED     0
#define INSN_ACCESS_FAULT           1
#define INSN_ILLEGAL                2
#define BREAKPOINT                  3
#define LD_ADDR_MISALIGNED          4
#define LD_ACCESS_FAULT             5
#define ST_ADDR_MISALIGNED          6
#define ST_ACCESS_FAULT             7
#define ECALL_U                     8
#define ECALL_S                     9
#define ECALL_M                     11
#define INSN_PG_FAULT               12
#define LD_PG_FAULT                 13
#define ST_PG_FAULT                 15

extern void _user_trap_vec();
extern void _kernel_trap_vec();

void _trap_init() {
    KINFO_STARTING("intr.service");
    w_stvec((uint64_t)_user_trap_vec);
    w_sie(r_sie() | SIE_SEIE | SIE_STIE | SIE_SSIE);
    w_sstatus(r_sstatus() | SSTATUS_SIE);
    KINFO_STARTED("intr.service");
}

void _trap_init_hart() {
    w_stvec((uint64_t)_user_trap_vec);
    w_sie(r_sie() | SIE_SEIE | SIE_STIE | SIE_SSIE);
    w_sstatus(r_sstatus() | SSTATUS_SIE);
}

static int _intr_handler() {
    uint64_t scause = r_scause();
    if(!(scause & I)) return scause;
    switch(scause & 0xff) {
        case SSI: {

            w_sip(r_sip() & ~SIP_SSIP);
            return 0;
        }
        case STI: {

            w_sip(r_sip() & ~SIP_STIP);
            return 0;
        }
        case SEI: {

            w_sip(r_sip() & ~SIP_SEIP);
            return 0;
        }
    }
    return scause;
}

static void _panic(const char* cause) {
    KINFO_PANIC(cause);
    for(;;);
}

static void _user_trap_ret() {
    //intr_off();
    w_stvec((uint64_t)_user_trap_vec);
}

void _user_trap_handler() {
    w_stvec((uint64_t)_kernel_trap_vec);

    uint64_t scause;

    if((scause = _intr_handler())) {
        //intr_on();
        switch(scause) {
            case INSN_ADDRESS_MISALIGNED: {
                _panic("INSN_ADDR_MISALIGNED");
            } break;

            case INSN_ACCESS_FAULT: {
                _panic("INSN_ACCESS_FAULT");
            } break;

            case INSN_ILLEGAL: {
                _panic("INSN_ILLEGAL");
            } break;

            case BREAKPOINT: {
                _panic("BREAKPOINT");
            } break;

            case LD_ADDR_MISALIGNED: {
                _panic("LD_ADDR_MISALIGNED");
            } break;

            case LD_ACCESS_FAULT: {
                _panic("LD_ACCESS_FAULT");
            } break;

            case ST_ADDR_MISALIGNED: {
                _panic("ST_ADDR_MISALIGNED");
            } break;

            case ST_ACCESS_FAULT: {
                _panic("ST_ACCESS_FAULT");
            } break;

            case ECALL_U: {
                _panic("ECALL_U");
            } break;

            case ECALL_S: {
                w_sstatus(r_sstatus() & ~SSTATUS_SPP);
            } break;

            case ECALL_M: {
                _panic("ECALL_M");
            } break;

            case INSN_PG_FAULT: {
                _panic("INSN_PG_FAULT");
            } break;

            case LD_PG_FAULT: {
                _panic("LD_PG_FAULT");
            } break;

            case ST_PG_FAULT: {
                _panic("ST_PG_FAULT");
            } break;

            default: {
                _panic("UNRECOGNIZED_EXCEPTION_CODE");
            } break;
        }
        w_sepc(r_sepc() + 4);
    }

    _user_trap_ret();
}
