/*线性表追加合并*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node* Init_list(Node* head) { // 初始化链表
  head = (Node*)malloc(sizeof(Node));
  head->data=0;
  head->next = NULL;
  return head;
}
void Create_Tail(Node* head){
  Node* p=head;
  while(p->next){
    p=p->next;
  }
  Node* s=(Node*)malloc(sizeof(Node)); 
  s->next=NULL;
  scanf("%d",&s->data);
  p->next=s;

}
Node* Find_Index(Node* head){
  
}
