#ifndef GIT_MATRIX_MATRIX_H
#define GIT_MATRIX_MATRIX_H

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
  MatrixFile *files;
  MatrixUser *users;
  MatrixCell **cells;
  char *qwe; // for testing
} Matrix;

extern Matrix matrix_init();

#endif