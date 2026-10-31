#define LA_H_IMPLEMENTATION
#include "la.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  struct Mat a = make_mat(5, 5);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.cols; j++) {
      a.data[i * a.cols + j] = (float)(rand() % 100 + 1);
    }
  }
  mat_print(&a);
  return 0;
}
