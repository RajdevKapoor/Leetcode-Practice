class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int l=0, h=tokens.size()-1;                   // The infamous two pointers
        sort(tokens.begin(), tokens.end());
        
        while(l<=h){
            while(h>=0 and tokens[l] > power){     // buying tokens
                if(score>0){
                    power+=tokens[h--];
                    score--;
                }
                else{
                    return 0;
                }
            }
            while(l<tokens.size() and tokens[l] <= power){     // Selling tokens
                power-=tokens[l++];
                score++;
            }
        }
        return score;
    }
};