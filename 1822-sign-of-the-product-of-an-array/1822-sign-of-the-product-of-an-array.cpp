class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=0;
        for(int x:nums){
            if(x==0){
                return 0;
            }
            
            if(x<0){
                ans++;
                ans%=2;
            }
                   
            
        }
        
        return ans==0 ? 1 : -1;      
        
        
    }
};