class Solution {
public:
    
    vector<string> getWords(string s) {
        string tmp;
        vector<string> res;
        
        for ( auto u : s ) {
            if ( isspace(u) ) {
                res.push_back(tmp);
                tmp.clear();
            }
            else {
                tmp += u;
            }
        }
        
        if ( !tmp.empty() ) res.push_back(tmp);
        return res;
    }
    
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v1 = getWords(s1);
        vector<string> v2 = getWords(s2);
        vector<string> ans;
        
        unordered_map<string, int> cnt;
        for ( auto u : v1 ) cnt[u]++;
        for ( auto u : v2 ) cnt[u]++;
        
        for ( auto u : cnt ) {
            if ( u.second == 1 ) ans.push_back(u.first);
        }
        
        return ans;
    }
};