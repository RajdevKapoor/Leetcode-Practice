class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if (num == 1) return true;
        
        long long nums = num;
        
        long long l = 1, r = num;
        
        while (l <= r){
            long long mid = l + (r - l) / 2;
            
            if (mid * mid == nums) {
                return true;
            }
            
            else if (mid * mid > nums){
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return false;
    }
};