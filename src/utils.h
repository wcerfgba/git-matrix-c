#ifndef GIT_MATRIX_UTILS_H
#define GIT_MATRIX_UTILS_H

#include <stdio.h>

#define log_error(...) {        \
  fprintf(stderr, __VA_ARGS__); \
}

// From 21st Century C
#define Sasprintf(write_to, ...) {          \
  char *tmp_string_for_extend = (write_to); \
  asprintf(&(write_to), __VA_ARGS__);       \
  free(tmp_string_for_extend);              \
}


typedef struct Status {
  int success;
  char *error;
} Status;

int status_check(Status status);

#endif