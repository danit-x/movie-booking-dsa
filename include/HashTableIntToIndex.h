#ifndef HASHTABLEINTTOINDEX_H
#define HASHTABLEINTTOINDEX_H

class HashTableIntToIndex
{
private:
    struct Node
    {
        int key;
        int index;
        Node *next;
    };

    Node **buckets;
    int bucketCount;
    int size;

    int hash(int key) const;

public:
    HashTableIntToIndex();
    ~HashTableIntToIndex();

    void init(int bucketCountValue);
    void put(int key, int index);
    int get(int key, int &outIndex) const;
    int remove(int key);
    void clear();

    int getSize() const;
};

#endif