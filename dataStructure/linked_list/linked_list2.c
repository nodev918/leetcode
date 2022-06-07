#include<stdio.h>
#include<stdlib.h>

#define MAXLENGTH 500

struct Node{
  int value;
  struct Node* next;
};
int* get_user_input();
int  length_of(int*);

void print_list(struct Node* node);
struct Node* make_node(int* target, int target_length);



int main(){
  
  struct Node* head = NULL;
  struct Node* second = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  head->value = 1;
  head->next = second;
  second->value = 2;

  int* inputs;
  inputs = get_user_input(); 
  int array_length = length_of(inputs);

  for (int i=0;i<array_length;i++){
    printf("array element: %d\n",*(inputs+i));
  }

  struct Node* node = NULL;
  node = (struct Node*)malloc(sizeof(struct Node));
  node = head;
  node = make_node(inputs,array_length);
  //print_list(node);  




//  struct Node* kk = NULL;
//  kk = (struct Node*)malloc(sizeof(struct Node));
//  kk->value = user_input;
//  second->next = kk; 



/*
  printf("head val: %d\n",head->value);
  printf("second val: %d\n",second->value);
  print_list(head);
*/

  return 0;
}


int* get_user_input(){
  int user_input=0;
  static int inputs[MAXLENGTH];
  int flag = 0;
  while(user_input!=-1){
    printf("input node val: \n");
    scanf("%d",&user_input);
    inputs[flag] = user_input;
    flag++;
  } 
  return inputs;
}

int length_of(int* in){
  int* inputs;
  inputs = in;
  int flag = 0;
  while( *(inputs+flag)!=0 ){
    //printf("target: %d\n",*(inputs+flag)); 
    flag++;
  }
  flag--;
  printf("flag= %d\n",flag);
  return flag;
}
struct Node* make_node(int* target, int target_length){
  
  int i=0;
  printf("target: \n");
//  for(;i<target_length;i++){
//    printf("%d -> ",*(target+i));
//  }
  printf("target_length: %d \n",target_length);
  struct Node* head = NULL;
  struct Node* n = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));
  n = (struct Node*)malloc(sizeof(struct Node));
  head = n;
  for (;i<target_length-1;i++){
    n->value = *(target+i);
    n = n->next;
  } 
  n->value = *(target+i);
  return head;
}


void print_list(struct Node* node){
  printf("hhhhhh\n");
  struct Node* current = NULL;
  current = (struct Node*)malloc(sizeof(struct Node));
  current = node;

  while(current!=NULL){
    printf("hihihih\n");
    //printf("current val: %d\n",current->value);
    printf("%d -> ",current->value);
    current = current->next;  
   
  }
}
