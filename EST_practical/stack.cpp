#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* pointer;
};

Node* head = new Node();

void Enqueue(Node* queue, int k) {
    if (queue==head) {
        head->data=k;
        head->pointer=nullptr;
    }
    while (queue->pointer!=nullptr) {
        queue = queue->pointer;
    }
    queue->data =k;
    queue->pointer = nullptr;
}

void Dequeue(Node* queue) {
    if (queue==nullptr) {
        cout<<"Queue is empty"<<endl;
    }
    cout<<queue->data<<endl;
    queue= queue->pointer;
}

bool isEmpty(Node* queue) {
    if (queue==nullptr) {
        return true;
    }
    else {
        return false;
    }
}