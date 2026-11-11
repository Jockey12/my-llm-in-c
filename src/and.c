#define LA_H_IMPLEMENTATION
#include "la.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <time.h>
#include <unistd.h>

void gen_seed() {
  struct utsname uts;
  uname(&uts);
  if (strcmp(uts.sysname, "Darwin") == 0) {
    srand((unsigned)time(NULL) ^ (unsigned)getpid());
  } else {
    srand(time(NULL));
  }
}
/* float forward_pass(float x1, float x2, float w1, float w2, float b) { */
/*   float z = w1 * x1 + w2 * x2 + b; */
/*   return z >= 0.0 ? 1.0 : 0.0; */
/* } */

int main(void) {
  gen_seed();

  /* float x1 = rand_float() * 2.0f - 1.0f; */
  /* float x2 = rand_float() * 2.0f - 1.0f; */

  /* float w1 = rand_float() * 2.0f - 1.0f; */
  /* float w2 = rand_float() * 2.0f - 1.0f; */
  /* float y = 0.0f; */
  /* float b = rand_float() * 2.0f - 1.0f; */
  /* float lr = 0.1; */

  /* float inputs[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; */
  /* float outputs[4] = {0, 0, 0, 1}; */
  struct Mat bias = make_mat(2, 1);
  struct Mat w1 = make_mat(1, 4);

  for (size_t i = 0; i < bias.rows; i++) {
    for (size_t j = 0; j < bias.cols; j++) {
      bias.data[i * bias.cols + j] = rand_float() * 2.0f - 1.0f;
    }
  }
  for (size_t i = 0; i < w1.rows; i++) {
    for (size_t j = 0; j < w1.cols; j++) {
      w1.data[i * w1.cols + j] = rand_float() * 2.0f - 1.0f;
    }
  }
  mat_print(&bias);
  printf("-----------\n");
  mat_print(&w1);
  printf("-----------\n");

  struct Mat C = mat_mul(&bias, &w1);
  mat_print(&C);
  printf("-----------\n");
  /* AND Gate
  ** x1 x2 out
  ** 0  0  0
  ** 0  1  0
  ** 1  0  0
  ** 1  1  1
  */

  /* struct Mat weight = make_mat(1, 2); */
  /* for (int i = 0; i < weight.rows; i++) { */
  /*   for (int j = 0; j < weight.cols; j++) { */
  /*     weight.data[i * weight.cols + j] = rand_float() * 2.0f - 1.5f; */
  /*   } */
  /* } */

  return 0;
}
