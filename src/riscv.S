# Copyright (c)  2024 Nikola Lukić
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

.section .text
.align 4

.global r_mvendorid
r_mvendorid:
    csrr    a0, mvendorid
    ret

.global r_marchid
r_marchid:
    csrr    a0, marchid
    ret

.global r_mimpid
r_mimpid:
    csrr    a0, mimpid
    ret

.global r_mhartid
r_mhartid:
    csrr    a0, mhartid
    ret

.global r_mconfigptr
r_mconfigptr:
    csrr    a0, mconfigptr
    ret

.global r_mstatus
r_mstatus:
    csrr    a0, mstatus
    ret

.global w_mstatus
w_mstatus:
    csrw    mstatus, a0
    ret

.global r_misa
r_misa:
    csrr    a0, misa
    ret

.global w_misa
w_misa:
    csrw    misa, a0
    ret

.global r_medeleg
r_medeleg:
    csrr    a0, medeleg
    ret

.global w_medeleg
w_medeleg:
    csrw    medeleg, a0
    ret

.global r_mideleg
r_mideleg:
    csrr    a0, mideleg
    ret

.global w_mideleg
w_mideleg:
    csrw    mideleg, a0
    ret

.global r_mie
r_mie:
    csrr    a0, mie
    ret

.global w_mie
w_mie:
    csrw    mie, a0
    ret

.global r_mtvec
r_mtvec:
    csrr    a0, mtvec
    ret

.global w_mtvec
w_mtvec:
    csrw    mtvec, a0
    ret

.global r_mcounteren
r_mcounteren:
    csrr    a0, mcounteren
    ret

.global w_mcounteren
w_mcounteren:
    csrw    mcounteren, a0
    ret

.global r_mscratch
r_mscratch:
    csrr    a0, mscratch
    ret

.global w_mscratch
w_mscratch:
    csrw    mscratch, a0
    ret

.global r_mepc
r_mepc:
    csrr    a0, mepc
    ret

.global w_mepc
w_mepc:
    csrw    mepc, a0
    ret

.global r_mcause
r_mcause:
    csrr    a0, mcause
    ret

.global w_mcause
w_mcause:
    csrw    mcause, a0
    ret

.global r_mtval
r_mtval:
    csrr    a0, mtval
    ret

.global w_mtval
w_mtval:
    csrw    mtval, a0
    ret

.global r_menvcfg
r_menvcfg:
    csrr    a0, menvcfg
    ret

.global w_menvcfg
w_menvcfg:
    csrw    menvcfg, a0
    ret

.global r_mseccfg
r_mseccfg:
    csrr    a0, mseccfg
    ret

.global w_mseccfg
w_mseccfg:
    csrw    mseccfg, a0
    ret

.global r_pmpcfg0
r_pmpcfg0:
    csrr    a0, pmpcfg0
    ret

.global w_pmpcfg0
w_pmpcfg0:
    csrw    pmpcfg0, a0
    ret

.global r_pmpcfg1
r_pmpcfg1:
    csrr    a0, pmpcfg1
    ret

.global w_pmpcfg1
w_pmpcfg1:
    csrw    pmpcfg1, a0
    ret

.global r_pmpaddr0
r_pmpaddr0:
    csrr    a0, pmpaddr0
    ret

.global w_pmpaddr0
w_pmpaddr0:
    csrw    pmpaddr0, a0
    ret

.global r_sstatus
r_sstatus:
    csrr    a0, sstatus
    ret

.global w_sstatus
w_sstatus:
    csrw    sstatus, a0
    ret

.global r_sie
r_sie:
    csrr    a0, sie
    ret

.global w_sie
w_sie:
    csrw    sie, a0
    ret

.global r_stvec
r_stvec:
    csrr    a0, stvec
    ret

.global w_stvec
w_stvec:
    csrw    stvec, a0
    ret

.global r_scounteren
r_scounteren:
    csrr    a0, scounteren
    ret

.global w_scounteren
w_scounteren:
    csrw    scounteren, a0
    ret

.global r_sscratch
r_sscratch:
    csrr    a0, sscratch
    ret

.global w_sscratch
w_sscratch:
    csrw    sscratch, a0
    ret

.global r_sepc
r_sepc:
    csrr    a0, sepc
    ret

.global w_sepc
w_sepc:
    csrw    sepc, a0
    ret

.global r_scause
r_scause:
    csrr    a0, scause
    ret

.global w_scause
w_scause:
    csrw    scause, a0
    ret

.global r_stval
r_stval:
    csrr    a0, stval
    ret

.global w_stval
w_stval:
    csrw    stval, a0
    ret

.global r_sip
r_sip:
    csrr    a0, sip
    ret

.global w_sip
w_sip:
    csrw    sip, a0
    ret

.global r_satp
r_satp:
    csrr    a0, satp
    ret

.global w_satp
w_satp:
    csrw    satp, a0
    ret

#.global intr_get
#    csrr    a0, sstatus
#    sll     a0, a0, 62
#    srl     a0, a0, 63
#    ret
