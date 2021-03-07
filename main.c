#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

char memory[SIZE];  /* allocate cells */

int main(int argc, char** argv)
{
  if (argc < 2) {
    printf("USE `bf -h` FOR HELP\n");
    printf("------------\n");
    interpreter(memory);
    return 0;
  }

  /* options selected by adding '-' */
  if (argv[1][0] == '-') {
    /* help */
    if (argv[1][1] == 'h') {
      printf("BrainfucC\n");
      printf("\n\t\t\ta BRAINFUC");
      printf("\033[1;34m");
      printf("C");
      printf("\033[0m");
      printf(" INTERPRETER\n");

      printf("\033[0;33m");
      printf("copyright (c) 2020 test0wanie\n");
      printf("\033[0m");
      /* user manual */
      printf("\nYOU CAN:\n");
      printf("1. INTERPRET CODE FROM COMMAND LINE BY SIMPLY ");
      printf("PASSING IT IN QUOTES WHEN CALLING THE INTERPRETER\n");
      printf("\tEG. `bf \"++++[>++++[>+++<-]<-]>>++.-.++.++++.\"`\n");
      printf("2. INTERPRET CODE FROM A SOURCE FILE JUST WRITING IT'S ");
      printf("NAME AFTER A -f FLAG WHEN CALLING THE INTERPRETER\n");
      printf("\tEG. `bf -f example.bf`\n\tOR IF YOU WANT TO SEE THE SOURCE CODE\n");
      printf("\tEG. `bf -f example.bf -s`\n");
      printf("3. ADD AN OPTIONAL -i FLAG TO RUN AN INTERACTIVE BF CONSOLE\n");
      printf("\tEG. `bf -i` OR `bf`\n");
    }
    /* execute from file */
    else if (argv[1][1] == 'f') {
      if (argc > 3)
        from_file(memory, argv[2], (argv[3][0] == '-'));
      else
        from_file(memory, argv[2], 0);
    }
    /* interactive interpreter */
    else if (argv[1][1] == 'i')
      interpreter(memory);
  }
  /* command passed in-line via the terminal */
  else
    from_cmnd(memory, &argv[1]);

  printf("\nEND\n");
  return 0;
}

