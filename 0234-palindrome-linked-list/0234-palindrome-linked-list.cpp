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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* secound = newHead;
        
        while(secound != NULL){
            if(first->val != secound->val){
                reverseList(newHead);
                return false;
            }
            first = first->next;
            secound = secound->next;
        }
        
        reverseList(newHead);
        return true;
    }
};