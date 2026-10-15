class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != nullptr && temp2 != nullptr) {
            int val;

            if (temp1->val <= temp2->val) {
                val = temp1->val;
                temp1 = temp1->next;
            } else {
                val = temp2->val;
                temp2 = temp2->next;
            }

            ListNode* newNode = new ListNode(val);

            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }

        while (temp1 != nullptr) {
            ListNode* newNode = new ListNode(temp1->val);

            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }

            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            ListNode* newNode = new ListNode(temp2->val);

            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }

            temp2 = temp2->next;
        }

        return head;
    }
};
