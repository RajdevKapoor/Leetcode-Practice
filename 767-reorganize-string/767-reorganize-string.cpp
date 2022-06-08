class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int> m;
        int n = s.size();
        
        for(char c: s){
            m[c]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto it : m){
            pq.push({it.second, it.first});
        }
        
        string ans = "";
        
        while(pq.size()>0){
            auto tp = pq.top();
            pq.pop();
            tp.first--;
            ans+=tp.second;
            
            if(pq.size()>0){
                auto tp2 = pq.top();
                pq.pop();
                ans+=tp2.second;
                tp2.first--;
                if(tp2.first>0){
                    pq.push(tp2);
                }
            }
            
            if(tp.first>0){
                pq.push(tp);
            }
            
        }
        
        if(ans[n-1]==ans[n-2]) return "";
        return ans;
        
    }
};