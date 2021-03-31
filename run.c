#include <stdio.h>
#include <stdlib.h>

#include "main.h"


/* execute brainfuck code from files */
void from_file(char memory[SIZE], char* path, int show)
{
  char* buffer = 0;
  FILE* f = fopen(path, "r");
  long length;
  int error;
  char skip;

  /* opening the file and storing it as a string*/
  if (f) {
    fseek(f, 0, SEEK_END);
    length = ftell (f);
    fseek(f, 0, SEEK_SET);
    buffer = malloc (length + 1);

    if (buffer)
      fread (buffer, 1, length, f);
    else
      exit(1);

    fclose (f);
    buffer[length] = '\0';

    if (show)
      printf("READING FILE `%s`: \n--------------\n%s\n----------\n", path, buffer);
  } else {
    perror("Error while opening the source file\n");
    exit(EXIT_FAILURE);
  }

  if (buffer)  {
    error = check(buffer);

    if (error) {
      printf("\033[1;31m");
      printf("AN ERROR FOUND\n");
      printf("\033[0;31m");
      show_error(buffer, error);
      printf("\033[0m");
      printf("INVALID SOURCE CODE\n");
      printf("DO YOU WANT TO SKIP THE ERROR? (y/n)\n");
      scanf("%c", &skip);

      /* you can skip errors if u really want to */
      if (skip != 'y') {
        exit(EXIT_FAILURE);
        return;
      }
    }

    printf("EXECUTING SOURCE CODE FROM `%s`\nOUTPUT:\n-------\n", path);
    command(memory, &buffer);
    printf("\n-------");
    free(buffer - length);
  } else
    printf("INVALID DATA\n");
}

/* execute code from command line */
void from_cmnd(char memory[SIZE], char** source)
{
  int error = check(*source);

  if (error) {
    printf("\033[1;31m");
    printf("AN ERROR FOUND\n");
    printf("\033[0;31m");
    show_error(*source, error);
    printf("\033[0m");
    printf("INVALID SOURCE CODE\n");
    exit(EXIT_FAILURE);
  } else
    command(memory, source);
}

