class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a1=nums.size();
        
        for(int i=0;i<nums.size();i++){
            a1^=i;
            a1^=nums[i];
        }
        
        return a1;
    }
};