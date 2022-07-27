class Solution {
public:
    unordered_map<string, bool> m;
    bool isScramble(string s1, string s2) {
        
        if(s1 == s2) return true;
        
        string code = s1 + '.' + s2;
        
        if(m.find(code) != m.end())
            return m[code];
        
        for(int k = 1; k < s1.size(); k++) {
            //if not swapped
            if((isScramble(s1.substr(0, k), s2.substr(0, k)) and isScramble(s1.substr(k), s2.substr(k))) or

            //if swapped
            (isScramble(s1.substr(0, k), s2.substr(s1.size() - k)) and isScramble(s1.substr(k), s2.substr(0, s1.size() - k))))
                return m[code] = true;
	    }
        
	    return m[code] = false;
    }
};