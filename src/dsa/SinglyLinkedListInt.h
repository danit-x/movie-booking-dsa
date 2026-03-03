#ifndef SINGLYLINKEDLISTINT_H
#define SINGLYLINKEDLISTINT_H

#include <iostream>
using namespace std;

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

public:
    SinglyLinkedListInt();
    ~SinglyLinkedListInt();

    void insertLast(int value);
    int removeValue(int value);
    int contains(int value) const;
    void print() const;
    void clear();

    Node *getHead() const;
    int getSize() const;
};

#endif
