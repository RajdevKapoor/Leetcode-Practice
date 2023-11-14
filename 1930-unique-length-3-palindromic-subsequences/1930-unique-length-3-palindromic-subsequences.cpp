class Solution {
private:
    int solve(string s, char c) {
        int first=s.find(c);
        int last=s.rfind(c);
        if (first==last) return 0;
        unordered_set<char> st(s.begin()+first+1,s.begin()+last);
        return st.size();
    }
public:
    int countPalindromicSubsequence(string s){
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int ans=0;
        for(char c='a';c<='z';c++) {
            ans+=solve(s,c);
        }
        return ans;
    }
};