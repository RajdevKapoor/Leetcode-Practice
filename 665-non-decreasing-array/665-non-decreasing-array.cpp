class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int count=0;
        
        for(int i=0;i+1<nums.size();i++){
            if(nums[i]>nums[i+1]){
                count++;
            }
            if(i-2>=0 && i+1<nums.size() && nums[i-2]>nums[i] && nums[i-1]>nums[i+1]) return false;
            if(count==2){
                return false;
            }
        }
        
        return true;
        
    }
};