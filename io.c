#include "io.h"

void print_string(const char *p) {
  while (*p != 0)
    print_char(*(p++));
}
