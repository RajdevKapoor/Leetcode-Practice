class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sum=0,ans=0,l=0,r=0,n=nums.size();
        unordered_map<int, int> mp;
        
        while(r<n){
            int right = nums[r];
            sum+=right;
            mp[right]++;
            
            while(mp[right]>1){
                int left = nums[l];
                sum-=nums[l];
                mp[left]--;
                l++;
            }
            r++;
            ans = max(ans, sum);
            
        }
        
        return ans;
        
    }
};