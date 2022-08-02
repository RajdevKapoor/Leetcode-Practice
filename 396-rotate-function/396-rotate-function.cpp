class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int preSum = 0;
        
        int cur = 0;
        for(int i = 0; i < n; ++i){
            cur += i * nums[i];
            preSum += nums[i];
        }
        int ans = cur;
        for(int i = 1; i < n; ++i){
            
            cur -= n*nums[n-i];
            cur += preSum;
            ans = max(ans, cur);
        }
        return ans;
    }
};