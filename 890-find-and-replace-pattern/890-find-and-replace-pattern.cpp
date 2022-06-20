class Solution {
public:
    bool solve(string s1,string s2){
        unordered_map<char,char> mp1,mp2;
        if(s1.size()!=s2.size()){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            if(mp1.find(s2[i])==mp1.end()&&mp2.find(s1[i])==mp2.end()){
                mp1[s2[i]]=s1[i];
                mp2[s1[i]]=s2[i];
            }
         
            else{
                if(mp1.find(s2[i])!=mp1.end()&&mp1[s2[i]]!=s1[i]){
                    return false;
                }
                if(mp2.find(s1[i])!=mp2.end()&&mp2[s1[i]]!=s2[i]){
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> v;
        for(int i=0;i<words.size();i++){
            if(solve(words[i],pattern)){
                v.push_back(words[i]);
            }
        }
        return v;
    }
};