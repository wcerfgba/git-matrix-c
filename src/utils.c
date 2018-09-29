#include "utils.h"

int status_check(Status status) {
  if (!status.success) {
    log_error(status.error);
  }
  return status.success;
}

void *stb_sb_bsearch(const void *key, const void *ptr, int (*comp)(const void *, const void *)) {
  return bsearch(key, ptr, stb_sb_count(ptr), sizeof(*ptr), comp);
}

void stb_sb_qsort(void *ptr, int (*comp)(const void *, const void *)) {
  qsort(ptr, stb_sb_count(ptr), sizeof(*ptr), comp);
}