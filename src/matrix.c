#include "matrix.h"

#include "utils.h"

Matrix matrix_init(MatrixConfig config) {
  return (Matrix){
    .users = NULL
  };
}

void matrix_add_commit(Matrix *matrix, ParserCommit commit) {
  MatrixUser matrixUser = (MatrixUser){
    .email = heapstr(commit.committerEmail)
  };
  MatrixUser *matrixUserHeap = heap(matrixUser);
  sb_push(matrix->users, matrixUserHeap);
}

void matrix_sort(Matrix *matrix) {
  // TODO
}

void matrix_destroy(Matrix *matrix) {
  // TODO
}