class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n=s.length();
        unordered_map<char,int> map;
        
        for(int i=0;i<n;i++){
            map[s[i]]=i;
        }
        
        
        char c = s[0];
        int effectOfc = map[c];
        
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            c=s[i];
            
            effectOfc=max(effectOfc,map[c]);
            
            if(i==effectOfc){
                ans.push_back(i);
            }
            
        }
        
        for(int i=ans.size()-1;i>0;i--){
            ans[i]-=ans[i-1];
        }
        ans[0]++;
        
        return ans;
        
    }
};