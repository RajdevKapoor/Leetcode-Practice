class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp = s+s;
        tmp = tmp.substr(1, tmp.length()-2);
        return tmp.find(s) != string::npos ? true : false;
    }
};