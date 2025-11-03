#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;

    explicit Node(int val);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void append(int data);
    void prepend(int data);
    void remove(int data);
    void display();
};

#endif
