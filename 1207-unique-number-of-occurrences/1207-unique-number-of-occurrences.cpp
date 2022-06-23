class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        unordered_set<int> freq;
        
        for(auto i:arr){
            map[i]++;
        }
    
        for(auto i:map){
            if(freq.find(i.second)!=freq.end()){
                return false;
            }
            freq.insert(i.second);
        }
        return freq.size()==map.size();
    }
};