class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string  cs="";
        for(auto it:words){
            cs+=it;
            if(cs==s) return true;
        }
        return false;
    }
};