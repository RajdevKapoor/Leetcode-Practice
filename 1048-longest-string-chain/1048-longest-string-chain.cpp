class Solution {
public:
    static bool comp(string &a, string &b){
        return a.size()<b.size();
    }

    bool checkPossible(string &s1, string &s2){

        if(s1.size()!=s2.size()+1) return false;

        int i=0, j=0;
        while(i<s1.size()){
            if(j<s2.size() && s1[i]==s2[j]){
                i++;j++;
            }
            else{
                i++;
            }
        }
        return i==s1.size() && j==s2.size();
    }

    int longestStrChain(vector<string>& words) {

        int n=words.size(), maxi=1;
        vector<int> dp(n,1);
        sort(words.begin(), words.end(), comp);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){

                if(checkPossible(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};