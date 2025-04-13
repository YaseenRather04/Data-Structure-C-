class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        struct ListNode* temp = head;

        int nodes = 0;

        while(temp != NULL){
            nodes++;
            temp = temp->next;
        }

        temp = head;

        if(nodes == 1) return head;

        else if(nodes == 2){
            return head->next;
        }
        
        else {
            int i = 1;

            if(nodes/2 % 2 == 0){
                
                while(i != nodes/2 + 1 && temp->next != NULL){
                    i++;
                    temp = temp->next;
                }
                return temp;
            }

            else if(nodes/2 % 2 == 1){
                while(i != nodes/2 && temp->next != NULL){
                    i++;
                    temp = temp->next;
                }
                
                return temp->next;
                
            }
        }

        return head;
        
    }
};
