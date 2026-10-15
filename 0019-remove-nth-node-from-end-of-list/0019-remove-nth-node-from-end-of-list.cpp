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
    ListNode* removeKthElement(ListNode* head, int k) {
        if (head == NULL || k <= 0) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        if (k == 1) {
            head = head->next;
            delete temp;
            return head;
        }

        int count = 1;

        while (temp != NULL) {
            if (count == k) {
                prev->next = temp->next;
                delete temp;
                return head;
            }

            prev = temp;
            temp = temp->next;
            count++;
        }

        return head;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while( temp != NULL){
            len++;
            temp = temp->next;
        }
        int k = len - n;

        return removeKthElement(head, k+1);
    }
};