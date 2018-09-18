#include "render_csv.h"

#include "utils.h"

char *render_csv(Matrix *matrix) {
  // First row will have user emails.
  // First cell is empty because the first column will have file names.
  char *csv = NULL;

  // TODO: why this no work?
  // for (MatrixUser *user = matrix->users; user != NULL; user++) {
  // for (size_t i = 0; (void *)(*(matrix->users + i)) != NULL; i++) {
    MatrixUser *user = matrix->users + i;
    sb_push(csv, ",");
    sb_push(csv, user->email);
    user++;
  }

  return csv;
}