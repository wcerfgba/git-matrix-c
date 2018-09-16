#ifndef GIT_MATRIX_OUTPUT_H
#define GIT_MATRIX_OUTPUT_H

#include "matrix.h"
#include "utils.h"

typedef struct OutputStatus {
  struct Status;
} OutputStatus;

typedef OutputStatus (*Output)(Matrix *matrix);

#endif