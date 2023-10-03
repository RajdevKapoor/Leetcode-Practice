class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>map;
        
        for(auto n:nums){
            map[n]++;
        }
        
        int ans=0;
        for(auto m:map){
            if(m.second==1){
                continue;
            }
            
            ans+= (m.second*(m.second-1))/2;
        }
        
        return ans;
    }
};