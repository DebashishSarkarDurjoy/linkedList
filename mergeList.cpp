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

Node* merge(Node* a, Node* b) {
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }

    Node* c = NULL;
    if (a->data < b->data) {
        c = a;
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }

    return c;
}

int main(void) {
    //1-> 5 -> 7 -> 10 -> NULL
	// 2 , 3, 6

	Node* a = NULL;
	insertAtHead(a,10);
	insertAtHead(a,7);
	insertAtHead(a,5);
	insertAtHead(a,1);

	Node* b = NULL;
	insertAtHead(b,6);
	insertAtHead(b,3);
	insertAtHead(b,2);
	Node* head = merge(a,b);
	printLL(head);


    return 0;
}
