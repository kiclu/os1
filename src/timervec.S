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

.global _timervec
.align 4

_timervec:
    # save context
    csrrw   a0, mscratch, a0
    sd      a1,  0(a0)
    sd      a2,  8(a0)
    sd      a3, 16(a0)

    # schedule next interrupt
    ld      a1, 24(a0)
    ld      a2, 32(a0)
    ld      a3,  0(a1)
    add     a3, a3, a2
    sd      a3,  0(a1)

    # arrange a supervisor timer interrupt
    csrs    sip, 2

    # restore context
    ld      a3, 16(a0)
    ld      a2, 8(a0)
    ld      a1, 0(a0)
    csrrw   a0, mscratch, a0

    # return
    mret
