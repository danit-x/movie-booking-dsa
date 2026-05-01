#include <cstddef>
#include "../include/HashTableIntToIndex.h"

HashTableIntToIndex::HashTableIntToIndex()
    : buckets(NULL), bucketCount(0), size(0)
{
}

HashTableIntToIndex::~HashTableIntToIndex()
{
    clear();
}

void HashTableIntToIndex::init(int bucketCountValue)
{
    clear();

    if (bucketCountValue <= 0)
    {
        return;
    }

    bucketCount = bucketCountValue;
    buckets = new Node *[bucketCount];
    for (int i = 0; i < bucketCount; i++)
    {
        buckets[i] = NULL;
    }
}

void HashTableIntToIndex::put(int key, int index)
{
    if (buckets == NULL)
    {
        return;
    }

    int bucketIndex = hash(key);
    Node *current = buckets[bucketIndex];

    while (current != NULL)
    {
        if (current->key == key)
        {
            current->index = index;
            return;
        }
        current = current->next;
    }

    Node *newNode = new Node;
    newNode->key = key;
    newNode->index = index;
    newNode->next = buckets[bucketIndex];
    buckets[bucketIndex] = newNode;
    size++;
}

bool HashTableIntToIndex::get(int key, int &outIndex) const
{
    if (buckets == NULL)
    {
        return false;
    }

    int bucketIndex = hash(key);
    Node *current = buckets[bucketIndex];

    while (current != NULL)
    {
        if (current->key == key)
        {
            outIndex = current->index;
            return true;
        }
        current = current->next;
    }

    return false;
}

bool HashTableIntToIndex::remove(int key)
{
    if (buckets == NULL)
    {
        return false;
    }

    int bucketIndex = hash(key);
    Node *current = buckets[bucketIndex];
    Node *previous = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (previous == NULL)
            {
                buckets[bucketIndex] = current->next;
            }
            else
            {
                previous->next = current->next;
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

void HashTableIntToIndex::clear()
{
    if (buckets == NULL)
    {
        return;
    }

    for (int i = 0; i < bucketCount; i++)
    {
        Node *current = buckets[i];
        while (current != NULL)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    delete[] buckets;
    buckets = NULL;
    bucketCount = 0;
    size = 0;
}

int HashTableIntToIndex::getSize() const
{
    return size;
}

bool HashTableIntToIndex::isEmpty() const
{
    return size == 0;
}

int HashTableIntToIndex::hash(int key) const
{
    // Cast to unsigned to handle negatives and avoid INT_MIN overflow UB
    return static_cast<unsigned int>(key) % static_cast<unsigned int>(bucketCount);
}