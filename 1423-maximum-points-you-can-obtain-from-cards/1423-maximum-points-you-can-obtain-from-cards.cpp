class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int ans=0;
        
        for(int i=0;i<k;i++){
            ans+=card[i];
        }
        
        int curr = ans;
        int n=card.size();
        
        for(int i=k-1;i>=0;i--){
            curr -= card[i];
            curr += card[n-k+i];
            ans=max(curr,ans);
        }
        return ans;
    }
};