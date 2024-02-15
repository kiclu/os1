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

.global _user_trap_vec
.global _kernel_trap_vec
.align 4

.extern _user_trap_handler

_user_trap_vec:
    csrrw   t6,  sscratch, t6

    sd      ra,  0x00(t6)
    sd      sp,  0x08(t6)
    sd      gp,  0x10(t6)
    sd      tp,  0x18(t6)
    sd      t0,  0x20(t6)
    sd      t1,  0x28(t6)
    sd      t2,  0x30(t6)
    sd      s0,  0x38(t6)
    sd      s1,  0x40(t6)
    sd      a0,  0x48(t6)
    sd      a1,  0x50(t6)
    sd      a2,  0x58(t6)
    sd      a3,  0x60(t6)
    sd      a4,  0x68(t6)
    sd      a5,  0x70(t6)
    sd      a6,  0x78(t6)
    sd      a7,  0x80(t6)
    sd      s2,  0x88(t6)
    sd      s3,  0x90(t6)
    sd      s4,  0x98(t6)
    sd      s5,  0xa0(t6)
    sd      s6,  0xa8(t6)
    sd      s7,  0xb0(t6)
    sd      s8,  0xb8(t6)
    sd      s9,  0xc0(t6)
    sd      s10, 0xc8(t6)
    sd      s11, 0xd0(t6)
    sd      t3,  0xd8(t6)
    sd      t4,  0xe0(t6)
    sd      t5,  0xe8(t6)

    mv      t5,  t6
    csrrw   t6,  sscratch, t6
    sd      t6,  0xf0(t5)

    call    _user_trap_handler

    csrr    t6, sscratch

    ld      ra,  0x00(t6)
    ld      sp,  0x08(t6)
    ld      gp,  0x10(t6)
    ld      tp,  0x18(t6)
    ld      t0,  0x20(t6)
    ld      t1,  0x28(t6)
    ld      t2,  0x30(t6)
    ld      s0,  0x38(t6)
    ld      s1,  0x40(t6)
    ld      a0,  0x48(t6)
    ld      a1,  0x50(t6)
    ld      a2,  0x58(t6)
    ld      a3,  0x60(t6)
    ld      a4,  0x68(t6)
    ld      a5,  0x70(t6)
    ld      a6,  0x78(t6)
    ld      a7,  0x80(t6)
    ld      s2,  0x88(t6)
    ld      s3,  0x90(t6)
    ld      s4,  0x98(t6)
    ld      s5,  0xa0(t6)
    ld      s6,  0xa8(t6)
    ld      s7,  0xb0(t6)
    ld      s8,  0xb8(t6)
    ld      s9,  0xc0(t6)
    ld      s10, 0xc8(t6)
    ld      s11, 0xd0(t6)
    ld      t3,  0xd8(t6)
    ld      t4,  0xe0(t6)
    ld      t5,  0xe8(t6)
    ld      t6,  0xf0(t6)

    sret

_kernel_trap_vec:
    sret
