/*
Implement my own hashtable
1) Define new structure with key and value
functions I need:
1. insert()
2. delete()
3. find()
*/
#include <iostream>
#include <vector>
#include <string>
template <typename K, typename V>
class HashNode {
  private:
    K key;
    V val;
    HashNode* next;
  public:
    HashNode(K key, V val) : key(key), val(val), next(nullptr) {}
    K getkey() {return key;}
    V getval() {return val;}
    void setval(V value) {val = value;}
    void setnext(HashNode* h) {next = h;}
    HashNode* getnext() {return next;}
};
template <typename K, typename V>
class HashTable {
  private:
    static const int table_size = 100;
    std::vector<HashNode<K, V>*> table;
    int hash_function(K key) {return static_cast<int>(key) % table_size;}
  public:
    HashTable() : table(table_size, nullptr) {}
    void find(K key, V val) {
      int bucket_num = hash_function(key);
      HashNode<K, V>* temp = table[bucket_num];
      while (temp != nullptr) {
        if (temp->getkey() == key && temp->getval() == val) {
          std::cout << "Element exists!" << std::endl;
          return;
        }
        temp = temp->getnext();
      }
      std::cout << "Element doesn't exists!" << std::endl;
    }
    void insert(K key, V val) {
      int bucket_num = hash_function(key);
      HashNode<K, V>* temp = table[bucket_num];
      HashNode<K, V>* prev = table[bucket_num];
      if (temp == nullptr) {
        //HashNode<K, V> h = HashNode<K, V>(key, val); -> Segment Fault Error
        table[bucket_num] = new HashNode<K, V>(key, val);
        std::cout << "Insert first element" << std::endl;
      }
      else {
        while (temp != nullptr) {
          if (temp->getkey() == key) {
            if (temp->getval() == val) {
              std::cout << "<" << key << ", " << val << "> already exists!" << std::endl;
              return;
            }
            else {
              temp->setval(val);
              std::cout << "Value replaced!" << std::endl;
              return;
            }
          }
          prev = temp;
          temp = temp->getnext();
        }
        prev->setnext(new HashNode<K, V>(key, val));
        std::cout << "New element added by chaining!" << std::endl;
      }
    }
    void del(K key) {
      int bucket_num = hash_function(key);
      HashNode<K, V>* temp = table[bucket_num];
      HashNode<K, V>* prev;
      while (temp != nullptr) {
        if (temp->getkey() == key) {
          if (temp == table[bucket_num]) {
            table[bucket_num] = temp->getnext()? temp->getnext() : nullptr;
            std::cout << "Key deleted!" << std::endl;
            return;
          }
          else {
            prev->setnext(temp->getnext());
            std::cout << "Key deleted!" << std::endl;
            return;
          }
        }
        prev = temp;
        temp = temp->getnext();
      }
      std::cout << "Key doens't exist!" << std::endl;
    }
};
int main() {
  HashTable<int, std::string> map;
  map.insert(3, "HAHAHA");
  map.insert(3, "AHAHAH");
  map.insert(4, "HEHEHE");
  map.insert(103, "HOHOHO");
  map.find(3, "HAHAHA");
  map.find(103, "HOHOHO");
  map.find(3, "AHAHAH");
  map.del(3);
  map.find(3, "AHAHAH");
  map.insert(3, "AHAHAH");
  map.find(3, "AHAHAH");
  map.find(103, "HOHOHO");
}