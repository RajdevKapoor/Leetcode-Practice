class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.length();i++){
            char c = s[i];
            mp[c]=i;
        }
        
        char c = s[0];
        int max = mp[c];
        
        for(int i=0;i<s.length();i++){
            c=s[i];
            if(mp[c]>max){
                max=mp[c];
            }
            
            if(i==max){
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