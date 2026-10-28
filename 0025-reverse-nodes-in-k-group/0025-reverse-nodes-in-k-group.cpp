class Solution {
    ListNode* findKthNode(ListNode* temp, int k) {
        while (temp != NULL && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* rev(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newNode = rev(head->next);

        head->next->next = head;
        head->next = NULL;

        return newNode;
    }

    public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        ListNode* nextnode;
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp != NULL) {
            ListNode* kthnode = findKthNode(temp, k);

            if (kthnode == NULL) {
                if (prev) prev->next = temp;
                break;
            }

            nextnode = kthnode->next;
            kthnode->next = NULL;

            rev(temp);

            if (temp == head) {
                head = kthnode;
            } else {
                prev->next = kthnode;
            }

            prev = temp;
            temp = nextnode;
        }

        return head;
    }
};
