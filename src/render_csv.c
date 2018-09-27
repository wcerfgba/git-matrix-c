#include "render_csv.h"

#include "utils.h"

char *render_csv(Matrix *matrix) {
  // First row will have user emails.
  // First cell is empty because the first column will have file names.
  char *csv = sdsnew("");

  for (MatrixUser **user = matrix->users; *(MatrixUser **)(user) != NULL; user++) {
    csv = sdscat(csv, ",");
    csv = sdscat(csv, (*(MatrixUser **)(user))->email);
  }

  return csv;
}