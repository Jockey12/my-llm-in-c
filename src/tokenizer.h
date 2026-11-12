#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <stdio.h>

typedef struct Tokenizer Tokenizer;
typedef struct BPEPair BPEPair;
int vocab_size(const Tokenizer *t);
Tokenizer *train_bpe(const char *corpus_path, int vocab_size, int merge_rounds);
int encode(const Tokenizer *t, char *text);
int decode(const Tokenizer *t);
#endif /* ifndef TOKENIZER_H */

#ifdef TOKENIZER_H_IMPLEMENTATION

#include "fileio.h"
#include <assert.h>
#include <stdlib.h>

typedef struct Tokenizer {
  int vocab_size;
  int merge_count;
  char *vocab_path;
  char **vocab;
  int *vocab_indices;
  BPEPair *merges;
  char *text_buffer;
  int text_len;
} Tokenizer;

typedef struct BPEPair {
  char *left;
  char *right;
  int count;
} BPEPair;

#endif /* ifndef TOKENIZER_H_IMPLEMENTATION */
