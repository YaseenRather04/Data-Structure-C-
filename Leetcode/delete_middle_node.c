 int count(struct ListNode* head){
    int i = 0;
    struct ListNode* temp = head;
    while(temp != NULL){
        i++;
        temp = temp->next;
    }
    return i;
 }
struct ListNode* deleteMiddle(struct ListNode* head) {

    int size = count(head);
    int middle = size / 2;

    if(middle == 0) return NULL;

    else {
        int i = 1;
        struct ListNode* temp = head;
        while(i < middle && temp->next != NULL){
            i++;
            temp = temp->next;
        }
        if (temp->next != NULL && middle >= 0)
        {
            struct ListNode* t = temp->next;
            temp->next = temp->next->next;
            free(t);
        }

        return head;
    }

}
