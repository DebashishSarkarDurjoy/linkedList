#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* n = new Node(data);
    if (head == NULL) {
        head = n;
    }
    else {
        n->next = head;
        head = n;
    }
}

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}

void insertInMiddle(Node* head, int data, int pos) {
    if (pos == 0) insertAtHead(head, data);
    else {
        Node* n = new Node(data);
        Node* current = head;
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
        }
        n->next = current->next;
        current->next = n;
    }
}

void insertAfter(int data, int data_2,  Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            Node* n = new Node(data_2);
            n->next = current->next;
            current->next = n;
            return;
        }
        else {
            current = current->next;
        }
    }
}

Node* rReverse(Node* current) {
    if (current == NULL || current->next == NULL) {
        return current;
    }

    Node* sHead = rReverse(current->next);
    current->next->next = current;
    current->next = NULL;
    return sHead;

}

int main (void) {
    Node* head = new Node(10);

    insertAtHead(head, 9);
    insertAtHead(head, 8);
    printLL(head);
    head = rReverse(head);
    printLL(head);

    return 0;
}
