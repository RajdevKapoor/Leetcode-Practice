class Solution {
public:
    bool winnerOfGame(string colors) {
            int cnt_a = 0;
    int cnt_b = 0;
    int n=colors.size();
    int j(0);
    while(j<n){
        if(colors[j]=='A'){
            int cnt =0;
            while(colors[j]=='A' and j<n){
                cnt++;
                j++;
            }
            if(cnt>=3) cnt_a += cnt-2;
        }
        if(colors[j]=='B'){
            int cnt =0;
            while(colors[j]=='B' and j<n){
                cnt++;
                j++;
            }
            if(cnt>=3) cnt_b += cnt-2;
        }
    }

    return cnt_a > cnt_b;
    }
};