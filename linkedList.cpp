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

int main(void) {
    Node* head = new Node(5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertInMiddle(head, 10, 3);
    printLL(head);

    return 0;
}
