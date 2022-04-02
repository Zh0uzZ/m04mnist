#ifndef IO_H
#define IO_H

#include "uart.h"
#include <inttypes.h>

static inline void print_char(char c) { uart_tx(c); }
static inline char get_char(void) { return uart_rx(); }

void print_string(const char *p);

#endif
