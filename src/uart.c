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

#include <uart.h>

void _uart_init() {
    // disable interrupts
    UART_WRITE_REG(IER, 0x00);

    // set baud rate
    UART_WRITE_REG(LCR, LCR_BAUD_LATCH);
    UART_WRITE_REG(0, 0x03);
    UART_WRITE_REG(1, 0x00);

    // set word length to 8 bits
    UART_WRITE_REG(LCR, LCR_EIGHT_BITS);

    // reset and enable FIFO
    UART_WRITE_REG(FCR, FCR_FIFO_ENABLE | FCR_FIFO_CLEAR);

    // enable transmit and receive interrupts
    UART_WRITE_REG(IER, IER_TX_ENABLE | IER_RX_ENABLE);
}

void _uart_putc(char c) {
    while((UART_READ_REG(LSR) & LSR_TX_IDLE) == 0);
    UART_WRITE_REG(THR, c);
}

char _uart_getc() {
    return -1;
}
