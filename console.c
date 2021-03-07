#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"


void interpreter(char memory[SIZE])
{
  size_t cmnd_len = 0;
  char* cmnd = NULL;
  char* p;
  int i = 0, j, len;
  int error;

  intro();

  do {
    printf("\033[0;32m");
    printf("|> ");
    printf("\033[0m");
    fflush(stdout);
    len = getline(&cmnd, &cmnd_len, stdin);

    /* check whether the command aint too long */
    if (cmnd == NULL)
      exit(1);

    p = cmnd;

    if (*cmnd == 'q')
      break;

    if (*cmnd == '\n')
      continue;

    /* checking for unmatched parentheses */
    error = check(cmnd);

    if (error <= 0) {
      printf("\033[0;36m");
      printf("|< ");
      printf("\033[0m");

      /* exec */
      p = command(memory + i, &cmnd);
      i = p - memory;

      /* index out of range vel seg fault */
      if (i < 0 || i >= SIZE) {
        printf("\033[1;31m");
        printf("ERRONOUS COMMAND\n");
        printf("\033[0;31m");
        show_error(cmnd - len, -len + 2);
        printf("\033[0m");
        i = 0;
      }

      printf("\033[0;33m");
      printf("\n@ ");
      show_memory(memory);
      printf("\033[0m");
      printf("\n  ");

      /* show the pointer */
      for (j = 0; j < i; j++)
        printf("      ");

      printf("\033[1;35m");
      printf("^");
      printf("\033[0m");

      /* clean_memory(memory); */
      cmnd = cmnd - len;
      printf("\n");
    } else {
      printf("\033[1;31m");
      printf("ERRONOUS COMMAND\n");
      printf("\033[0;31m");
      show_error(cmnd, error);
      printf("\033[0m");
    }
  } while (*cmnd != 'q');

  free(cmnd);
}

void intro(void)
{
  /* intro */
  printf("AN INTERACTIVE BRAINFUC");
  printf("\033[1;34m");
  printf("C");
  printf("\033[0m");
  printf(" CONSOLE\n\n");
  /* |> */
  printf("\033[0;32m");
  printf("|> ");
  printf("\033[0m");
  printf("- INPUT\n");
  /* |< */
  printf("\033[0;36m");
  printf("|< ");
  printf("\033[0m");
  printf("- OUTPUT\n");
  /* @ */
  printf("\033[0;33m");
  printf("@  ");
  printf("\033[0m");
  printf("- CURRENT MEMORY STATUS. DISPLAYED AS: ");
  printf("\033[0;33m");
  printf("value@adress\n");
  printf("\033[0m");
  /* ^ */
  printf("\033[1;35m");
  printf("^  ");
  printf("\033[0m");
  printf("- CURRENT POINTER POSITION\n");

  printf("\nUSE q OR CTRL-C TO QUIT\n\nEXECUTE WITH ENTER\n---\n");
}


void clean_memory(char memory[SIZE])
{
  int i;

  for (i = 0; i <= 50; i++)
    memory[i] = 0;
}

/* shows first 7 cells and then checks
forward whether in +4 dist there is a non zero cell present */
void show_memory(char memory[SIZE])
{
  int i = 0;

  while (memory[i] || memory[i + 1] || memory[i + 2]
         || memory[i + 3] || memory[i + 4] || i < 7) {

    printf("%02d@%.2d ", memory[i], i);
    i++;
  }

  printf("\b...");
}
