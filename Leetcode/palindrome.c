bool isPalindrome(struct ListNode* head) {
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;

    struct ListNode* curr = slow;
    struct ListNode* next = NULL;
    struct ListNode* prev = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    while(prev != NULL){
        if(prev->val != fast->val) return false;
        else{
            prev = prev->next;
            fast = fast->next;
        }
    }
    return true;
}
