class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i=0;i<matrix.size();i++){
            
            if(!(target >= matrix[i][0] and target <= matrix[i][matrix[0].size()-1])) continue;
            auto it = find(matrix[i].begin(),matrix[i].end(),target);
            
            if(it!=matrix[i].end()){
                return true;
            }
        }
        
        return false;
        
    }
};