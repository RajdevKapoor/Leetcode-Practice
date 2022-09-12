class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int size=nums.size();
        
        vector<vector<int>> ans;
        
        for(int i=0 ; i<size-1 ; i++){
            
            int a=i+1,b=size-1;
            
            int sum=0-nums[i];
            
            while(a<b){
                
                if(nums[a]+nums[b]==sum){
                    
                    ans.push_back({nums[i],nums[a],nums[b]});
                    a++;b--;
                    while(a<b && nums[a-1]==nums[a]) a++;
                    while(b>a && nums[b+1]==nums[b]) b--;
                    
                    //a++; b--;
                }
                else if(nums[a]+nums[b]>sum) b--;
                else a++;
            }
            while((i<size-1)&&(nums[i+1]==nums[i])) i++;
        }
        return ans;
    }
};