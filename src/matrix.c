#include "matrix.h"

#include "utils.h"

Matrix matrix_init(MatrixConfig config) {
  return (Matrix){
    .users = NULL
  };
}

void matrix_add_commit(Matrix *matrix, ParserCommit commit) {
  MatrixUser *newUser = matrix_user_alloc((MatrixUser){
    .email = commit.committerEmail
  });
  MatrixUser **matrixUser = stb_sb_bsearch(&newUser, matrix->users, matrix_user_comp);
  if (matrixUser == NULL) {
    sb_push(matrix->users, newUser);
    matrixUser = &sb_last(matrix->users);

    MatrixCell **newRow = NULL;
    sb_add(newRow, sb_count(matrix->files));
    for (int i = 0; i < sb_count(newRow); i++) {
      newRow[i] = heap((MatrixCell){ .value = 0 });
    }
    sb_push(matrix->cells, newRow);
  }

  for (ParserCommitFile *commitFile = commit.files; commitFile - commit.files < sb_count(commit.files); commitFile++) {
    MatrixFile *newFile = matrix_file_alloc((MatrixFile){
      .name = commitFile->name
    });
    MatrixFile **matrixFile = stb_sb_bsearch(&newFile, matrix->files, matrix_file_comp);
    if (matrixFile == NULL) {
      sb_push(matrix->files, newFile);
      matrixFile = &sb_last(matrix->files);

      for (MatrixCell ***user = matrix->cells; user - matrix->cells < sb_count(matrix->cells); user++) {
        sb_push(*user, heap((MatrixCell){ .value = 0 }));
      }
    }

    // TODO: generic value/score calculation
    matrix->cells[matrixUser - matrix->users][matrixFile - matrix->files]->value++;
  }

  matrix_sort(matrix);
}

MatrixUser *matrix_user_alloc(MatrixUser matrixUser) {
  return heap((MatrixUser){
    .email = heapstr(matrixUser.email)
  });
}

MatrixFile *matrix_file_alloc(MatrixFile matrixFile) {
  return heap((MatrixFile){
    .name = heapstr(matrixFile.name)
  });
}

int matrix_user_comp(MatrixUser **a, MatrixUser **b) {
  return strcmp((*a)->email, (*b)->email);
}

int matrix_file_comp(MatrixFile **a, MatrixFile **b) {
  return strcmp((*a)->name, (*b)->name);
}

void matrix_sort(Matrix *matrix) {
  stb_sb_qsort(matrix->users, matrix_user_comp);
}