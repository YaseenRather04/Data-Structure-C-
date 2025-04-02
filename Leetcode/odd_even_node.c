/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {

    if(head == NULL || head->next == NULL) return head;

   
    struct ListNode* head1 = NULL;
    struct ListNode* head2 = NULL;

    struct ListNode* mover1 = head1;
    struct ListNode* mover2 = head2;

    struct ListNode* temp = head;

    int i = 1;

    while(temp != NULL){

        if(i % 2 == 1){

            if(head1==NULL)
                head1 = mover1 = temp;
            else{
                mover1->next = temp;
                mover1 = mover1->next;
            }
        }
        else{
            if(head2==NULL)
                head2 = mover2 = temp;
            else{
                mover2->next = temp;
                mover2 = mover2->next;
            }
        }
        i++;
        temp = temp->next;
    }
    mover2->next=NULL;
    mover1->next=head2;
    return head1;
    
}
