class Solution {
public:
    
    bool count(vector<vector<int>>& matrix,int n,int k, int mid){
        int c = 0;
        for(int i = 0; i < n; i++){
            c += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return c < k;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low < high){
            
            int mid = low + (high - low)/2;
            
            
            if(count(matrix,n,k,mid)){
                low = mid + 1;
            }else{
                high = mid;
            }
            
        }
        
        return low;
    }
};