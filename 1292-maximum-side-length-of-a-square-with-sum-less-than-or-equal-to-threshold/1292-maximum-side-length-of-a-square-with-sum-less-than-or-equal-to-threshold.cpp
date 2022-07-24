class Solution {
public:
    int n, m;
    vector<vector<unsigned long long>> prefix;
    bool isValid(int x1, int y1, int x2, int y2, int k) {
        unsigned long long s1 = prefix[x2][y2];
        unsigned long long s2 = prefix[x1][y2];
        unsigned long long s3 = prefix[x2][y1];
        unsigned long long s4 = prefix[x1][y1];
        
        return (s1+s4)-(s2+s3) <= k;
    }
    
    bool isValid(int len, int k) {
        for (int i = len; i <= n; ++i) for (int j = len; j <= m; ++j)
            if (isValid(i-len, j-len, i, j, k)) return true;
        return false;
    }
    
    int maxSideLength(vector<vector<int>>& g, int k) {
        n = g.size(), m = g[0].size();
        prefix = vector<vector<unsigned long long>>(n+1, vector<unsigned long long>(m+1, 0));
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
            prefix[i+1][j+1] = g[i][j] + prefix[i+1][j] + prefix[i][j+1] - prefix[i][j];
        
        int lo = 0, hi = min(n, m);
        while (hi>lo and lo+1!=hi){
            int mid = lo+(hi-lo)/2;
            if (isValid(mid,k)) lo = mid;
            else hi = mid-1;
        }
        
        if (isValid(hi,k)) return hi;
        return lo;
    }
};