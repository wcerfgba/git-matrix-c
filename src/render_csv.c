#include "render_csv.h"

#include "utils.h"

char *render_csv(Matrix *matrix) {
  // First row will have user emails.
  // First cell is empty because the first column will have file names.
  char *csv = ",";

  for (MatrixUser *user = matrix->users; user != NULL; user++) {
    Sasprintf(csv, user->email);
  }
}