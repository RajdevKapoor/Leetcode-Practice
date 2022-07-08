class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        unordered_set<long long> s(nums.begin(),nums.end());
        
        map<long long,long long> mp;
        
        for(auto n:s){
            
            if(s.count(n-1)) continue;
            
            long long checNext=n;
            while(s.count(checNext)){
                mp[n]++;
                checNext++;
            }}
            
            vector<string> ans;
            string str;
            for(auto m:mp){
                
                str=to_string(m.first);
                if(m.second>1){
                    str+="->" + to_string(m.first+m.second-1);
                }
                ans.push_back(str);
            }
            
            return ans;
            
        
        
    }
};