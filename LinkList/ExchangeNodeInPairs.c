#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
}ListNode;

void create_tail(ListNode *head) {
  ListNode *p = head;
  while (p->next) {
    p = p->next;
  }

  ListNode *s = (ListNode *)malloc(sizeof(ListNode));
  s->next = NULL;
  scanf("%d", &s->val);
  p->next = s;
}

struct ListNode* swapPairs(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode* dummyHead=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next=head;
    struct ListNode* cur=dummyHead;
    struct ListNode* next=head;
    while(cur->next&&cur->next->next){
        struct ListNode* temp=next->next->next;
        cur->next=cur->next->next;
        cur->next->next=next;
        next->next=temp;
        cur=cur->next->next;
        next=cur->next;
    }
    return dummyHead->next;
}

struct ListNode* swapPairs2(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode* newhead=head->next;
    head->next=swapPairs(newhead->next);
    newhead->next=head;
    return newhead;
}

void show(ListNode *l) { // 遍历链表并打印
  ListNode *p = l;
  if (p->next == NULL)
    printf("链表为空");
  else {
    while (p != NULL) {

      printf("%d ", p->val);
      p = p->next;
    }
  }
}

int main() {
  struct ListNode *head = (ListNode *)malloc(sizeof(ListNode));
  head->val = 1;
  for (int i = 0; i < 3; i++) {
    create_tail(head);
  }
  show(head);
  struct ListNode *res = swapPairs(head);
  show(res);
  return 0;
}