#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <stdio.h>

typedef struct Tokenizer Tokenizer;
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
    int vsize;
    int merge_r;
    char *path;
    char *fileName;
    FILE *file ;
} Tokenizer;

#endif /* ifndef TOKENIZER_H_IMPLEMENTATION */
