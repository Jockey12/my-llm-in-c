#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileLoaded(FILE *file) {
  if (file == NULL) {
    return 1;
  }
  return 0;
}

char *scanFile(char fileName[]) {
  FILE *file = fopen(fileName, "r");
  if (fileLoaded(file) != 0) {
    perror("Error loading file");
    printf("%s", fileName);
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);

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

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Usage: %s <file.txt>", argv[0]);
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
