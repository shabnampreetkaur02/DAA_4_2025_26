#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

Node* head = nullptr;


void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insertAtBeg(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}


void insertLast(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


void insertAtPos(int val, int pos) {
    if (pos == 1) {
        insertAtBeg(val);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;
}


void deleteByValue(int val) {
    Node* temp = head;
    while (temp != nullptr && temp->data != val) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Value not found" << endl;
        return;
    }
    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next; 

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}

int main() {
    insertAtBeg(10);
    insertLast(20);
    insertLast(30);
    insertAtBeg(40);
    insertAtPos(88, 2); 
    display();               

    deleteByValue(40);
    display();               

    deleteByValue(20);
    display();               

    return 0;
}