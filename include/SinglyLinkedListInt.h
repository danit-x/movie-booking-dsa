#ifndef SINGLYLINKEDLISTINT_H
#define SINGLYLINKEDLISTINT_H

#include <iostream>

class SinglyLinkedListInt
{
public:
    struct Node
    {
        int value;
        Node *next;
    };

private:
    Node *head;
    Node *tail;
    int size;
    // No need for a separate tail pointer if we only insert at the end, but it can make insertions more efficient.

public:
    SinglyLinkedListInt();
    ~SinglyLinkedListInt();

    void insertLast(int value);
    bool removeValue(int value);
    bool contains(int value) const;
    void print() const;
    void clear();

    Node *getHead() const;
    int getSize() const;
    bool isEmpty() const;

    SinglyLinkedListInt(const SinglyLinkedListInt &) = delete;
    SinglyLinkedListInt &operator=(const SinglyLinkedListInt &) = delete;
};

#endif