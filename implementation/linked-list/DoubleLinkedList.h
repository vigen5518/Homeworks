#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* prev;
    Node* next;

    explicit Node(int val);
};

class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void append(int data);
    void prepend(int data);
    void remove(int data);
    void display();
};

#endif
