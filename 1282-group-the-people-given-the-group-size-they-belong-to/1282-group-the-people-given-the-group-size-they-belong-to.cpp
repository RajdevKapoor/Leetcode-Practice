class Solution {
public:
    vector<vector<int>> partitionVector(const vector<int>& originalVector, int k) {
        vector<vector<int>> result;
        int n= originalVector.size();
        for (int i = 0; i < n; i += k) {
            vector<int> subVector(originalVector.begin() + i, originalVector.begin() + min(i + k, n));
            result.push_back(subVector);
        }
        return result;
    }
    vector<vector<int>> groupThePeople(vector<int>& gp) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<gp.size();i++){
            mp[gp[i]].push_back(i);
        }
        
        vector<vector<int>> ans;
        for(auto m:mp){
            auto temp = partitionVector(m.second,m.first);
            for(auto t:temp){
                ans.push_back(t);
            }
        }
        
        return ans;
    }
};