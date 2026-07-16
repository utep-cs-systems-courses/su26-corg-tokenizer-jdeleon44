#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *list = malloc(sizeof(List));
  list -> root = NULL;
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  //Create new item token and use malloc
  Item *newItem = malloc(sizeof(Item));
  int len = 0;
  while(str[len] != '\0'){
    len++;
  }
    
  // Use copy_str from tokenizer.h to copy the string
  newItem->str = copy_str(str, len);
  newItem->next = NULL;
  if(list->root == NULL){
    newItem->id = 1;
    list->root = newItem;
    return;
  }
    
  //If list is empty, set as root
  if(list->root == NULL){
    newItem->id = 1;
    list->root = newItem;
    return;
  }
    
  //Create a current token and set it as the next one to get the last token
  Item *current = list->root;
  while(current->next != NULL){
    current = current->next;
  } 
  // Add new item at the end
  newItem->id = current->id + 1;
  current->next = newItem;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *current = list->root;
  while(current != NULL){
    if(current->id == id){
      return current->str;
    }
      current = current->next;
  }
  return NULL;
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *current = list->root;
  while(current != NULL){
    printf("%d. %s\n", current->id, current->str);
    current = current->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *current = list->root;
  while(current != NULL){
    Item *temp = current;
    current = current->next;
    free(temp->str);
    free(temp);
  }
  //Free the list
  free(list);
}
