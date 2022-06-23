class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int  mini = nums[0];
        while(low <= high)
        {
            while(low < high && nums[low] == nums[low + 1])
            {
                low++;
            }
            
            while(low < high && nums[high] == nums[high - 1])
            {
                high--;
            }
            
            if(nums[low] < nums[high])
            {
                mini = min(mini, nums[low]);
                
                break;
            }
            
            int mid = low + (high - low) / 2;
            
            mini = min(mini, nums[mid]);
            
            if(nums[mid] >= nums[low])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return mini;
    }
};