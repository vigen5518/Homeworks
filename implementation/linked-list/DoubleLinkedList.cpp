#include "LinkedList.h"
#include <iostream>

Node::Node(int val) : data(val), next(nullptr) {}

DoubleLinkedList::DoubleLinkedList() : head(nullptr) {}

DoubleLinkedList::~DoubleLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DoubleLinkedList::append(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void DoubleLinkedList::prepend(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DoubleLinkedList::remove(int data) {
    if (head == nullptr) return;

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != data) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        current->next->next->prev = current;
        delete temp;
    }
}

void DoubleLinkedList::display() {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
