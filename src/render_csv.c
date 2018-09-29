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

  csv = sdscat(csv, "\n");

  for (int i = 0; i < sb_count(matrix->files); i++) {
    MatrixFile **file = matrix->files + i;
    csv = sdscat(csv, (*file)->name);

    for (int j = 0; j < sb_count(matrix->users); j++) {
      csv = sdscat(csv, ",");
      char score[1024] = { 0 };
      sprintf(score, "%d", (matrix->cells[i][j])->value);
      csv = sdscat(csv, score);
    }

    csv = sdscat(csv, "\n");
  }

  return csv;
}