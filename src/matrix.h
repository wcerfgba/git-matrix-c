#ifndef GIT_MATRIX_MATRIX_H
#define GIT_MATRIX_MATRIX_H

#include "parser.h"

typedef struct MatrixFile {
  char *name;
} MatrixFile;

typedef struct MatrixUser {
  char *email;
} MatrixUser;

typedef struct MatrixCell {
  unsigned long int value;
} MatrixCell;

typedef struct Matrix {
  MatrixFile **files;   // Array of pointers to files
  MatrixUser **users;   // Array of pointers to users
  MatrixCell ***cells;  // 2D array (user * file) of pointers to cells
} Matrix;

typedef int MatrixType;
static MatrixType MATRIX_TYPE_CHANGE_COUNT = 0;

typedef struct MatrixConfig {
  MatrixType type;
} MatrixConfig;

Matrix matrix_init(MatrixConfig config);
void matrix_destroy(Matrix *matrix);

void matrix_add_commit(Matrix *matrix, ParserCommit commit);

void matrix_sort(Matrix *matrix);

#endif