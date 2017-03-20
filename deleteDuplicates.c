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
	struct ListNode* a = malloc(sizeof(struct ListNode));
  a->val = 4;
  printf("value is %d ", a->val);
  return 1;
}