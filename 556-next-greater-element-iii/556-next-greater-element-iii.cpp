class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        if(!nextPermutation(nums)) return -1;
        long long result=stoll(nums);
        return (result>INT_MAX || result<=n)? -1:result;
    }
private:
    bool nextPermutation(string& nums) {
        if(nums.empty()) return false;
        int i=nums.size()-1;
        while(i>=1 && nums[i-1]>=nums[i]) i--;
        if(i==0) return false; // no next permutation, i.e. already largest
        
        int j=nums.size()-1;
        while(nums[j]<=nums[i-1]) j--;
        swap(nums[i-1],nums[j]);
        
        reverse(nums.begin()+i,nums.end());
        return true;
    }
};