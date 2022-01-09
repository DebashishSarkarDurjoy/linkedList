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

int main(void) {
    Node* head = new Node(5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printLL(head);

    return 0;
}
