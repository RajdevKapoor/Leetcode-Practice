class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(),m = typed.size(),i = 1, j = 1, k = 0;
        if(name[0] != typed[0] || n > m) return false;
        for(;j<m;j++)
            if(i != n && name[i] == typed[j]) i++;
            else if(name[i-1] != typed[j]) return false;
        return i == n && j == m;
    }
};