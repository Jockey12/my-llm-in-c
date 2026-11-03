#ifndef LA_H_
#define LA_H_

typedef struct Mat Mat;                  // Matrix definition
struct Mat make_mat(int rows, int cols); // Create matrix
int isSquareMat(struct Mat *a); // Check square mat
static float rand_float(void);           // Random float num gen
void mat_print(struct Mat *m);           // Print matrix
/*  Mat */ void mat_add(struct Mat *A, struct Mat *B); // Add matrix(s)
Mat mat_mul(struct Mat *A, struct Mat *B); // Multiply Matrix
/* float mat_mul(struct Mat *A, int m, int n, struct Mat *B, int n2,int p); //
 * matrix multiply */
/* float dot(float *a, float *b, int n); // dot product */
/* float badd(float *a, float *b, float scalar, int n); // Binary Add */
#endif /* ifndef LA_H_ */

#ifdef LA_H_IMPLEMENTATION

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static float rand_float(void) {
  /* return(float)rand() / (float)RAND_MAX; */
  return (float)(arc4random() >> 8) /
         16777216.0f; // [0, 1] Random generator for mac
}

struct Mat {
  int rows;
  int cols;
  float *data;
  /*
  ** Implement later
   int stride, dtype; */
};

int isSquareMat(struct Mat *a) {
    return a->rows == a-> cols;
}

struct Mat make_mat(int rows, int cols) {
  struct Mat m = {
      .rows = rows, .cols = cols, .data = malloc(rows * cols * sizeof(float))};
  return m;
};

void mat_print(struct Mat *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      int idx = i * m->cols + j;
      printf("%8.3f", m->data[idx]);
    }
    printf("\n");
  }
}
void mat_add(struct Mat *A, struct Mat *B) { printf("TODO");}

/* float mat_mul(struct Mat *A, int m, int n, struct Mat *B, int n2, int p) { */
Mat mat_mul(struct Mat *A, struct Mat *B) {
  struct Mat C = make_mat(A->rows, B->cols);
  // Loop through matrixs
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < B->cols; ++j) {
      float sum = 0.0;
      // Loop through A columns;
      for (int k = 0; k < A->cols; k++) {
        sum += A->data[i * A->cols + k] * B->data[k * B->cols + j];
      }
      C.data[i * C.cols + j] = sum;
    }
  }
  return C;
}

#endif /* ifndef LA_H_IMPLEMENTATION */
