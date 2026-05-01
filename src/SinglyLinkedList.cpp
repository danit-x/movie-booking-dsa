#include <cstddef>
#include <iostream>
#include "../include/SinglyLinkedListInt.h"

using std::cout;
using std::endl;

SinglyLinkedListInt::SinglyLinkedListInt()
    : head(NULL), tail(NULL), size(0)
{
}

SinglyLinkedListInt::~SinglyLinkedListInt()
{
    clear();
}

void SinglyLinkedListInt::insertLast(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

bool SinglyLinkedListInt::removeValue(int value)
{
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL)
    {
        if (current->value == value)
        {
            if (previous == NULL)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            if (current == tail)
            {
                tail = previous;
            }

            delete current;
            size--;
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

bool SinglyLinkedListInt::contains(int value) const
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->value == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SinglyLinkedListInt::print() const
{
    Node *current = head;
    if (current == NULL)
    {
        cout << "(empty)" << endl;
        return;
    }

    while (current != NULL)
    {
        cout << current->value;
        if (current->next != NULL)
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

void SinglyLinkedListInt::clear()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    head = NULL;
    tail = NULL;
    size = 0;
}

SinglyLinkedListInt::Node *SinglyLinkedListInt::getHead() const
{
    return head;
}

int SinglyLinkedListInt::getSize() const
{
    return size;
}

bool SinglyLinkedListInt::isEmpty() const
{
    return size == 0;
}