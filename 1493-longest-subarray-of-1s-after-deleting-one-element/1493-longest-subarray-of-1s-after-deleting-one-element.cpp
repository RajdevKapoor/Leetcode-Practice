class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=1;
        int left=0;
        int right=0;
        int count=0;
        int maxlen=0;
        while(right<nums.size())
        {
            if(nums[right]==0) count++;
            while(count>k)
            {
                if(nums[left]==0) count--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right+=1;
        }
        return maxlen-1;
        
    }
};