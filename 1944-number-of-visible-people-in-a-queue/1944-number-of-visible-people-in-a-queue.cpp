class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> ans;
        ans.push_back(0);
        stack<int> st;
        st.push(heights[n - 1]);
        
        for(int i=n-2;i>=0;i--){
            int c =0;
            while(st.size() and heights[i]>st.top()){
                c++;
                st.pop();
            }
            
            if(st.size()){
                 ans.push_back(c+1);
            }else{
                ans.push_back(c);
            }
            
            st.push(heights[i]);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
