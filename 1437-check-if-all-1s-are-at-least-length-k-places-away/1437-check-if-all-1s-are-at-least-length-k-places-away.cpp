class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;
    
        for(int i = 0; i < nums.size(); i++) {
          if(nums[i] == 1 and prev == -1) {
            prev = i;
          } else if(nums[i] == 1) {
            if(i-prev-1 < k) return false;
            prev = i;
          }
        }

        return true;
    }
};