class Solution {
public:
     vector<vector<int>>ans;
    void helper(vector<int>& candidates, int target, vector<int> v, int sum, int ind){      
        if(sum == target){
            ans.push_back(v);
            return;
        }
        int n = candidates.size();
        for(int i=ind+1; i<n; i++){            
            if(i > ind+1 and candidates[i] == candidates[i-1])
                continue;
            if(sum + candidates[i] > target)
                break;
            v.push_back(candidates[i]);
            helper(candidates, target, v, sum+candidates[i], i);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, {}, 0, -1);
        return ans;
    }
};