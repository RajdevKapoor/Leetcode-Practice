class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        map<int, int> mp;
        set<int> zeros;
        int n = rains.size(); 
        vector<int> ans(n);
        
        for(int i=0;i<rains.size();i++){
            int el = rains[i];
        
        
        if(el==0){
            zeros.insert(i);
        }else{
            ans[i]=-1;
            if(mp.find(el) == mp.end()){
                mp[el] = i;
            }else{
                int last_index = mp[el];
                auto it = zeros.upper_bound(last_index);
                
                if(it == zeros.end()){
                    return {};
                }else{
                    int idx = *it;
                    zeros.erase(it);
                    mp[el] = i;
                    ans[idx] = el;
                }
            }
        }
            }
        
        for(auto it: zeros){
            ans[it] = 1;
        }
        
        return ans;
        
    }
};