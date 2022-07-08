class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r = *max_element(nums.begin(), nums.end());
        int l = 1;
        int ans;
        while(l<=r){
            int m = (l+r)/2;
            if(numOp(nums, m,maxOperations)){
                ans=m;
                r = m-1;
            } 
            else l = m + 1;
        }
        return ans;
    }
private:
    bool numOp(vector<int>& nums, int m,int maxOperations){
        int ans = 0;
        for(int i{}; i<nums.size(); i++){
            if(nums[i] >= m){
                int s = (nums[i]%m == 0)?(nums[i]/m):(nums[i]/m + 1);
                ans += s-1;
                if(ans>maxOperations) return false;
            }
        }
        return ans<=maxOperations;
    }
};