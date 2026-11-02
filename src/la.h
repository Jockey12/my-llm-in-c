#ifndef LA_H_
#define LA_H_

typedef struct Mat Mat; // Matrix definition
struct Mat make_mat(int rows, int cols); // Create matrix
static float rand_float(void); // Random float num gen
void mat_print(struct Mat *m); // Print matrix
void mat_add(struct Mat *A, struct Mat *B, struct Mat *C); // Add matrix(s)
float mat_mul(struct Mat *A, int m, int n, struct Mat *B, int n2, int p); // matrix multiply
/* float dot(float *a, float *b, int n); // dot product */
/* float badd(float *a, float *b, float scalar, int n); // Binary Add */
#endif /* ifndef LA_H_ */

#ifdef LA_H_IMPLEMENTATION

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

static float rand_float(void) {
    /* return(float)rand() / (float)RAND_MAX; */
    return (float)(arc4random() >> 8) / 16777216.0f; // [0, 1] Random generator for mac
}

struct Mat {
    int rows;
    int cols;
    float *data;
    /*
    ** Implement later
     int stride, dtype; */
};

struct Mat make_mat(int rows, int cols) {
    struct Mat m = {
      .rows = rows, .cols = cols,
      .data = malloc(rows * cols * sizeof(float))
};
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
#endif /* ifndef LA_H_IMPLEMENTATION */
