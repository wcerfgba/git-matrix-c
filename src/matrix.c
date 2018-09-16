#include "matrix.h"

Matrix matrix_init(MatrixConfig config) {
  return (Matrix){
    .users = (MatrixUser[]){}
    // TODO: need stretchy_buffer
  };
}

void matrix_add_commit(Matrix *matrix, ParserCommit commit) {

}

void matrix_sort(Matrix *matrix) {
  
}