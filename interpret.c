#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

/* simplified bf grammar that this interpreter is based on:
   <command> ::= '+' | '-' | '>' | '<' | '.' | ',' | <loop>
   <loop> ::= '[' { <command> } ']'

   and in this implementation vel. dialect you can use another command - '?'
   it shows memory right from the current pointer's position.

   And also '!' prints value under the current cell as an unsgined
   inty char ie. a number from 0 to 255 (see the function printnum).

   You can also do the same thing but with the input with "^" (assignnum).

   Also `#` marks comments - the interpreter will skip everything after a #
   on a given line
*/

char* command(char* p, char** source)
{
  while (**source != '\0' && **source != ']') {
    /* skip coments all the way to the eoln/eof */
    if (**source == '#')
      for (; (**source != '\n' && **source != '\0'); ++*source);

    /* commends */
    if (**source == '-')
      --*p;
    else if (**source == '+')
      ++*p;
    else if (**source == '<')
      --p;
    else if (**source == '>')
      ++p;
    else if (**source == '.')
      print(p);
    else if (**source == ',')
      assign(&p);
    else if (**source == '[')
      p = loop(p, source);
    else if (**source == ']')
      break;
    /* NONSTANDARD YET HELPFUL COMMANDS */
    else if (**source == '?') {
      printf("\n");
      show_memory(p);
    } else if (**source == '!')
      printnum(p);
    else if (**source == '^')
      assignnum(&p);

    ++*source;
  }

  return p;
}

char* loop(char* p, char** source)
{
  char* start = *source;
  int l_par = 1, r_par = 0;

  while (*p) {
    *source = start;
    ++*source;
    p = command(p, source);
  }

  /* jump all the way to the loop's end in case it doesnt even initialise
   * if the loop run at least one time it should've been set at the end */
  if (**source == '[')
    do {
      ++*source;

      if (**source == '[')
        l_par++;
      else if (**source == ']')
        r_par++;
    } while (**source != ']' || l_par != r_par);

  return p;
}

void print(char* p)
{
  printf("%c", *p);
}

void assign(char** p)
{
  scanf("%c", *p);
}

/* nonstandard bf - numeral output and input */
void printnum(char* p)
{
  printf("%u", (unsigned char)*p);
}

void assignnum(char** p)
{
  scanf("%d", (int*)*p);
}
