#ifndef GIT_MATRIX_OUTPUT_H
#define GIT_MATRIX_OUTPUT_H

#include "matrix.h"

typedef struct OutputStatus {
  bool success;
  char *error;
} OutputStatus;

typedef OutputStatus (*OutputF)(Matrix *matrix);

#endif