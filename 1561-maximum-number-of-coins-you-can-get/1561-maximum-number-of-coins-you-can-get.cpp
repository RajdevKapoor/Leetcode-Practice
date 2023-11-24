class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(p.begin(), p.end(), greater<int>());
        int ans = 0;
        int turn = p.size();
        turn /= 3;
        for(int i=1;i<p.size();i= i+2){
            ans += p[i];
            turn--;
            if(turn ==0)break;
        }
        return ans;
    }
};