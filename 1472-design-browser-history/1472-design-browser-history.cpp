class BrowserHistory {
public:
    class Node {
    public:
        string url;
        Node* back;
        Node* forward;

        Node(string value) {
            url = value;
            back = NULL;
            forward = NULL;
        }
    };

    Node* curr;

    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        Node* newnode = new Node(url);

        curr->forward = newnode;
        newnode->back = curr;
        curr = newnode;
    }

    string back(int steps) {
        while (steps > 0 && curr->back != NULL) {
            curr = curr->back;
            steps--;
        }
        return curr->url;
    }

    string forward(int steps) {
        while (steps > 0 && curr->forward != NULL) {
            curr = curr->forward;
            steps--;
        }
        return curr->url;
    }
};