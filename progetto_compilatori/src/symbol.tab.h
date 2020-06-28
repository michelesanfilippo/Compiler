#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct b
{
  char *title;
  char *code;
  char *author;
  char *date;
  struct b *next;
} book;

book *bookList;
book *finalBookList;

void initialize();
void insertBook(char *t, char *c);
void addAuthor(char *a);
void insertTaken(char *c, char *d);
void print();
