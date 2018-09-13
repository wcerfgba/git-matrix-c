#include "matrix.h"

typedef struct OutputStatus {
  bool success;
  char *error;
} OutputStatus;

typedef OutputStatus (*OutputF)(Matrix *matrix);