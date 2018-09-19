#include "render_csv.h"

#include "utils.h"

char *render_csv(Matrix *matrix) {
  // First row will have user emails.
  // First cell is empty because the first column will have file names.
  char *csv = NULL;

  for (MatrixUser **user = matrix->users; *(MatrixUser **)(user) != NULL; user++) {
    sb_push(csv, ',');
    char *email = (*(MatrixUser **)(user))->email;
    sb_add(csv, strlen(email));
    strcpy(csv + strlen(csv), email);
  }

  return csv;
}