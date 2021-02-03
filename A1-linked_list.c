#include <stdio.h>
#include <stdlib.h>

/*
 while (cur != NULL) : 表示跳出while時，cur會在NULL
 while (cur->next != NULL) : 表示跳出while時，cur會在最後一個node
 */
typedef struct Node {
  int val;
  struct Node* next;
} ListNode;

ListNode* CreateListFromArray(int* data, const int len) {
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

void PrintList(ListNode* head) {
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

void PushFront(ListNode** head, int x) {
  ListNode* n = (ListNode*)malloc(sizeof(ListNode));
  n->val = x;
  n->next = *head;
  *head = n;
}

void PushBack(ListNode** head, int x) {
  ListNode* n = (ListNode*)malloc(sizeof(ListNode));
  n->val = x;
  n->next = NULL;

  if (*head == NULL) {  // XXXXXX
    *head = n;
    return;
  }

  ListNode* cur = *head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = n;
}

void InsertAt(ListNode** head, int x, int idx) {
  ListNode* n = (ListNode*)malloc(sizeof(ListNode));
  n->val = x;
  n->next = NULL;

  if (idx == 0) {
    n->next = *head;
    *head = n;
    return;
  }

  ListNode* prev = NULL;
  ListNode* cur = *head;
  int cur_idx = 0;
  while (cur != NULL && cur_idx < idx) {
    // cur_idx < idx 表示當cur_idx移動到==idx就會跳出，此時prev會停在idx之前
    prev = cur;
    cur = cur->next;
    cur_idx++;
  }

  if (cur_idx < idx) {
    printf("List length smaller than idx: %d, Insert at end.\n", idx);
  }

  n->next = prev->next;
  prev->next = n;
}

void Reverse(ListNode** head) {
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

void Delete(ListNode** head, int x) {
  ListNode* prev = NULL;
  ListNode* cur = *head;
  while (cur != NULL && cur->val != x) {
    prev = cur;
    cur = cur->next;
  }

  if (cur == NULL) {
    printf("Cant find delete val.\n");
  } else if (cur == *head) {
    printf("Delete head node.\n");
    *head = (*head)->next;
    free(cur);
  } else {
    printf("Delete not head node.\n");
    prev->next = cur->next;
    free(cur);
  }
  return;
}

void DeleteAll(ListNode** head) {
  ListNode* cur = *head;
  while (cur != NULL) {
    *head = (*head)->next;
    free(cur);
    cur = *head;
  }
  return;
}

int main() {
  ListNode* head = NULL;
  PrintList(head);
  Delete(&head, 3);
  PrintList(head);

  PushBack(&head, 0);
  PrintList(head);
  PushBack(&head, 4);
  PrintList(head);
  PushFront(&head, 1);
  PrintList(head);
  PushFront(&head, 2);
  PrintList(head);
  PushBack(&head, 3);
  PrintList(head);

  InsertAt(&head, 990, 0);
  PrintList(head);
  InsertAt(&head, 991, 6);
  PrintList(head);
  InsertAt(&head, 992, 2);
  PrintList(head);
  PrintList(head);
  InsertAt(&head, 999, 50);
  PrintList(head);

  Reverse(&head);
  PrintList(head);

  Delete(&head, 2);
  PrintList(head);
  Delete(&head, 3);
  PrintList(head);
  Delete(&head, 5);
  PrintList(head);

  DeleteAll(&head);
  PrintList(head);

  return 0;
}

/*
 ---
 This is an empty list.
 Cant find delete val.
 This is an empty list.
 0
 0 4
 1 0 4
 2 1 0 4
 2 1 0 4 3
 3 4 0 1 2
 Delete not head node.
 3 4 0 1
 Delete head node.
 4 0 1
 Cant find delete val.
 4 0 1
 This is an empty list.
 */
