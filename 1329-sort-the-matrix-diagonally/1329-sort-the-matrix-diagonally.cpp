class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> temp(min(m,n), 0);
        int numdiag = m+n-1;
        
        for(int d = 0; d < numdiag; d++) {
            
            // starting rows are 0, 1 ... m.
            int row =  d < m ? d : 0;
            
            // starting cols are 0, 1 ... n.
            int col = d < m ? 0 : d-m+1;
            
            temp.clear();
            
            // copy the content of the diagonal to the vector.
            int index = 0;
            for (int i = row, j = col; i < m and j < n; i++, j++) {
                temp[index++] = mat[i][j];    
            }
            
            sort(temp.begin(), temp.begin()+index);
            
            // copy the contents of the sorted temp vector back to the diagonal.
            index = 0;
            for (int i = row, j = col; i < m and j < n; i++, j++) {
                mat[i][j] = temp[index++];
            }
        }
        
        return mat;
    }
};