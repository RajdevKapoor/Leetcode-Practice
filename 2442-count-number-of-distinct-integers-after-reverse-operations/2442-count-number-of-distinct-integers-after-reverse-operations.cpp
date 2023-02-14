class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            string num = to_string(nums[i]);
            reverse(num.begin(), num.end());
            nums.push_back(stoi(num));
        }
        
        unordered_set <int> us(nums.begin(), nums.end());
        return us.size();
    }
};