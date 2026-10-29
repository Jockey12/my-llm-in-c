#define TOKENIZER_H_IMPLEMENTATION
#define FILEIO_H_IMPLEMENTATION
#include "tokenizer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    Tokenizer t;
    t.vsize = 4;
    t.fileName = "hi";
    t.file = fopen(t.fileName, "r");

  if (argc == 1) {
    printf("Usage: %s train <file.txt>", argv[0]);
  } else if (argc == 3 && strcmp(argv[1], "train") == 0) {
    char *data = scanFile(argv[2]);
    if (data == NULL) {
      fprintf(stderr, "failed to load dataset\n");
      exit(1);
    }
    printf("Dataset Loaded: %s", argv[2]);
    free(data);
  } else {
    printf("Wrong usage");
    return 1;
  }

  return 0;
}
