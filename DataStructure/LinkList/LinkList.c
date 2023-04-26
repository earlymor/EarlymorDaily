#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char data;
  struct Node *next;
} Node, *LinkList;

LinkList Init_list(LinkList l) { // 初始化链表
  l = (LinkList)malloc(sizeof(Node));
  l->next = NULL;
  return l;
}

int getlen_list(LinkList l) { // 得到链表长度
  int j = 0;
  LinkList p = l;
  while (p->next) {
    p = p->next;
    j++;
  }
  return j;
}

LinkList find_index(LinkList l, int k) { // 找到第k个节点
  LinkList p = l;
  int j = 1;
  while (p != NULL && j < k) {
    p = p->next;
    j++;
  }
  if (j == k)
    return p;
  else
    return NULL;
}

LinkList find_data(char data, LinkList l) { // 找到第一个数据为data的节点
  LinkList p = l;
  while (p != NULL && p->data != data) {
    p = p->next;
  }
  return p;
}

LinkList insert_list(char data, LinkList l, int k) { // 插入到第k个节点
  if (k == 1) {
    LinkList p = (LinkList)malloc(sizeof(Node));
    p->data = data;
    p->next = l;
    return p;
  }
  LinkList p = find_index(l, k - 1);
  if (p == NULL) {
    printf("参数错误");
    return NULL;
  } else {
    LinkList s = (LinkList)malloc(sizeof(Node));
    s->data = data;
    s->next = p->next;
    p->next = s;
    return l;
  }
}

LinkList del_list(LinkList l, int k) { // 删除第k个节点
  LinkList p, s;
  if (k == 1) {
    LinkList p = l;
    typedef struct Node {
      char data;
      struct Node *next;
    } Node, *LinkList;
    if (p == NULL)
      return NULL;
    else {
      l = l->next;
      free(p);
      return l;
    }
  }
  p = find_index(l, k - 1);
  if (p == NULL) {
    printf("第%d个节点不存在", k - 1);
    return NULL;
  } else if (p->next == NULL) {
    printf("第%d个节点不存在", k);
    return NULL;
  } else {
    s = p->next;
    p->next = s->next;
    free(s);
    return l;
  }
}

void create_head(LinkList l) { // 头插法
  char ch;
  LinkList p = l;
  while (ch = getchar(), ch != '#') {
    LinkList s = (LinkList)malloc(sizeof(Node));
    s->data = ch;
    s->next = p->next;
    p->next = s;
  }
}

void create_tail(LinkList l) { // 尾插法
  char ch;
  LinkList p = l;
  while (ch = getchar(), ch != '#') {
    LinkList s = (LinkList)malloc(sizeof(Node));
    s->data = ch;
    s->next = NULL;
    p->next = s;
    p = s;
  }
}

void show(LinkList l) { // 遍历链表并打印
  LinkList p = l;
  if (p->next == NULL)
    printf("链表为空");
  else {
    while (p->next != NULL) {
      p = p->next;
      printf("%c ", p->data);
    }
  }
}

int main(int argc, char **argv) {
  LinkList l;
  l = Init_list(l);
  create_tail(l);
  printf("%d\n", getlen_list(l));
  show(l);
  return 0;
}