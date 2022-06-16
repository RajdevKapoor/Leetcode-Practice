class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0)
            return m*n;
        
        int minx = INT_MAX;
        int miny = INT_MAX;
        
        for(auto o:ops){
            minx=min(minx,o[0]);
            miny=min(miny,o[1]);
        }
        
        return minx*miny;
    }
};