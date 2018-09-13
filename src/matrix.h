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
} Matrix;