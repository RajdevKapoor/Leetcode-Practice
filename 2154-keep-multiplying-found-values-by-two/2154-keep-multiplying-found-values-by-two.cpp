class Solution {
public:
    int findFinalValue(vector<int>& nums, int ans) {
        
        unordered_set<int> s (nums.begin(),nums.end());
        
        while(s.count(ans)){
            ans*=2;
        }
        
        return ans;
    }
};