class Solution {
public:
    bool isPerfectSquare(int nums) {
        
        int ans = sqrt(nums);
        
        return ans*ans==nums;
        
    }
};