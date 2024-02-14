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

#ifndef _OS1_RISCV_H_
#define _OS1_RISCV_H_

#define MSTATUS_SIE         (1 << 1)
#define MSTATUS_MIE         (1 << 3)
#define MSTATUS_SPIE        (1 << 5)
#define MSTATUS_MPIE        (1 << 7)
#define MSTATUS_SPP         (1 << 8)

#define MSTATUS_MPP_MASK    (0b11 << 11)
#define MSTATUS_MPP_S       (0b01 << 11)

#define MIP_SSIP            (1 << 1)
#define MIP_MSIP            (1 << 3)
#define MIP_STIP            (1 << 5)
#define MIP_MTIP            (1 << 7)
#define MIP_SEIP            (1 << 9)
#define MIP_MEIP            (1 << 11)

#define MIE_SSIE            (1 << 1)
#define MIE_MSIE            (1 << 3)
#define MIE_STIE            (1 << 5)
#define MIE_MTIE            (1 << 7)
#define MIE_SEIE            (1 << 9)
#define MIE_MEIE            (1 << 11)

#define SSTATUS_SIE         (1 << 1)
#define SSTATUS_SPIE        (1 << 5)
#define SSTATUS_SPP         (1 << 8)

#define SIP_SSIP            (1 << 1)
#define SIP_STIP            (1 << 5)
#define SIP_SEIP            (1 << 9)

#define SIE_SSIE            (1 << 1)
#define SIE_STIE            (1 << 5)
#define SIE_SEIE            (1 << 9)

#include <types.h>

uint64_t    r_mvendorid();
uint64_t    r_marchid();
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

uint64_t    r_mscratch();
void        w_mscratch(uint64_t);

uint64_t    r_mepc();
void        w_mepc(uint64_t);

uint64_t    r_mcause();
void        w_mcause(uint64_t);

uint64_t    r_mtval();
void        w_mtval(uint64_t);

uint64_t    r_mip();
void        w_mip(uint64_t);

uint64_t    r_menvcfg();
void        w_menvcfg(uint64_t);

uint64_t    r_mseccfg();
void        w_mseccfg(uint64_t);

uint64_t    r_pmpcfg0();
void        w_pmpcfg0(uint64_t);

// ...

uint64_t    r_pmpaddr0();
void        w_pmpaddr0(uint64_t);

uint64_t    r_sstatus();
void        w_sstatus(uint64_t);

uint64_t    r_sie();
void        w_sie(uint64_t);

uint64_t    r_stvec();
void        w_stvec(uint64_t);

uint64_t    r_scounteren();
void        w_scounteren(uint64_t);

uint64_t    r_senvcfg();
void        w_senvcfg(uint64_t);

uint64_t    r_sscratch();
void        w_sscratch(uint64_t);

uint64_t    r_sepc();
void        w_sepc(uint64_t);

uint64_t    r_scause();
void        w_scause(uint64_t);

uint64_t    r_stval();
void        w_stval(uint64_t);

uint64_t    r_sip();
void        w_sip(uint64_t);

uint64_t    r_satp();
void        w_satp(uint64_t);

inline uint64_t     intr_get() { return (r_sstatus() >> 1) & 0b1; }
inline void         intr_on()  { w_sstatus(r_sstatus() |  0b10ul); }
inline void         intr_off() { w_sstatus(r_sstatus() & ~0b10ul); }

#endif//_OS1_RISCV_H
