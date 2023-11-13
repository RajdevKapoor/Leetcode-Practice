class Solution {
public:
    string sortVowels(string s) {
        
        unordered_set<char> st ={'a','e','i','o','u','A','E','I','O','U'};
        vector<char> v;
        
        for(auto c:s){
            if(st.count(c)){
                v.push_back(c);
            }
        }
        
        sort(v.begin(),v.end());
        
        string ans="";
        
        int i=0;
        
        for(auto c: s){
            if(st.count(c)){
                ans+=v[i++];
            }else{
                ans+=c;
            }
        }
        
        return ans;
        
    }
};