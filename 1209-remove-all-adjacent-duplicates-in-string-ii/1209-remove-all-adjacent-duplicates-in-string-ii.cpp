class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack <pair<char,int>> st;
        
        for(auto c : s ){
            if(st.empty()==true){
                st.push(make_pair(c,1));
            }else if(st.top().first !=c){
                st.push(make_pair(c,1));
            }
            else{
               if(st.top().second == k-1 ){
                   st.pop();
               }else{
                   st.top().second += 1;
               }
            }
        }
        
        string ans="";
        
        while(st.size()>0){
            while(st.top().second>0){
            ans += st.top().first;
                st.top().second -=1;
            }
            st.pop();
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};