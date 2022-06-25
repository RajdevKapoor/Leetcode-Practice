class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> mp1;
        map<string, int> mp2;
        
        map<string, int> m;
        vector<string> ans;
        
        for(int i = 0; i < list1.size(); i++){
            mp1[list1[i]] = i + 1;
        }
        for(int i = 0; i < list2.size(); i++){
            mp2[list2[i]] = i + 1;
        }
        
        int key;
        int minm = INT_MAX;
        
        for(auto i = mp1.begin(); i != mp1.end(); i++){
            if(mp2.count(i -> first) > 0){
                key = mp2[i -> first] + i -> second;
                minm = min(minm, key);
                m[i -> first] = key;
            }
        }
        
        for(auto i = m.begin(); i != m.end(); i++){
            if(minm == i-> second){
                ans.push_back(i -> first);
            }
        }
        
        return ans;
        
    }
};