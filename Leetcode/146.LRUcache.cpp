#include <iostream>
#include <list>
#include <unordered_map> 
#include <utility> //std::pair
class LRUcache1 {
  private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_hash;
    std::list<std::pair<int, int>> m_list;
    size_t m_capacity;
    int m_size;
  public:
    LRUcache1(int num): m_capacity(num) {}
    int get(int key) {
      auto hash_key_position = m_hash.find(key);
      if (hash_key_position == m_hash.end()) {
        return -1;
      }
      auto list_key_position = hash_key_position->second;
      m_list.splice(m_list.begin(), m_list, list_key_position);
      return list_key_position->second;
    }
    void set(int key, int value) {
      auto hash_key_position = m_hash.find(key);
      if (hash_key_position != m_hash.end()) {
        auto list_key_position = hash_key_position->second;
        m_list.splice(m_list.begin(), m_list, list_key_position);
        list_key_position->second = value;
      }
      if (m_size == m_capacity) {
        int least_recently_used_key = m_list.back().first;
        m_list.pop_back();
        m_hash.erase(least_recently_used_key);
        m_size--;
      }
      m_list.emplace_front(key, value);
      m_hash[key] = m_list.begin();
      m_size++;
    }
};

#include <queue>
class LRUcache2 {
  private:
  std::unordered_map<int, std::deque<std::pair<int, int>>::iterator> hashmap;
  std::deque<std::pair<int, int>> deq;
  int size;
  int capacity;
  public:
  LRUcache2(int num) : deq(num), capacity(num), size(0) {}
  int get(int key) {
    if (hashmap.count(key)) {
      deq.push_back(*hashmap[key]);
      deq.erase(hashmap[key]);
      hashmap[key] = deq.end() - 1;
      return deq.back().second;
    }
    else return -1;
  }
  void set(int key, int value) {
    if (hashmap.count(key)) {
      if ((*hashmap[key]).second == value) {
        std::cout << "Key & Val already exists" << std::endl;
        deq.push_back(*hashmap[key]);
        deq.erase(hashmap[key]);
        hashmap[key] = deq.end() - 1;
      }
      else {
        std::cout << "Update Val" << std::endl;
        deq.push_back(std::make_pair(key, value));
        deq.erase(hashmap[key]);
        hashmap[key] = deq.end() - 1;
      }
    }
    else {
      if (size == capacity) {
        std::cout << "I'm here max capacity" << std::endl;
        hashmap.erase(deq.front().first);
        deq.pop_front();
        deq.push_back(std::make_pair(key, value));
        hashmap[key] = deq.end() - 1;
      }
      else {
        std::cout << "I'm here insert new" << std::endl;
        deq.push_back(std::make_pair(key, value));
        hashmap[key] = deq.end() - 1;
        size++;
      }
    }
  }
};

int main() {
  LRUcache2 cache(2);
  cache.set(1, 1);
  cache.set(2, 2);
  cache.set(3, 3);
  std::cout << cache.get(1);
}

/* 1.Idea
First time reading an instruction, I thought about how to combine
queue and hashtable. Because data structure of cache has to have a
FIFO property, I thought queue would be a valid approach on solving
this problem. However, queue has limit on implementing cache in O(1).
When we try to get something or put something,
the associated key and value pair has to be renewed
in priority everytime. The queue has limit on supporting this feature.
Therefore, I tried to use list and its splice function to move transfer
element in constant time. 
Hashtable has <int, list_iterator> to store key and iterator in list
and list has <int, int> pair to store key and value.
2. Things that I learned
#include <utility> to import std::pair
list.splice(iter, list): transfer all elements in list to iter position
list.splice(iter1, list, iter2): transfer elements in list in iter2 position
list.splice(iter1, list, iter2, iter3): transfer iter2~3 range
list.back(): return reference, not an iterator. Use list.back().first.
list.emplace_front(): construct element at the front of the list
  This is similar to list.push_front() but more optimized in some way.
  Not constructing and moving element as push_front() does.
hash.find(key): return iterator
hash.erase(key): erase element with key
*/