class Solution {
public:
    string removeDuplicates(string s) {
        
        stack <char> st;
        
        string ans="";
        
        for(auto c : s){
            
            if(st.empty()==true){
                st.push(c);
            }            
            else if(c != st.top()){
                st.push(c);
            }
            else{
                st.pop();
            }
        }
        
        while(st.size()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
        
    }
};