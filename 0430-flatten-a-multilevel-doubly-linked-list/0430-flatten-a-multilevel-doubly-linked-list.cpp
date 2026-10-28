/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* temp = head;

        while (temp != NULL) {
            if (temp->child != NULL) {
                Node* nextNode = temp->next;

                Node* childHead = flatten(temp->child);

                temp->next = childHead;
                childHead->prev = temp;
                temp->child = NULL;

                Node* tail = childHead;
                while (tail->next != NULL) {
                    tail = tail->next;
                }

                if (nextNode != NULL) {
                    tail->next = nextNode;
                    nextNode->prev = tail;
                }
            }

            temp = temp->next;
        }

        return head;
    }
};
