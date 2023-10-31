class Solution {
public:
    int minSteps(string s, string t) {
        
    unordered_map<char, int> sm, tm;

    for (int i = 0; i < s.length(); i++)
    {
        sm[s[i]]++;
        sm[t[i]]--;
    }
    int ans = 0;
    for (auto m : sm)
    {
        if (m.second >= 0)
        {
            ans += m.second;
        }
    }
    return ans;
        
    }
};

    