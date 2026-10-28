#ifndef FILEIO_H
#define FILEIO_H
#include <stdio.h>

int fileLoaded(FILE *file);
char *scanFile(char fileName[]);

#endif /* ifndef FILEIO_H */

#ifdef FILEIO_H_IMPLEMENTATION

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

#endif /* ifndef FILEIO_H_IMPLEMENTATION */
