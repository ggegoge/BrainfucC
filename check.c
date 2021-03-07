#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

/* check whether the data is valid */
/* error codes:
   0: no errors
   i: unclosed [ or ] at idx i
   -i: accesing negative memory adresses at idx i
*/


/* count the number of: [, ], < and >.
   if the number of [ doesnt match the number of ] it means
   that there're some unclosed/unopened loops.
   If the number of > is lesser then the number of < it MIGHT
   mean that the programme tries to acces negative memory at
   some point but not necessarly - a loop with that goes > twice
   can be balanced with << later and that would still trigger the error
*/
int check(char* source)
{
  int i = 0;
  int r_parenth = 0, l_parenth = 0;
  int l_point = 0, r_point = 0;
  int idx_par_clos = 0, idx_par_op = 0, idx_point = 0;

  while (*source != '\0') {
    /* skip comments */
    if (*source == '#')
      while ((*source != '\n') && (*source != '\0')) {
        source++;
        i++;
      }

    if (*source == '[') {
      l_parenth++;
      idx_par_op = i;
    } else if (*source == ']') {
      r_parenth++;
      idx_par_clos = i;
    }

    /* correct memory acces */
    if (*source == '<') {
      l_point++;
      idx_point = i;
    } else if (*source == '>') {
      r_point++;
      idx_point = i;
    }

    /* return the index of the possible memory violation */
    if (r_point - l_point < 0)
      return -idx_point;

    i++;
    source++;
  }

  /* return the index of last unmatched [ or ] */
  if (idx_par_clos == 0)
    idx_par_clos++;

  if (idx_par_op == 0)
    idx_par_op++;

  if (l_parenth != r_parenth)
    return l_parenth > r_parenth ? idx_par_op : idx_par_clos;

  return 0;                     /* no errors found */
}


/* kinda working, puts a ^ under the unclosed/unopened loop
or under the possible seg-faulting */
void show_error(char* source, int error)
{
  int i;
  char traceback[60];

  if (error > 0)
    strcpy(traceback, "DANGLING PARENTHESES AT %d\n");
  else if (error < 0) {
    strcpy(traceback, "POSSIBLY TRYING TO ACCES NEGATIVE MEMORY ADRESSES AT %d\n");
    error = -error;
  }

  if (error > 5) {
    for (i = 0; i < error - 5; i++)
      source++;

    printf("...");

    for (i = error - 5; i <= error; i++)
      printf("%c", *(source + i - error + 5));

    printf("\n        ^ ");
    printf(traceback, error);
  } else {
    for (i = 0; i <= error; i++)
      printf("%c", *(source + i));

    printf("\n");

    for (i = 0; i < error; i++)
      printf(" ");

    printf("^ ");
    printf(traceback, error);
  }
}
