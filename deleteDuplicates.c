#include <stdlib.h>
#include <stdio.h>
#include <string.h>

  struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    struct ListNode* current = head;
    while(current != NULL) {
        struct ListNode* next = current->next;
        while(next != NULL && next->val == current->val)
            next = next->next;
        current->next = next;
        current = current->next;
        
    }
    return head;
  
    
}

int main()
{
	struct ListNode* a = calloc(1, sizeof(struct ListNode));
  a->val = 4;
  if(a->next != NULL)
  printf("crash? %d", a->next->val);
  struct ListNode* b = calloc(1, sizeof(struct ListNode));
  b->val = 4;
  a->next = b;
  struct ListNode* c = calloc(1, sizeof(struct ListNode));
  c->val = 4;
  b->next = c;
  struct ListNode* d = calloc(1, sizeof(struct ListNode));
  d->val = 6;
  c->next = d;
  struct ListNode* e = deleteDuplicates(a);
  printf("value is %d and %d ", e->val, e->next->val);
  return 1;
}