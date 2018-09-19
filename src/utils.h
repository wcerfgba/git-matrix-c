#ifndef GIT_MATRIX_UTILS_H
#define GIT_MATRIX_UTILS_H

#include <stdio.h>
#include <stdint.h>
#include "../vendor/stretchy_buffer.h"

#define heap(value) memcpy(malloc(sizeof value), &value, sizeof value)
#define heapstr(charptr) strcpy(malloc(strlen(charptr)), charptr)

#define log_error(...) {        \
  fprintf(stderr, __VA_ARGS__); \
}

typedef struct Status {
  int success;
  char *error;
} Status;

int status_check(Status status);

#endif