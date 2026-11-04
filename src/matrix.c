#define LA_H_IMPLEMENTATION
#include "la.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  struct Mat a = make_mat(2, 3);
  struct Mat b = make_mat(3,3);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.cols; j++) {
      a.data[i * a.cols + j] = rand_float() * 2.0f - 1.0f;
    }
  }

  mat_print(&a);
  return 0;
}
