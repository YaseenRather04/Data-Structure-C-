/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* constructor(int data){
    
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));

    temp->val = data;
    temp->next = NULL;
    return temp;

}


struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;

    struct ListNode* newListhead = NULL;
    struct ListNode* temp = head;

    while(temp != NULL){

        struct ListNode* newNode = constructor(temp->val);

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
