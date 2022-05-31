class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        vector<int> idx;
        vector<int> ans;
        while(k--)
        {
            idx.push_back(pq.top().second);
            pq.pop();
        }
        sort(idx.begin(),idx.end());
        for(int i=0;i<idx.size();i++)
        {
            ans.push_back(nums[idx[i]]);
        }
        return ans;
    }
};