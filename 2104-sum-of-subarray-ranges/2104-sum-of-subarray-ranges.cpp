class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
      
        long long sum = 0;
        int mx = INT_MIN;
        int mi = INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            
            mx =nums[i];
            mi =nums[i];
            
            for(int j=i+1;j<nums.size();j++){
                
                mx = max(mx,nums[j]);
                mi = min(mi,nums[j]);
                
                sum+= mx-mi;
                
            }
            
            
        }
        
        return sum;
        
    }
};