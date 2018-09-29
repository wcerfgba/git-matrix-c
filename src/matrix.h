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
  MatrixFile **files;   // Pointer to array of pointers to files
  MatrixUser **users;   // Pointer to array of pointers to users
  MatrixCell ***cells;  // Pointer to 2D array (user * file) of pointers to cells
} Matrix;

typedef int MatrixType;
static MatrixType MATRIX_TYPE_CHANGE_COUNT = 0;

typedef struct MatrixConfig {
  MatrixType type;
} MatrixConfig;

Matrix matrix_init(MatrixConfig config);

void matrix_add_commit(Matrix *matrix, ParserCommit commit);

void matrix_sort(Matrix *matrix);

MatrixUser *matrix_user_alloc(MatrixUser matrixUser);

int matrix_user_comp(MatrixUser **a, MatrixUser **b);
int matrix_file_comp(MatrixFile **a, MatrixFile **b);

#endif