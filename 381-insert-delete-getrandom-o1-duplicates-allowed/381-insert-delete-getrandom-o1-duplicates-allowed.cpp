class RandomizedCollection {
public:
    unordered_multimap<int, int> mp;
    vector<pair<int, unordered_multimap<int, int>::iterator>> vals;

    RandomizedCollection() {
        mp.clear();
        vals.clear();
    }
    
    bool insert(int val) {
        auto it = mp.insert({val, vals.size()});
        vals.push_back({val, it});
        return mp.count(val) < 2;
    }

    bool remove(int val) {
        if (!mp.count(val))
            return false;
        auto it = mp.find(val);
        int idx = it->second;
        vals[idx] = vals.back();
        vals[idx].second->second = idx;
        vals.pop_back();
        mp.erase(it);
        return true;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */