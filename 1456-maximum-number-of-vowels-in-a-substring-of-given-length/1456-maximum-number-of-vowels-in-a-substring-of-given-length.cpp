class Solution {
public:
    int maxVowels(string s, int k) {
        
        set<char> st ={'a','e','i','o','u'};
        
        int ans =0;
        
        for(int i=0;i<k;i++){
            if(st.count(s[i])) ans++;
        }
        
        int temp = ans;
        int j = 0;
        
        for(int i=k;i<s.length();i++){
            
            if(st.count(s[j])) temp --;
            j++;
            if(st.count(s[i])) temp++;
        
            ans = max(temp,ans);
        }
        
        return ans;
    }
};