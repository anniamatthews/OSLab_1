#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  int x;
  printf("Write your Tests for your linked list implementation\n");
  list_t *mylist;
  mylist = list_alloc();

  printf("List created, printing to check status...\n");
  list_print(mylist);

  printf("adding first five elements...\n");
  list_add_to_back(mylist, 1);
  list_add_to_back(mylist, 2);
  list_add_to_back(mylist, 3);
  list_add_to_back(mylist, 4);
  list_add_to_back(mylist, 5);


  list_print(mylist);

  printf("The list length is %d\n", list_length(mylist));

  printf("adding some more elements to the front...\n");

  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);

  list_print(mylist);

  printf("adding elements at random indexes...\n");

  printf("adding 21 at index 1\n");
  list_add_at_index(mylist, 21, 1);
  list_print(mylist);
  
  
  printf("adding 10 at index 8\n");
  list_add_at_index(mylist, 10, 8);
  list_print(mylist);

  printf("adding 25 at index 4\n");
  list_add_at_index(mylist, 25, 4);
  list_print(mylist);

  printf("....\n");

  printf("The list length is %d\n", list_length(mylist));

  
  
  // printf("remove from back\n");
  // printf("%d\n",list_remove_from_back(mylist));
  // printf("%d\n",list_remove_from_back(mylist));

  // list_print(mylist);

  // printf("remove from front\n");
  // printf("%d\n", list_remove_from_front(mylist));
  // printf("%d\n", list_remove_from_front(mylist));

  // list_print(mylist);
  printf("remove at index\n");
  printf("remove item from index 5\n");
  printf("%d\n", list_remove_at_index(mylist, 5));
  list_print(mylist);

  printf("%d\n", list_remove_at_index(mylist, 25));
  list_print(mylist);
  
  // printf("check if an element is in the list\n");
  // printf("%s\n", list_is_in(mylist,10)?"true":"false");
  // printf("%s\n", list_is_in(mylist,50)?"true":"false");

  // printf("get element at certain index\n");
  // list_print(mylist);
  // printf("%d\n",list_get_elem_at(mylist, 0));
  // printf("%d\n",list_get_elem_at(mylist, 3));

  

  // printf("get index of a certain element\n");
  // list_print(mylist);
  // printf("%d\n", list_get_index_of(mylist,3));
  // printf("%d\n", list_get_index_of(mylist,20));

  // printf("free list\n");
  // list_free(mylist); 
  // list_print(mylist); 

  return 0;
}
