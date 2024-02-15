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

#ifndef _OS1_KINFO_H_
#define _OS1_KINFO_H_

#include <printk.h>

#define KINFO_STARTING(m)           _printk("         Starting \x1b[1m" m "\x1b[0m...\n");
#define KINFO_STARTING_I(m, i0)     _printk("         Starting \x1b[1m" m "\x1b[0m...\n", i0);

#define KINFO_STARTED(m)            _printk("[  \x1b[32mOK\x1b[0m  ] Started \x1b[1m" m "\x1b[0m.\n");
#define KINFO_STARTED_I(m, i0)      _printk("[  \x1b[32mOK\x1b[0m  ] Started \x1b[1m" m "\x1b[0m.\n", i0);

#define KINFO_TARGET(m)             _printk("[  \x1b[32mOK\x1b[0m  ] Reached target \x1b[1m" m "\x1b[0m.\n");

#endif//_OS1_KINFO_H_
