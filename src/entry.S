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

.global _entry

.extern _kernel_mem_region_start
.extern _stack_size

.section .text.entry
_entry:
    # read mhartid
    csrr    a0, mhartid

    # initialize stack pointer for each hart
    la      a1, _kernel_mem_region_start
    la      a2, _stack_size
    mv      sp, a1
    beqz    a0, 2f
1:
    add     sp, sp, a2
    add     a0, a0, -1
    bnez    a0, 1b
    add     sp, sp, a2

2:
    j       _start
