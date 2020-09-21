#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

/* simplified bf grammar that this interpreter is based on:
   <command> ::= '+' | '-' | '>' | '<' | '.' | ',' | <loop>
   <loop> ::= '[' { <command> } ']'

and in this implementation vel. dialect you can use another command - '!'
'!' shows memory right from the current pointer's position.

Also `#` marks comments - the interpreter will skip everything after a #
on a given line
*/

char * command(char * p, char ** source) {
  /* char curr; */
  while (**source != '\0' && **source != ']') {
    /* curr = **source; */
    /* skip coments all the way to the eoln/eof */
    if (**source == '#') 
      for(; (**source!='\n' && **source != '\0'); ++*source);
    
    /* commends */
    if (**source == '-')
      --*p;
    else if (**source == '+')
      ++*p;
    else if (**source == '<')
      --p;
    else if (**source == '>')
      ++p;
    else if (**source =='.')
      print(p);
    else if (**source ==',') 
      assign(&p);        
    else if (**source == '[') 
      p = loop(p, source);
    else if (**source == ']') 
      break;
    else if (**source == '!') {
      printf("\n");
      show_memory(p);
    }
    ++*source;
  }
  return p;
}

char * loop(char * p, char ** source) {
  char * start = *source;
  int l_par = 1, r_par = 0;

  while (*p) {
    *source = start;
    ++*source;
    p = command(p, source);
  }
  
  /* jump all the way to the loop's end in case it doesnt even initialise */
  /* if the loop run at least one time it should've been set at the end */
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

void print(char * p) {
  printf("%c", *p);
}

void assign(char ** p) {
  scanf("%c", *p);
}

