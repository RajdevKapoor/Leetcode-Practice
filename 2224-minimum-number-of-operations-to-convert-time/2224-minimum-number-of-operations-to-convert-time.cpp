class Solution {
private:
    int time;
public:
    int solve(int t){
        if(time<t) return 0;
        
        int x = time/t;
        time=time%t;
        return x;
        
    }
    int convertTime(string current, string correct) {
        
        int h1 = (current[0]-'0')*10 + (current[1]-'0');
        int m1 = (current[3]-'0')*10 + (current[4]-'0');
        
        int h2 = (correct[0]-'0')*10 + (correct[1]-'0');
        int m2 = (correct[3]-'0')*10 + (correct[4]-'0');
        
        int timeDiff = abs(h1*60 + m1 - h2*60-m2);
        
        int ans=0;
        time = timeDiff;
        
        return solve(60)+solve(15)+solve(5)+solve(1);
        
        
    }
};