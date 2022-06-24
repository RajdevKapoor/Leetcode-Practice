class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        if (s.length() < 11) return {};
        
        unordered_map<string,int> mp;
        vector<string> ans;
        
        for(int i=0;i+10<=s.length();i++){
            string str = s.substr(i,10);
            mp[str]++;

        }
        
        for(auto m:mp){
            if(m.second>1){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};