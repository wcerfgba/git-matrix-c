#include "utils.h"

int status_check(Status status) {
  if (!status.success) {
    log_error(status.error);
  }
  return status.success;
}