#include <iostream>
#include <utility>
#include <list>
#include <unordered_map>
class LRUcache {
  private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_cache;
    std::list<std::pair<int, int>> m_list;
    size_t capacity;
    int size;
  public:
    LRUcache(size_t num) : capacity(num) {}
    int get(int key) {
      auto find_iter = m_cache.find(key);
      if (find_iter == m_cache.end()) {
        return -1;
      }
      m_list.splice(m_list.begin(), m_list, find_iter->second);
      return find_iter->second->second;
    }
    void put(int key, int value) {
      auto find_iter = m_cache.find(key);
      if (find_iter != m_cache.end()) {
        m_list.splice(m_list.begin(), m_list, find_iter->second);
        find_iter->second->second = value;
      }
      if (size == capacity) {
        int key_to_erase = m_list.back().first;
        m_list.pop_back();
        m_cache.erase(key_to_erase);
        size--;
      }
      m_list.emplace_front(key, value);
      m_cache[key] = m_list.begin();
      size++;
    }
};