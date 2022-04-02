#ifndef UART_H
#define UART_H

#include "constants.h"
#include <inttypes.h>

static inline void uart_tx(uint8_t data) {
  *(volatile uint32_t *)UART_TX_ADDR = data;
}

static inline uint8_t uart_rx(void) {
  return *(volatile uint32_t *)UART_RX_ADDR;
}

#endif
