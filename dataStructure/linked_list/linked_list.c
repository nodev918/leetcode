#include<stdio.h>
#include<stdlib.h>

struct Node{
  int value;
  struct Node* next;
};

int main(){
  struct Node* head;
  head->value = 1;
  struct Node* second;
  head->next = second;
  second->value = 2;
  second->next = NULL;
  
  struct Node* point;
  point = head;
  while(point != NULL){
    printf("%d\n",point.value);
    point = point.next;
  }
  

  printf("%d\n",head.value);
  return 0;
}
