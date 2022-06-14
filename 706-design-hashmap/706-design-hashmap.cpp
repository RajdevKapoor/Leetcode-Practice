class MyHashMap {
public:
    vector<pair<int,int>>res;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        
        for(int i=0;i<res.size();i++){
            if(res[i].first==key){
                res[i].second=value;
                return;
            }
        }
        
        res.push_back({key,value});
        
    }
    
    int get(int key) {
        for(auto r:res){
            if(r.first==key and r.second!=-1){
                return r.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0;i<res.size();i++){
            if(res[i].first==key){
                res[i].second=-1;
            }
        }
    }
};