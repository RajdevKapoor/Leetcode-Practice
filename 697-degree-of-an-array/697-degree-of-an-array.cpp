#include<bits/stdc++.h>
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        int degree = 0, res = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
            degree = max(degree, (int)m[nums[i]].size());
        }
        for(auto it : m) {
            if(it.second.size() == degree)
                res = min(res, it.second[degree - 1] - it.second[0]+1);
        }
        return res;
    }
};