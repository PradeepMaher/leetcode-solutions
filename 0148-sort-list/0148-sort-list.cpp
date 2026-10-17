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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* tail = dummy;

        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if (left != NULL) tail->next = left;
        else tail->next = right;

        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two halves
        ListNode* right = slow->next;
        slow->next = NULL;

        // Recursively sort both halves
        ListNode* left = sortList(head);
        right = sortList(right);

        // Merge the sorted halves
        return merge(left, right);
    }
};