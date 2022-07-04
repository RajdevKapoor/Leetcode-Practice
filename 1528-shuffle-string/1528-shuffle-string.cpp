class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        unordered_map<int,char> seen;
        for(int i=0;i<s.length();i++){
            seen[indices[i]]=s[i];
        }
        for(int i=0;i<s.length();i++){
            s[i]=seen[i];
        }
        return s;
    }
};