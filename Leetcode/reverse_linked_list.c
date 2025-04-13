struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;

    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    struct ListNode* prev = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;     
}
