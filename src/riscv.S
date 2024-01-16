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
    csrr a0, mvendorid
    ret

.global r_misa
r_misa:
    csrr a0, misa
    ret

.global r_mimpid
r_mimpid:
    csrr a0, mimpid
    ret

.global r_mhartid
r_mhartid:
    csrr a0, mhartid
    ret

.global r_mconfigptr
r_mconfigptr:
    csrr a0, mconfigptr
    ret

.global r_mstatus
r_mstatus:
    csrr a0, mstatus
    ret

.global w_mstatus
w_mstatus:
    csrw mstatus, a0
    ret

.global r_misa
r_misa:
    csrr a0, misa
    ret

.global w_misa
w_misa:
    csrw misa, a0
    ret

.global r_medeleg
r_medeleg:
    csrr a0, medeleg
    ret

.global w_medeleg
w_medeleg:
    csrw medeleg, a0
    ret

.global r_mideleg
r_mideleg:
    csrr a0, mideleg
    ret

.global w_mideleg
w_mideleg:
    csrw mideleg, a0
    ret

.global r_mie
r_mie:
    csrr a0, mie
    ret

.global w_mie
w_mie:
    csrw mie, a0
    ret

.global r_mtvec
r_mtvec:
    csrr a0, mtvec
    ret

.global w_mtvec
w_mtvec:
    csrw mtvec, a0
    ret

.global r_mcounteren
r_mcounteren:
    csrr a0, mcounteren
    ret

.global w_mcounteren
w_mcounteren:
    csrw mcounteren, a0
    ret
