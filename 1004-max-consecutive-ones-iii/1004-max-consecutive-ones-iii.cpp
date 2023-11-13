class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int count=0;
        int maxlen=0;
        while(right<nums.size())
        {
            if(nums[right]==0)
                count+=1;
            while(count>k)
            {
                if(nums[left]==0)
                    count-=1;
                left+=1;
            }
            
            maxlen=max(maxlen,right-left+1);
            right+=1;
        }
        return maxlen;
    }
};