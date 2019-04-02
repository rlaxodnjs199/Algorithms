#include <iostream>
#include <vector>
const int Table_Size = 10;
template <typename K, typename V>
class HashNode {
  K key;
  V value;
  HashNode* next;
public:
  HashNode(const K key, const V value): key(key), value(value), next(NULL) {}
  K getKey() {return key;}
  V getValue() {return value;}
  HashNode* getNext() {return next;}
  void setValue(const V val) {value = val;}
  void setNext(HashNode* ptr) {next = ptr;}
};

template <typename K>
struct KeyHash {
  unsigned long operator() (const K key) {
    return reinterpret_cast<unsigned long>(key) % Table_Size;
  }
};

template <typename K, typename V>
class Hashmap {
  std::vector<HashNode*> table;
  KeyHash<K> hashfunc;
public:
  Hashmap() : table(new HashNode<K, V> * Table_Size);
  ~Hashmap() {
    for (int i = 0; i < Table_Size; i++) {
      HashNode<K, V>* entry = table[i];
      while (entry != NULL) {
        HashNode<K, V>* prev = entry;
        entry = entry->getNext();
        delete prev;
      }
    }
    table.clear();
  }
  V findVal(const K key) {
    unsigned long hashvalue = hashfunc(key);
    HashNode<K, V>* entry = table[hashvalue];
    while (entry != NULL && entry->getKey() != key) {
      entry = entry->getNext();
    }
    return entry->getValue();
  }
  void putKey(const K key, const V val) {
    unsigned long hashvalue = hashfunc(key);
    HashNode<K, V>* entry = table[hashvalue];
    HashNode<K, V>* prev;
    while (entry != NULL && entry->getKey() != key) {
      prev = entry;
      entry = entry->getNext();
    }
    if (entry == NULL) {
      if (prev == NULL) {
        entry = new HashNode<K, V>(key, val);
      }
      else {
        prev->setNext(new HashNode<K, V>(key, val));
      }
    }
    else {
      entry->setValue(val);
    }
  }
  void removeKey(const K key) {
    unsigned long hashvalue = hashfunc(key);
    HashNode<K, V>* entry = table[hashvalue];
    HashNode<K, V>* prev = NULL;
    while (entry != NULL && entry->getKey() != key) {
      prev = entry;
      entry = entry->getNext();
    }
    if (entry == NULL) return;
    if (prev == NULL) {
      table[hashvalue] = entry->getNext();
      delete entry;
    }
    else {
      prev->setNext(entry->getNext());
      delete entry;
    }
  }
};