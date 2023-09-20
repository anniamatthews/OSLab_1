#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  int x;
  printf("Write your Tests for your linked list implementation\n");
 
  list_t* mylist = list_alloc();
  list_print(mylist);
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);

  printf("after adding 10 elements:\n");
  list_print(mylist);

  
  printf("Test: list_add_to_front\n");
  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
    printf("list_add_to_front : FAILED\n");
  }else{printf("list_add_to_front : PASSED\n");}

  // printf("remove element from index 3:\n");
  list_remove_at_index(mylist, 3);
  // char* result = listToString(mylist);
  // printf("result: %s\n", result );
  
  printf("Test: list_remove_at_index\n");
  if(strcmp("100->90->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
    printf("list_remove_at_index : FAILED\n");
  }else{printf("list_remove_at_index : PASSED\n");}

  list_remove_at_index(mylist, 1);
  list_remove_at_index(mylist, 6);
   
  if(strcmp("90->70->60->50->40->20->10->NULL",listToString(mylist)) != 0)
  {
    printf("list_remove_at_index : FAILED\n");
  }else{printf("list_remove_at_index test 2 : PASSED\n");}
  
  list_print(mylist);
  printf("The list length is %d\n", list_length(mylist));

  printf("Test: list_length\n");
  if(list_length(mylist) != 7){
    printf("list_length : FAILED\n");
  }else{printf("list_length : PASSED\n");}

  list_add_to_back(mylist, 39);
  list_print(mylist);
  list_add_to_back(mylist, 18);
  list_add_to_back(mylist, 42);
  list_add_to_back(mylist, 190);
  list_print(mylist);

  printf("Test: list_add_to_back\n");
  // add a test for add to back right here 
  if(strcmp("90->70->60->50->40->20->10->39->18->42->190->NULL",listToString(mylist)) != 0)
  {
    printf("list_add_to_back : FAILED\n");
  }else{printf("list_add_to_back : PASSED\n");}

  printf("Test: list_free\n");
  list_free(mylist);
  if(strcmp("NULL",listToString(mylist)) != 0)
  {
    printf("list_free : FAILED\n");
  }else{printf("list_free : PASSED\n");}

   
  printf("adding at indexes\nif index number > num elements in list it will add at the end\nif index == 0 it will not add to list\n");
  list_add_at_index(mylist, 21, 1);
  list_print(mylist);
  list_add_at_index(mylist, 65, 2);
  list_print(mylist);
  list_add_at_index(mylist, 10, 15000);
  list_print(mylist);
  list_add_at_index(mylist, 10, 4);
  list_print(mylist);
  list_add_at_index(mylist, 10, 0);
  list_print(mylist);
  
  printf("Test: list_add_at_index\n");
  if(strcmp("21->65->21->10->10->NULL",listToString(mylist)) != 0)
  {
    printf("list_add_at_index : FAILED\n");
  }else{printf("list_add_at_index: PASSED\n");}

  
  printf("tests: list_is_in\n");
  printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  printf("Is %d in the list?: %d\n", 50, list_is_in(mylist, 50));
  printf("Is %d in the list?: %d\n", 10, list_is_in(mylist, 10));

  printf("tests: list_get_elem_at\n**returns -1 if index DNE\n");
  list_print(mylist);
  printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(mylist, 3));
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  printf("Value at %d in the list?: %d\n", -2, list_get_elem_at(mylist, -2));
  printf("Value at %d in the list?: %d\n", 12, list_get_elem_at(mylist, 12));
  printf("Value at %d in the list?: %d\n", 7, list_get_elem_at(mylist, 7));



  printf("tests: list_get_index_of\n**returns -1 if value not in list\n**returns first index if value is frequent\n");
  list_print(mylist);
  printf("Index of %d?: %d\n", 21, list_get_index_of(mylist, 21));
  printf("Index of %d?: %d\n", 65, list_get_index_of(mylist, 65));
  printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));

  printf("Index of %d?: %d\n", 0, list_get_index_of(mylist, 0));
  printf("Index of %d?: %d\n", 90, list_get_index_of(mylist, 90));
  printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));


  printf("........resetting list.......\n");
  list_free(mylist);
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);

  list_print(mylist);

  
  list_remove_from_back(mylist);
  list_remove_from_back(mylist);
  list_remove_from_back(mylist);
  list_remove_from_back(mylist);
  list_remove_from_back(mylist);

  printf("Test: list_remove_from_back\n");
  if(strcmp("100->90->80->70->60->NULL",listToString(mylist)) != 0)
  {
    printf("list_remove_from_back : FAILED\n");
  }else{printf("list_remove_from_back : PASSED\n");}



  
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 60);
  list_print(mylist);
  list_add_at_index(mylist, 50, 1);
  list_add_at_index(mylist, 0, 6);
  list_add_at_index(mylist, 70, 0);
  list_add_at_index(mylist, 80, 12);
  list_print(mylist);

  printf("tests for removing from front\n");
  list_remove_from_front(mylist);
  list_remove_from_front(mylist);
  list_remove_from_front(mylist);
  list_remove_from_front(mylist);
  list_remove_from_front(mylist);
  list_remove_from_front(mylist);
  list_remove_from_front(mylist);

  list_remove_at_index(mylist, 5);
  list_print(mylist);

  char* result8 = listToString(mylist);
  printf("result: %s\n", result8 );

  printf("Test: list_remove_from_front\n");
  if(strcmp("100->90->80->70->60->NULL",listToString(mylist)) != 0)
  {
    printf("list_remove_from_front : FAILED\n");
  }else{printf("list_remove_from_front : PASSED\n");}
  
 
  
  return 0;
}
