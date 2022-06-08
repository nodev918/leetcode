#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

typedef struct node Node;

int main(int argc,char *argv[]){
  Node a,c,b;
  Node *ptr=&a;
  
  a.data = 12;
  a.next = &b;
  b.data = 30;
  b.next = &c;
  c.data = 64;
  c.next = NULL;

  while(ptr!=NULL){
    printf("%p|",ptr);
    printf("[%d|",ptr->data);
    printf("%p]-> ",ptr->next);
    ptr = ptr -> next;
  }

  return 0;

}
