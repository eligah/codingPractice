//146. LRU Cache
#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>

#include "tmp.h"

using namespace std;

class LRUCache {
 private:
  struct CacheNode {
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {}
  };

 public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    if (cache_map.find(key) == cache_map.end()) return -1;
    cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
    cache_map[key] = cache_list.begin();

    return cache_map[key]->value;
  }

  void put(int key, int value) {
    if (cache_map.find(key) == cache_map.end()) {
      if (cache_list.size() == capacity) {
        cache_map.erase(cache_list.back().key);
        cache_list.pop_back();
      }
      cache_list.push_front(CacheNode(key, value));
      cache_map[key] = cache_list.begin();
    } else {
      cache_map[key]->value = value;
      cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
      cache_map[key] = cache_list.begin();
    }
  }

 private:
  list<CacheNode> cache_list;
  unordered_map<int, list<CacheNode>::iterator> cache_map;
  int capacity;
};

int main() {
  LRUCache cache(3);

  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;  // returns 1
  cache.put(3, 3);               // evicts key 2
  cout << cache.get(2) << endl;  // returns -1 (not found)
  cache.put(4, 4);               // evicts key 1
  cout << cache.get(1) << endl;  // returns -1 (not found)
  cout << cache.get(3) << endl;  // returns 3
  cout << cache.get(4) << endl;  // returns 4
}