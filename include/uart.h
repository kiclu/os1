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

#ifndef _OS1_UART_H_
#define _OS1_UART_H_

#include <memlayout.h>
#include <types.h>

#define UART_REG(idx) ((volatile uint8_t*)(UART0 + idx))

#define RHR 0
#define THR 0
#define IER 1
#define FCR 2
#define ISR 2
#define LCR 3
#define LSR 5

#define IER_RX_ENABLE   (1 << 0)
#define IER_TX_ENABLE   (1 << 1)

#define FCR_FIFO_ENABLE (1 << 0)
#define FCR_FIFO_CLEAR  (3 << 1)

#define LCR_EIGHT_BITS  (3 << 0)
#define LCR_BAUD_LATCH  (1 << 7)

#define LSR_RX_READY    (1 << 0)
#define LSR_TX_IDLE     (1 << 5)

#define UART_READ_REG(idx)      (*(UART_REG(idx)))
#define UART_WRITE_REG(idx, v)  (*(UART_REG(idx)) = (v))

#define IART_TX_BUF_SIZE 32

void    _uart_init();

void    _uart_putc(char);
char    _uart_getc();

#endif//_OS1_UART_H_
