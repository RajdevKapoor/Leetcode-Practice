class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set <int> s(nums.begin(),nums.end());
        int count;
        int ans=0;
        
        for(auto current:nums){
            if(s.find(current-1)!=s.end()){
                continue;
            }else{
                
                int n=current;
                count=1;
                
                while(s.find(n+1)!=s.end()){
                    count++;
                    n++;
                }
            }
            
           if(count>ans){
               ans=count;
           }
        }
        
        return ans;
        
    }
};