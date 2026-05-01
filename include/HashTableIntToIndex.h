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

    // Object is unusable until init() is called.
    void init(int bucketCountValue);

    void put(int key, int index);
    bool get(int key, int &outIndex) const;
    bool remove(int key);
    void clear();

    int getSize() const;
    bool isEmpty() const;

    HashTableIntToIndex(const HashTableIntToIndex &) = delete;
    HashTableIntToIndex &operator=(const HashTableIntToIndex &) = delete;
};

#endif