struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;

    struct ListNode* newListhead = NULL;
    struct ListNode* temp = head;

    while(temp != NULL){

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode->val = temp->val;
        newNode->next = NULL;

        if(newListhead == NULL){
            newListhead = newNode;
        }

        else{
            newNode->next = newListhead;
            newListhead = newNode;
        }
        temp = temp->next;
    }

    return newListhead;
    
}
