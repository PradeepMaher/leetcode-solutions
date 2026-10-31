class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL) return head;

        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){

            if(curr->val == curr->next->val){

                ListNode* del = curr->next;
                curr->next = curr->next->next;

                delete del;
            }
            else{
                curr = curr->next;
            }
        }

        return head;
    }
};