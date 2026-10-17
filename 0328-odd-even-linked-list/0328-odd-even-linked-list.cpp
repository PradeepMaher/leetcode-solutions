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
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* tempodd = head;
        ListNode* tempeven = head->next;
        ListNode* evenhead = tempeven;

        while(tempeven != NULL && tempeven->next != NULL){
            tempodd->next = tempodd->next->next;
            tempeven->next = tempeven->next->next;

            tempodd = tempodd-> next;
            tempeven = tempeven->next;  
        }
        tempodd->next = evenhead;

        return head;
    }
};