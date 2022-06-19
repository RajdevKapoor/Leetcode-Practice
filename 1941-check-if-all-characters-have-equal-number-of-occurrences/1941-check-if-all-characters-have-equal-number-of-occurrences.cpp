class Solution {
public:
    bool areOccurrencesEqual(string s) {
        
        unordered_map<char,int> mp;
        
        for(auto c:s){
            mp[c]++;
        }
        
        int val = mp[s[0]];
        
        for(auto x:mp){
            if(x.second!=val){
                return false;
            }
        }
        return true;
    }
};