#ifndef LA_H_
#define LA_H_

#include <stddef.h>

static float rand_float(void);                 // Random float num gen
typedef struct Mat Mat;                        // Matrix definition
struct Mat make_mat(size_t rows, size_t cols); // Create matrix
int isSquareMat(struct Mat *a);                // Check square mat
void mat_print(struct Mat *m);                 // Print matrix
/* /\*  Mat *\/ void mat_add(struct Mat *A, struct Mat *B); // Add matrix(s) */
struct Mat mat_mul(const struct Mat *A, const struct Mat *B); // Multiply Matrix
/* float mat_mul(struct Mat *A, int m, int n, struct Mat *B, int n2,int p); //
 * matrix multiply */
/* float dot(float *a, float *b, int n); // dot product */
/* float badd(float *a, float *b, float scalar, int n); // Binary Add */
#endif /* ifndef LA_H_ */

#ifdef LA_H_IMPLEMENTATION

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <time.h>
#include <unistd.h>

static float rand_float(void) {
#ifdef __APPLE__
  return (float)(arc4random() >> 8) / 16777216.0f;
#else
  static int seeded = 0;
  if (!seeded) {

    srand((unsigned)time(NULL) ^ (unsigned)getpid());
    seeded = 1;
  }
  return (float)(rand() & 0xFFFFFF / 167777216.0f;)
#endif
}

struct Mat {
  size_t rows;
  size_t cols;
  float *data;
  /*
  ** Implement later
   int stride, dtype; */
};

int isSquareMat(struct Mat *a) { return a->rows == a->cols; }

struct Mat make_mat(size_t rows, size_t cols) {
  struct Mat m = {
      .rows = rows, .cols = cols, .data = malloc(rows * cols * sizeof(float))};
  return m;
};

void mat_print(struct Mat *m) {
  for (size_t i = 0; i < m->rows; i++) {
    for (size_t j = 0; j < m->cols; j++) {
      size_t idx = i * m->cols + j;
      printf("%8.3f", m->data[idx]);
    }
    printf("\n");
  }
}
/* void mat_add(struct Mat *A, struct Mat *B) { printf("TODO"); } */

struct Mat mat_mul(const struct Mat *A, const struct Mat *B) {
  struct Mat C = make_mat(A->rows, B->cols);
  // Loop through matrixs
  for (size_t i = 0; i < A->rows; ++i) {
    for (size_t j = 0; j < B->cols; ++j) {
      float sum = 0.0f;
      // Loop through A columns;
      for (size_t k = 0; k < A->cols; k++) {
        sum += A->data[i * A->cols + k] * B->data[k * B->cols + j];
      }
      C.data[i * C.cols + j] = sum;
    }
  }
  return C;
}

#endif /* ifndef LA_H_IMPLEMENTATION */
