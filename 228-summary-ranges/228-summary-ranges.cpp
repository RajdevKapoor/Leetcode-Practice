class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0) return ans;
        bool flag = false;
        string s ;
        
        for(int i=0;i<n-1;i++){
            if(nums[i] +1 != nums[i+1] && !flag){
                ans.push_back(to_string(nums[i]));
                flag = false;
            }
            else if (nums[i] +1 == nums[i+1] && !flag){
                s +=  to_string(nums[i]) + "->";
                flag = true;
            }
            else if (nums[i] +1 != nums[i+1] && flag){
                s += to_string(nums[i]);
                flag = false;
            }
           if(s != "" && flag == false){
               ans.push_back(s);
               s = "";
           }
        }
        if(flag){
             s += to_string(nums[n-1]);
            ans.push_back(s);
            flag = false;
        } else{
            ans.push_back(to_string(nums[n-1]));
        }
        return ans;
    }
};