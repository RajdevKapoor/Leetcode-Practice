class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int crrIdx = abs(nums[i])-1;
            if(nums[crrIdx]>0){
                nums[crrIdx]*=-1;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        
        return ans;
        
    }
};