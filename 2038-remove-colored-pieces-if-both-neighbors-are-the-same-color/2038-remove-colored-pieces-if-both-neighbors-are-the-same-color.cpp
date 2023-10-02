class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt_a = 0;
        int cnt_b = 0;
        int n=colors.size();
        
        for(int i=1;i<n-1;i++){
            if(colors[i]=='A' and colors[i-1]=='A' and colors[i+1]=='A'){
                cnt_a++;
            }
            if(colors[i]=='B' and colors[i-1]=='B' and colors[i+1]=='B'){
                cnt_b++;
            }
        }

        return cnt_a > cnt_b;
    }
};