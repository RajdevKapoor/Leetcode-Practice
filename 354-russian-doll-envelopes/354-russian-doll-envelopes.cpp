class Solution {
public:
    static bool sortbyCond(vector<int>& a,const vector<int>& b){
            if (a[0] != b[0])
                return (a[0] < b[0]);
            else
                return (a[1] > b[1]);
        }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),sortbyCond);
        
        int n=envelopes.size();
        vector<int>nums;
        for(int i=0;i<n;i++)
            nums.push_back(envelopes[i][1]);
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>ans.back())
                ans.push_back(nums[i]);
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
        
        
    }
};