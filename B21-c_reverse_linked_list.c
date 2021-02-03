#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node* next;
} ListNode;

ListNode* createListFromArray(int* data, const int len) {
  ListNode* head = NULL;
  ListNode* prev = NULL;
  for (int i = 0; i < len; ++i) {
    ListNode* n = (ListNode*)malloc(sizeof(ListNode));
    n->val = data[i];
    n->next = NULL;
    if (head == NULL) {
      head = n;
    }
    if (prev != NULL) {
      prev->next = n;
    }
    prev = n;
  }
  return head;
}

void printList(ListNode* head) {
  if (head == NULL) {
    printf("This is an empty list.\n");
    return;
  }
  ListNode* cur = head;
  while (cur != NULL) {
    printf("%d ", cur->val);
    cur = cur->next;
  }
  printf("\n");
}

void reverseList(ListNode** head) {
  if (*head == NULL || (*head)->next == NULL) {
    printf("List dont need to reverse.\n");
    return;
  }

  ListNode* prev = NULL;
  ListNode* cur = *head;
  ListNode* next = NULL;
  while (cur->next != NULL) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  cur->next = prev;
  *head = cur;
}

void deleteAll(ListNode** head) {
  ListNode* cur = *head;
  while (cur != NULL) {
    *head = (*head)->next;
    free(cur);
    cur = *head;
  }
  return;
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ListNode* head = createListFromArray(a, 9);
  printList(head);
  reverseList(&head);
  printList(head);
  deleteAll(&head);
  return 0;
}
