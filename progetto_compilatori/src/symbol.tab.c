#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.tab.h"

void initialize(){
  bookList = NULL;
  finalBookList = NULL;
}

void insertBook(char *t, char *c){
  book *temp = malloc(sizeof(book));
  temp->title = t;
  temp->code = c;
  temp->author = NULL;
  temp->date = NULL;
  temp->next = bookList;
  bookList = temp;
  printf("%s - %s\n", bookList->title, bookList->code);
}

void addAuthor(char *a){
  book *tmp = bookList;
  book *prev = NULL;
  while (tmp != NULL) {
    tmp->author = a;
    prev = tmp;
    tmp = tmp->next;
  }

  if (prev != NULL) {
    prev->next = finalBookList;
  }
   finalBookList = bookList;

  bookList = NULL;
}

void insertTaken(char *c, char *d){
  book *temp = finalBookList;
  while(temp != NULL){
    if(strcmp(c, temp->code) == 0){
      temp->date = d;
    }
    temp = temp->next;
  }
}

void print()
{
  book *temp = finalBookList;
  printf("LIBRI DISPONIBILI:\n");
  while (temp != NULL)
  {
    if (temp->date == NULL) {
      printf("(%s. %s)\n", temp->title, temp->author);  
    }
    temp = temp->next;
  }
  temp = finalBookList;
  printf("LIBRI IN PRESTITO:\n");
  while (temp != NULL)
  {
    if(temp->date != NULL){
      printf("%s: %s;\n", temp->title, temp->date);
    }
  temp = temp->next;
}
}