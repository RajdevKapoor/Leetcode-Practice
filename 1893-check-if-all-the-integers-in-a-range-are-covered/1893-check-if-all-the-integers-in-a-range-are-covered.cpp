class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        
        
        for(int i=left;i<=right;i++){
            bool flag = false;
            for(auto r:ranges){
                if(i>=r[0] and i <=r[1]){
                    flag = true;
                    break;
                }
            }
          if(flag==false){
              return false;
          }
            
        }
        
        return true;
        
    }
};