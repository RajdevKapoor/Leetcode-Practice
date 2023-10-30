class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n=s.length();
        set<int> toSkip;
        stack<int> st;
        
        for(int i=0;i<n;i++){
            
            if(s[i]==')'){
                
                if(st.empty()){
                    toSkip.insert(i);
                }else{
                    st.pop();
                }
                
            }else if(s[i]=='('){
                st.push(i);
            }
            
        }
        
        while(st.size()){
            toSkip.insert(st.top());
            st.pop();
        }
        
        string ans="";
        
        for(int i=0;i<n;i++){
            if(toSkip.count(i)){
                continue;
            }
            ans+=s[i];
        }
        
        return ans;
        
    }
};