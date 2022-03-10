class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        
        int ans=0;
        
       
        
        for(int i=0;i<a.size();i++){
             int temp=0;
            for(int j=0;j<a[0].size();j++){
                temp += a[i][j];
            }
            
            ans=max(ans,temp);
        }
        
        
        return ans;
        
    }
};