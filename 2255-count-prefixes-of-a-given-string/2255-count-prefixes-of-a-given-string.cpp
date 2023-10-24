class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (auto& str : words)
            ans += s.substr(0, str.size()) == str;
        return ans;
    }
};