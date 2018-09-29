#include "matrix.h"

#include "utils.h"

Matrix matrix_init(MatrixConfig config) {
  return (Matrix){
    .users = NULL
  };
}

void matrix_add_commit(Matrix *matrix, ParserCommit commit) {
  MatrixUser *matrixUser = matrix_user_alloc((MatrixUser){
    .email = commit.committerEmail
  });
  if (stb_sb_bsearch(&matrixUser, matrix->users, matrix_user_comp) == NULL) {
    sb_push(matrix->users, matrixUser);
    stb_sb_qsort(matrix->users, matrix_user_comp);
  }
}

MatrixUser *matrix_user_alloc(MatrixUser matrixUser) {
  return heap((MatrixUser){
    .email = heapstr(matrixUser.email)
  });
}

int matrix_user_comp(MatrixUser **a, MatrixUser **b) {
  return strcmp((*a)->email, (*b)->email);
}