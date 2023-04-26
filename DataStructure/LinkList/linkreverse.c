#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

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

/* 使用数组记录节点 */
struct ListNode *reverseList(struct ListNode *head) {
  struct ListNode *arr[5001];
  struct ListNode *p = head;
  int i;
  if (head == NULL) {
    return head;
  }
  for (i = 0; p; i++) {
    arr[i] = p;
    p = p->next;
  }
  int end = i - 1;
  for (i -= 1; i > 0; i--) {
    arr[i]->next = arr[i - 1];
  }
  arr[0]->next = NULL;
  return arr[end];
}

/* 头插法创建新链表 */
struct ListNode *reverseList2(struct ListNode *head) {
  struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
  res->val = head->val;
  struct ListNode *old = head;
  struct ListNode *new = res;
  if (old == NULL) {
    return old;
  }
  old = old->next;
  while (old) {
    struct ListNode *s = (struct ListNode *)malloc(sizeof(struct ListNode));
    s->val = old->val;
    s->next = new;
    new = s;
    old = old->next;
  }
  return new;
}

/* 双指针 */
struct ListNode *reverseList3(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  ListNode *pre = NULL;
  ListNode *cur = head;
  ListNode *next = head->next;
  while (next) {
    cur->next = pre;
    pre = cur;
    cur = next;
    next = next->next;
  }
  cur->next = pre;
  return cur;
}

/* 递归 */
struct ListNode *reverseList4(struct ListNode *head) {
  if (head->next == NULL || head == NULL) {
    return head;
  }
  ListNode *ret = reverseList4(head->next);
  head->next->next = head;
  head->next = NULL;
  return ret;
}

/* 妖魔化双指针 */
struct ListNode *reverseList5(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  ListNode *pre = head;
  ListNode *cur = head->next;
  ListNode *next = cur->next;
  while (next) {
    cur->next = pre;
    head->next = next;
    pre = cur;
    cur = next;
    next = next->next;
  }
    head->next=NULL;
    cur->next = pre;
  return cur;
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
  struct ListNode *res = reverseList(head);
  show(res);
  return 0;
}