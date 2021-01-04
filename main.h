#ifndef EXPRESSIONS_H_   /* Include guard */
#define EXPRESSIONS_H_


#define SIZE 30000


/* run.c */
void from_file(char memory[SIZE], char * path, int show);
void from_cmnd(char * p, char ** source);

/* console.c */
void interpreter(char memory[SIZE]);
void intro(void);
void clean_memory(char memory[SIZE]);
void show_memory(char memory[SIZE]);

/* check.c */
int check(char * source);
void show_error(char * source, int error);

/* interpret.c */
char * command(char * p, char ** source);
char * loop(char * p, char ** source);
void print(char * p);
void assign(char ** p);
/* nonstandard bf */
void printnum(char * p);
void assignnum(char ** p);


#endif 
