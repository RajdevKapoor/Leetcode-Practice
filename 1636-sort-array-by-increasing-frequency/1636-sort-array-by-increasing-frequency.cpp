class Solution {
public:
    
    static bool mycmp(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
    
    
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> mapp;
        for(int i=0; i<nums.size(); i++)
            mapp[nums[i]]++;
        
        vector<pair<int, int>> v;
        
        for(auto i: mapp)
        {
            v.push_back({i.first, i.second});
        }
        
        sort(v.begin(), v.end(), mycmp);
        vector<int> ans;
        
        for(auto i:v)
        {
            for(int j=0; j<i.second; j++)
            {
                ans.push_back(i.first);
            }
        }
        
        return ans;
        
    }
};