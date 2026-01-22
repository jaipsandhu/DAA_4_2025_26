#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

struct DoublyLinkedList {
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head != NULL) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int val, int pos) {
        if (pos == 1) {
            insertAtHead(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    void deleteAtHead() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    void deleteAtTail() {
        if (head == NULL) return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }

    void deleteByValue(int val) {
        if (head == NULL) return;

        Node* temp = head;

        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }

        if (temp == NULL) return;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " - ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void displayBackward() {
        if (head == NULL) return;

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        while (temp != NULL) {
            cout << temp->data << " - ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtPosition(15, 2);

    list.displayForward();
    list.displayBackward();

    list.deleteAtHead();
    list.displayForward();

    list.deleteAtTail();
    list.displayForward();

    list.deleteByValue(15);
    list.displayForward();

    return 0;
}
