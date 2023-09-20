// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { // works 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;

  return mylist;

}

void list_free(list_t *l) { // tested 
  node_t* temp; 
  while(l->head){
    temp=l->head; 
    l->head = temp->next; 
    free(temp);
  }
}

// helper function to allocate memory for a new node
node_t *create_new_node(elem val){ // doesn't need to be tested 
  node_t* allocated_node = (node_t*)malloc(sizeof(node_t));
  allocated_node->value = val; 
  allocated_node->next = NULL; 
  return allocated_node;
}

void list_print(list_t *l) { // doesn't really need a test 
  node_t *curr = l->head; 

  if(!curr){
    printf("List is empty\n");
  }
  while(curr!=NULL){
    printf("%d ", curr->value);
    curr=curr->next;
  }
  printf("\n");
  
}

char * listToString(list_t *l) { // built for testing 
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) {  // tested 
  node_t *curr = l->head;  
  int counter = 0; 
  while(curr != NULL){
    counter++; 
    curr = curr->next; 
  }
  return counter; 
}

void list_add_to_back(list_t *l, elem value) { // tested
  if(l->head){ // if there are already existing elements in the list
    node_t *curr = l->head; 
    while(curr->next != NULL){
      curr = curr->next; 
    }
    node_t* new=create_new_node(value);
    curr->next=new;
  }
  else{ // if there are no elements on the list 
    node_t* new=create_new_node(value);
    new->next = l->head; 
    l->head = new; 
  }
}


void list_add_to_front(list_t *l, elem value) { // tested 
  node_t* new_node = create_new_node(value);
  if (l->head!=NULL){
    new_node->next = l->head;
    l->head = new_node;
  }
  else{
    l->head = new_node;
  }
}

void list_add_at_index(list_t *l, elem value, int index) { //tested 
  node_t* new_node = create_new_node(value);
  if(index <= 0){
    return;
  }
  if(index > list_length(l)){
    list_add_to_back(l,value);
  }
  if(l->head != NULL && index == 1){
    new_node->next = l->head; 
    l->head = new_node;
  }
  else if(l->head == NULL){
    l->head = new_node;
  }
  else{
    node_t* curr = l->head; 
    node_t* prev = NULL; 
    int i = 1; 
    while(curr!= NULL && i <index){
      i++; 
      prev = curr; 
      curr = curr->next; 
    }
    if(curr == NULL && i == index){ 
      list_add_to_back(l, value);
    }
    else if(i == index){
      new_node->next = prev->next; 
      prev->next = new_node; 
    }
  }
}

elem list_remove_from_back(list_t *l) { // done
  if(l->head != NULL){
    node_t* remove = NULL; 
    remove = l->head; 
    node_t* prev = NULL; 
    while (remove->next) {
      prev = remove;
      remove = remove->next;
    }
    prev->next = remove->next; 
    elem val = remove->value;
    free(remove);
    return val; 
  }
  else { return -1; }
}

elem list_remove_from_front(list_t *l) { // tested 
  if(l->head){
    node_t* remove = l->head;
    l->head = remove->next; 
    elem val = remove ->value; 
    free(remove);
    return val; 
  }

  else { return -1; }
}

elem list_remove_at_index(list_t *l, int index) {  // tested 
  int n = list_length(l);
  if (index == 1){
    return list_remove_from_front(l);
  }
  else if(index == n){
    return list_remove_from_back(l);
  }
  if(index < 1 || index > n){
    return -1; 
  }
  if (l->head){
    node_t* remove = l->head;
    node_t* prev = NULL; 
    int i = 1; 
    while(remove && i < index){
      i++; 
      prev = remove; 
      remove = remove->next; 
    }
    if (!remove && i == index){
      return list_remove_from_back(l);
    }
    else if(i == index){
      elem var = remove->value; 
      prev->next = remove->next; 
      free(remove); 
      return var; 
    }
    
  }
  else{ return -1; } 
}

bool list_is_in(list_t *l, elem value) {  // tested 
  if(!l->head){
    return false; 
  }
  else{
    node_t* curr = l->head;
    while(curr){
      if(curr->value == value){
        return true; 
      }
      curr = curr->next; 
    }
  }
  
  return false; 
}

elem list_get_elem_at(list_t *l, int index) {  // tested
  if(index <= 0 || index > list_length(l)){
    return -1; 
  }
  if(l->head){
    node_t* curr = l->head; 
    int i = 1; 
    while (curr){
      if(i == index){
        return curr-> value;
      }
      i++; 
      curr = curr->next; 
    }
  }
  else{ return -1; }
}

int list_get_index_of(list_t *l, elem value) {  // tested 
  if(!list_is_in(l,value)){
    return -1;
  }
  if(l->head){
    node_t* curr = l->head; 
    int i = 1; 
    while(curr){
      if(curr->value == value){
        return i;  // stops when it finds it the first time
      }
      i++; 
      curr = curr->next;
    }
    
  }
  else{ return -1; }
}
