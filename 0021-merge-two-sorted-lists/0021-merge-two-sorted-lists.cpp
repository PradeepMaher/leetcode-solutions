/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* addAtLast(ListNode* head, int val){
        if(head == NULL){
            return new ListNode(val, head);
        }

        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        ListNode* newNode = new ListNode(val);
        temp->next = newNode;
        return head;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head = NULL;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 != NULL && temp2 != NULL){
            int val =0;
            if( temp1->val <= temp2->val){
                val = temp1->val;
                temp1 = temp1->next;
            }else{
                val = temp2->val;
                temp2 = temp2->next;
            }
            head = addAtLast(head, val);
        }

        while(temp1 != NULL){
            int val = temp1->val;
            head = addAtLast(head, val);
            temp1 = temp1->next;
        }

        while(temp2 != NULL){
            int val = temp2->val;
            head = addAtLast(head, val);
            temp2 = temp2->next;
        }

        return head;
    }
};