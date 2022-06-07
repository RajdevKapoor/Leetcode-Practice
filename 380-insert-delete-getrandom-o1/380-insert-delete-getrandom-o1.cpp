class RandomizedSet {
public:
    unordered_set<int> S;
    
    RandomizedSet() {
        S.clear();
    }
    
    bool insert(int val) {
        
        if(S.find(val) == S.end())
        {
            S.insert(val);
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
        
        if(S.find(val) != S.end())
        {
            S.erase(val);
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        
        int r = rand()%S.size();
        
        auto it = S.begin();
        
        while(r--)
            it++;
        
        return *it;
    }
};