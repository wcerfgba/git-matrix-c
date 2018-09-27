#ifndef GIT_MATRIX_UTILS_H
#define GIT_MATRIX_UTILS_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../vendor/stretchy_buffer.h"
#include "../vendor/sds/sds.h"

#define heap(value) memcpy(malloc(sizeof value), &value, sizeof(value))
#define heapstr(charptr) strcpy(malloc(strlen(charptr) * sizeof(char)), charptr)

#define log_error(...) {        \
  fprintf(stderr, __VA_ARGS__); \
}

#define call(continuation, ...) {                           \
  (continuation).method((continuation).receiver, __VA_ARGS__);  \
}

typedef struct Continuation {
  void (*method)();
  void *receiver;
} Continuation;

typedef struct Status {
  int success;
  char *error;
} Status;

int status_check(Status status);

#endif