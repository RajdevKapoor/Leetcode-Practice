class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int crrIdx = abs(nums[i])-1;
            if(nums[crrIdx]>0){
                nums[crrIdx]*=-1;
            }else{
                ans.push_back(abs(nums[i]));
            }
        }
        
        return ans;
        
    }
};