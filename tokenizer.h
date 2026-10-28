#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <stdio.h>

typedef struct Tokenizer Tokenizer;
int fileLoaded(FILE *file);
char *scanFile(char fileName[]);
int vocab_size(const Tokenizer *t);
Tokenizer *train_bpe(const char *corpus_path, int vocab_size, int merge_rounds);
int encode(const Tokenizer *t, char *text);
int decode(const Tokenizer *t);
#endif /* ifndef TOKENIZER_H */

#ifdef TOKENIZER_H_IMPLEMENTATION

#include <assert.h>
#include <stdlib.h>

int fileLoaded(FILE *file) { return file == NULL; }
char *scanFile(char *fileName) {
  FILE *file = fopen(fileName, "r");

  if (fileLoaded(file) != 0) {
    perror("Error loading file");
    printf("%s", fileName);
    return NULL;
  }

  // find start and end of file to find size.
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);
  assert(size > 0);

  // set file contents to buffer
  char *buffer = malloc(size);
  if (buffer == NULL) {
    perror("Cant allocate buffer");
    fclose(file);
    return NULL;
  }
  size_t read = fread(buffer, 1, size, file);
  if (read != (size_t)size) {
    perror("fread failed");
    free(buffer);
    fclose(file);
    return NULL;
  }

  fclose(file);
  return buffer;
}

#endif /* ifndef TOKENIZER_H_IMPLEMENTATION */
