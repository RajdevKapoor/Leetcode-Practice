class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        int diff = 0; // different characters at each position
        
        unordered_set<char> a, b;
        
        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diff++;
            a.insert(s1[i]);
            b.insert(s2[i]);
        }
        
        return (diff == 0 || diff == 2) && a == b;
    }
};