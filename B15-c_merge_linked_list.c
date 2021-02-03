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

ListNode* mergeList(ListNode** head1, ListNode** head2) {
  if (*head1 == NULL) {
    return *head2;
  }
  if (*head2 == NULL) {
    return *head1;
  }

  ListNode* head = NULL;
  ListNode* prev = NULL;
  ListNode* cur = NULL;
  ListNode* cur1 = *head1;
  ListNode* cur2 = *head2;
  while (cur1 != NULL && cur2 != NULL) {
    if (cur1->val < cur2->val) {
      cur = cur1;
      cur1 = cur1->next;
    } else {
      cur = cur2;
      cur2 = cur2->next;
    }

    if (head == NULL) {
      head = cur;
    }
    if (prev != NULL) {
      prev->next = cur;
    }
    prev = cur;
  }

  cur = (cur1 != NULL) ? cur1 : cur2;
  if (cur != NULL) {
    if (head == NULL) {
      head = cur;
    }
    if (prev != NULL) {
      prev->next = cur;
    }
  }
  return head;
}

ListNode* mergeListRecursion(ListNode** head1, ListNode** head2) {
  if (*head1 == NULL) {
    return *head2;
  }
  if (*head2 == NULL) {
    return *head1;
  }
  ListNode* head = NULL;
  if ((*head1)->val < (*head2)->val) {
    head = *head1;
    head->next = mergeListRecursion(&(*head1)->next, head2);
  } else {
    head = *head2;
    head->next = mergeListRecursion(head1, &(*head2)->next);
  }
  return head;
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
  int a[] = {1, 3, 5, 7, 9, 11, 12, 13};
  ListNode* head1 = createListFromArray(a, sizeof(a) / sizeof(a[0]));
  printList(head1);
  int b[] = {0, 2, 4, 6, 8};
  ListNode* head2 = createListFromArray(b, sizeof(b) / sizeof(b[0]));
  printList(head2);
  // ListNode* head = mergeList(&head1, &head2);
  ListNode* head = mergeListRecursion(&head1, &head2);
  printList(head);
  deleteAll(&head);
  return 0;
}
