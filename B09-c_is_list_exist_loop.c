#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node* next;
} ListNode;

int isListExistLoop(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return 1;
    }
  }
  return 0;
}

int main() {
  ListNode* a = (ListNode*)malloc(sizeof(ListNode));
  ListNode* b = (ListNode*)malloc(sizeof(ListNode));
  ListNode* c = (ListNode*)malloc(sizeof(ListNode));
  a->next = b;
  b->next = c;
  c->next = NULL;
  printf("%d\n", isListExistLoop(a));
  c->next = a;
  printf("%d\n", isListExistLoop(a));
  free(a);
  free(b);
  free(c);
  return 0;
}
