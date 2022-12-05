// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_HASHTABLE_H
#define HW5_HASHTABLE_H
#include <iostream>
#include <string>
#include <set>
#include <fstream>

static const int MAX_DEFAULT = 991;

template<class T>
class HashTable {
    friend std::ostream& operator<<(std::ostream& ostream, const HashTable<T>& hash) {
        for (int i = 1; i < hash.tableSize; i++) {
            if (hash.Table[i]) {
                ostream << "[" << i << "] [" << *hash.Table[i]->nodeData->data << "]" << std::endl;
            }
        }
        return ostream;
    }
public:
    HashTable();
    ~HashTable();
    virtual int getHashIndex(T* key) const;
    bool insert(T* item);
    bool remove(T* item);
    void clear();
    bool contains(T* search) const;
    T* get(T* search) const;
    int getNumOfItems() const;
    bool isEmpty() const;
    int size() const;

protected:
    struct Node {
        T* data;
        Node* next;
        int key;
    };

    struct HashTableNode {
        int count;
        Node* nodeData;
    };

    HashTableNode** Table;
    int count;
    int tableSize;
};

template<class T>
HashTable<T>::HashTable() {
    tableSize = MAX_DEFAULT;
    Table = new HashTableNode*[MAX_DEFAULT];
    for (int i = 0; i < tableSize; i++) {
        Table[i] = NULL;
    }
}

template<class T>
HashTable<T>::~HashTable() {
    for(int i = 0; i < tableSize; i++) {
        if (Table[i]) {
            delete Table[i]->nodeData->data;
            delete Table[i]->nodeData;
            delete Table[i];
        }
    }
    delete Table;
}

template<class T>
int HashTable<T>::getHashIndex(T *key) const {
    return key->hash() % tableSize;
}

template<class T>
bool HashTable<T>::insert(T *item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = NULL;

    HashTableNode* newHash = new HashTableNode;
    int hashIndex = getHashIndex(item);
    newNode->key = hashIndex;

    newHash->nodeData = newNode;
    Table[hashIndex] = newHash;

    return true;
}

template<class T>
bool HashTable<T>::remove(T *item) {
    return true;
}

template<class T>
void HashTable<T>::clear() {

}

template<class T>
bool HashTable<T>::contains(T *search) const {
    int hash = getHashIndex(search);

    return Table[hash] != NULL;
}

template<class T>
T* HashTable<T>::get(T *search) const {
    if (contains(search)) {
        return Table[getHashIndex(search)]->nodeData->data;
    }

    return NULL;
}

template<class T>
int HashTable<T>::getNumOfItems() const {
    return 0;
}

template<class T>
bool HashTable<T>::isEmpty() const {
    return false;
}

template<class T>
int HashTable<T>::size() const {
    return tableSize;
}

#endif //HW5_HASHTABLE_H
