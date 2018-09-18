#include "matrix.h"

#include "utils.h"

Matrix matrix_init(MatrixConfig config) {
  return (Matrix){
    .users = NULL
  };
}

void matrix_add_commit(Matrix *matrix, ParserCommit commit) {
  // TODO: think i need to allocate the user on the heap
  sb_push(matrix->users, &(MatrixUser){
    .email = commit.committerEmail
  });
}

void matrix_sort(Matrix *matrix) {
  // TODO
}

void matrix_destroy(Matrix *matrix) {
  // TODO
}