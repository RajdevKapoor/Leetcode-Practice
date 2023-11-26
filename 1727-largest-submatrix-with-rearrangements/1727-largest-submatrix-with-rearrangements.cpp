class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        for(int r=0; r<m; ++r) {
            for(int c=0; c<n; ++c) {
                if(matrix[r][c] != 0 && r > 0)
                    matrix[r][c] += matrix[r-1][c];
            }
        
            vector<int> temp = matrix[r];
            sort(temp.begin(), temp.end(), greater<int>());
            for(int i=0; i<n; ++i) {
                ans = max(ans, temp[i] * (i+1));
            }
        }

        return ans;
    }
};