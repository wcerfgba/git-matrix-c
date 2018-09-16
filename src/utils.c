#include "utils.h"

void log_error(char *error) {
  fprintf(stderr, error);
}

int status_check(Status status) {
  if (!status.success) {
    log_error(status.error);
  }
  return status.success;
}