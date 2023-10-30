class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()==1){
            return 0;
        }
        if(arr[0] == arr[arr.size()-1]){
            return 1;
        }
        
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        
        int ans = 0;
        queue<int> q;
        q.push(0);
        while(q.size()){
            ans++;
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                auto parent = q.front(); q.pop();
                
                if (parent - 1 >= 0 and mp.find(arr[parent - 1]) != mp.end()) {
                    q.push(parent - 1);
                }
                
                if(parent + 1< arr.size() and mp.find(arr[parent+1]) != mp.end()){
                    if(parent+1==arr.size()-1){
                        return ans;
                    }
                    q.push(parent + 1);
                }
                
                if (mp.find(arr[parent]) != mp.end()) {
                    for (auto k : mp[arr[parent]]) {
                        
                            if (k == arr.size() - 1) return ans;
                            q.push(k);
                        
                    }
                }
                
                mp.erase(arr[parent]);
            }
        }
        
        
        return ans;
    }
};