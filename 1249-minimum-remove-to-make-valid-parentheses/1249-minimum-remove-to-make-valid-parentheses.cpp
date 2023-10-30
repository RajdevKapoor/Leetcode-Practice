class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        unordered_set<int> indices;
        stack<pair<char,int>> st;
        
        for(int i=0;i<n;i++){
            if(s[i]==')' && st.empty()){
                indices.insert(i);
            }
            else if(s[i]==')' && !st.empty()){
                st.pop();
            }
            else if(s[i]=='('){
                st.push(make_pair(s[i],i));
            }
        }
        
        while(!st.empty()){
            indices.insert(st.top().second);
            st.pop();
        }
        
        string x="";
        for(int i=0;i<n;i++){
            if(indices.find(i)==indices.end()){
                x+= s[i];
            }
        }

        return x;
        
    }
};