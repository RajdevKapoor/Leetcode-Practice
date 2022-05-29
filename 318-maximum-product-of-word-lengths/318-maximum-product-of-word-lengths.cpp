class Solution {
public:
    int solve(string w){
        int ans=0;
        for(auto c:w){
            ans|= 1 << (c-'a');
        }
        return ans;
        
    }
    
    int maxProduct(vector<string>& words) {
        
        int n =words.size();
        vector <int> v(n,0);
        
        for(int i=0;i<n;i++){
            v[i]=solve(words[i]);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((v[i]&v[j])==0 and (words[i].size()*words[j].size())>ans){
                    ans=words[i].size()*words[j].size();
                }
            }
        }
        
        return ans;
        
    }
};