class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(); 
        int l = 0, h = m - 1;
        
        while(l<=h){
            int midR=l+(h-l)/2;
            int maxCIdx = max_element(mat[midR].begin(), mat[midR].end()) - mat[midR].begin();
            
            if (midR < m - 1 && mat[midR][maxCIdx] < mat[midR + 1][maxCIdx])
                l = midR + 1;
            else if (midR > 0 && mat[midR][maxCIdx] < mat[midR - 1][maxCIdx])
                h = midR - 1;
            else
                return {midR, maxCIdx};
            
        }
        
        return {-1,-1};
    }
};