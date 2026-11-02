#define LA_H_IMPLEMENTATION
#include "la.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

float forward_pass(float x1, float x2, float w1, float w2, float b) {
  float z = w1 * x1 + w2 * x2 + b;
  return z >= 0.0 ? 1.0 : 0.0;
}

int main(int argc, char *argv[]) {
  srand((unsigned)time(NULL) ^ (unsigned)getpid());
  float x1 = rand_float() * 2.0f - 1.0f;
  float x2 = rand_float() * 2.0f - 1.0f;

  float w1 = rand_float() * 2.0f - 1.0f;
  float w2 = rand_float() * 2.0f - 1.0f;
  float y = 0.0f;
  float b = rand_float() * 2.0f - 1.0f;
  float lr = 0.1;
  /* struct Mat weight = make_mat(1, 2); */
  /* for (int i = 0; i < weight.rows; i++) { */
  /*   for (int j = 0; j < weight.cols; j++) { */
  /*     weight.data[i * weight.cols + j] = rand_float() * 2.0f - 1.5f; */
  /*   } */
  /* } */

  for (int epoch = 0; epoch < 5; epoch++) {
    for (int i = 0; i < 5; i++) {
    printf("%f\n",forward_pass(x1, x2, w1, w2, b));
    }
  }

  /* AND Gate
  ** x1 x2 output
  ** 0  0  0
  ** 0  1  0
  ** 1  0  0
  ** 1  1  1
  */

  /* mat_print(&weight); */
  return 0;
}
