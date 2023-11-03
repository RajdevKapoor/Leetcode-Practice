class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {

        unordered_set<int> st(t.begin(),t.end());
        vector<string> ans;

        for(int i=1;i<=n;i++){

            if(st.count(i)){
                
                st.erase(i);
                ans.push_back("Push");
                
                if(st.size()==0){
                return ans;
            }
                
            }else{
                
            
            ans.push_back("Push");
            ans.push_back("Pop");
                
            }
            
            
            

        }
        
        return ans;
        
    }
};