class Solution {
public:
    int minTimeToType(string word) {
        int time=0;
        char c='a';
        for(int i=0;i<word.size();i++){
            int dis=abs(word[i]-c);
            dis=min(dis,26-dis)+1;
            time+=dis;
            c=word[i];
        }
        return time;
    }
};