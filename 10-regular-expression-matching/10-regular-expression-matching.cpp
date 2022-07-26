class Solution {
public:
    vector<vector<int>> memo;
    
    bool isMatch(string& s, int i, string& p, int j){
        if(i < 0){
            if(j < 0) return true;
            if(p[j] != '*') return false;
            return isMatch(s, i, p, j - 2);
        }
        if(j < 0) return false;
        if(memo[i][j] != -1) return memo[i][j];
        
        if(p[j] == '.' || s[i] == p[j]) memo[i][j] = isMatch(s, i-1, p, j-1);
        else if(p[j] == '*'){
            if(p[j-1] == '.' || p[j-1] == s[i]) memo[i][j] = isMatch(s, i-1, p, j);
            if(memo[i][j] != 1) memo[i][j] = isMatch(s, i, p, j-2);
        }
        else memo[i][j] = 0;
        
        return memo[i][j];
    }
    
    bool isMatch(string s, string p) {
        memo.resize(s.size(), vector<int>(p.size(), -1));
        return isMatch(s, (int)s.size() - 1, p, (int)p.size() - 1);
    }
};