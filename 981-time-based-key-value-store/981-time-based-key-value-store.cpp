class TimeMap {
public:
    TimeMap() {}
    
    void set(const string& key, const string& value, int timestamp) {
        store[key].emplace_back(timestamp,value);
    }
    
    string get(const string& key, int timestamp) {
        if(store.count(key)) {
            for(auto it=store[key].crbegin(); it!=store[key].crend(); ++it)
                if(it->first<=timestamp) return it->second;
        }
        return {};
    }
private:
    unordered_map<string,vector<pair<int,string>>> store;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */