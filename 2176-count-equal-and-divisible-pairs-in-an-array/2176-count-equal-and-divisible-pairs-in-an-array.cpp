class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        
        unordered_map<int,vector<int>> map;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            
            if(map.count(nums[i])){
                
                for(auto v:map[nums[i]]){
                    if((v*i)%k==0){
                        ans++;
                    }
                }
                
            }
            map[nums[i]].push_back(i);
            
            
        }
        
        return ans;
        
    }
};