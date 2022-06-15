class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN ;
        unordered_set <int> s;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]<=0){
                nums[i] = INT_MAX;
            }
            
            mini = min(mini,nums[i]);
            
            if(nums[i]!=INT_MAX){
                maxi = max(nums[i],maxi);
            }
            
            s.insert(nums[i]);
            
        }
        
        if(mini != 1){
            return 1;
        }
        
        for(int i=2;i<=n+1;i++){
            if(s.find(i)==s.end()){
                return i;
            }
        }
        return 1;
    }
};