#ifndef GIT_MATRIX_UTILS_H
#define GIT_MATRIX_UTILS_H

#include <stdio.h>

void log_error(char *error);

typedef struct Status {
  int success;
  char *error;
} Status;

int status_check(Status status);

#endif