class LRUCache {
public:
  using Key = int;
  using Value = int;
  using Iter = list<pair<Key, Value>>::iterator;
  
  LRUCache(int capacity) : capacity_(capacity) {
  }

  int get(int key) {
    auto map_iter = map_.find(key);
    
    if (map_iter == map_.end()) {
      return -1;
    }
    
    Iter list_iter = map_iter->second;
    pair<Key, Value> key_val = *list_iter;  
    list_.erase(list_iter);
    
    list_.emplace_front(key_val);
    map_.insert_or_assign(key, list_.begin());
    
    return key_val.second;
  }

  void put(int key, int value) {
    auto map_iter = map_.find(key);
    
    if (map_iter == map_.end()) {
      if (map_.size() >= capacity_) {
        pair<Key, Value> LRU = list_.back();
        list_.pop_back();
        map_.erase(LRU.first);
      }
    } else {
      list_.erase(map_iter->second);
    }

    list_.emplace_front(key, value);
    map_.insert_or_assign(key, list_.begin());
  }
    
private:
  const int capacity_;
  list<pair<Key, Value>> list_;
  unordered_map<Key, Iter> map_;
};