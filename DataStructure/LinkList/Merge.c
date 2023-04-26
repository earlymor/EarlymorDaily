/*线性表追加合并*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *Init_list(Node *head) { // 初始化链表
  head = (Node *)malloc(sizeof(Node));
  head->data = 0;
  head->next = NULL;
  return head;
}
void Create_Tail(Node *head) {
  Node *p = head;
  while (p->next) {
    p = p->next;
  }
  Node *s = (Node *)malloc(sizeof(Node));
  s->next = NULL;
  scanf("%d", &s->data);
  p->next = s;
  head->data++;
}

Node *Find_Index(Node *head, int index) {
  Node *p = head;
  if (index > head->data)
    return NULL;
  for (int i = 0; i < index; i++) {
    p = p->next;
  }
  return p;
}

void show(Node *head) { // 遍历链表并打印
  Node *p = head;
  if (p->next == NULL)
    printf("链表为空");
  else {
    while (p->next != NULL) {
      p = p->next;
      printf("%d ", p->data);
    }
  }
}

Node *Find_Tail(Node *head) {
  Node *p = head;
  while (p->next) {
    p = p->next;
  }
  return p;
}
int Is_Data(Node *head, int data) {
  Node *p = head;
  while (p->next) {
    if (p->data == data) {
      printf("1");
      return 1;
    }
  }
  printf("0");
  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Node *link1, *link2;
  link1 = Init_list(link1);
  link2 = Init_list(link2);
  for (int i = 0; i < n; i++) {
    Create_Tail(link1);
  }
  for (int i = 0; i < m; i++) {
    Create_Tail(link2);
  }
  printf("len1=%d\n", link1->data);
  show(link1);
  printf("\n");
  printf("len2=%d\n", link2->data);
  show(link2);
  Node *end = link1;
  while (end->next) {
    end = end->next;
  }
  printf("end=%d", end->data);

  Node *p = link2;
  p=p->next;
  while (p->next) {
    if (!Is_Data(link1, p->data)) {
      printf("len1=%d\n", link1->data);

      Node *s = (Node *)malloc(sizeof(Node));
      s->data = p->data;
      s->next = NULL;
      end->next = s;
      link2->data++;
      end = end->next;
    }
    p = p->next;
    printf("len1=%d\n", link1->data);
  }
  printf("len1=%d\n", link1->data);
  show(link1);
  printf("\n");
  printf("len2=%d\n", link2->data);
  show(link2);
}