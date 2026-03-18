struct node {
  int data;
  struct node *next;
}

struct Node* nodes(struct ListNode* head) {
    
    struct ListNode *temp = head;
    int count = 0;

   
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
