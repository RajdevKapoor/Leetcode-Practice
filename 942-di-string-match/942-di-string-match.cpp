class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i=0;
        int j = s.length();
        vector<int> st;
        for(int m=0;m<s.length();m++){
            if(s[m]=='I'){
                st.push_back(i++);
            }
            if(s[m]=='D'){
                st.push_back(j--);
            }
        }
        if(s[s.length()-1]=='I'){
            st.push_back(i);
        }else{
            st.push_back(j);
        }
        return st;
    }
};