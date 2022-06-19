class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> mpTop;
        unordered_map<int, int> mpBot;
        int maxTop=0, maxTopEle=0;
        int maxBot=0, maxBotEle=0;
        for(auto itr: tops){
            mpTop[itr]++;
        }
        for(auto itr: bottoms){
            mpBot[itr]++;
        }
        for(auto itr: mpTop){
            if(maxTop<itr.second){
                maxTop=max(maxTop, itr.second);
                maxTopEle=itr.first;
            }
        }
        for(auto itr: mpBot){
            if(maxBot<itr.second){
                maxBot=max(maxBot, itr.second);
                maxBotEle=itr.first;
            }
        }
        int cnt=0;
        if(maxTop>maxBot){
            for(int i=0;i<tops.size();i++){
                if(maxTopEle==bottoms[i] and tops[i]!=maxTopEle){
                    cnt++;
                }
                else if(maxTopEle!=bottoms[i] and maxTopEle!=tops[i]){
                    return -1;
                }
            }
        }
        else{
            for(int i=0;i<tops.size();i++){
                if(maxBotEle==tops[i] and maxBotEle!=bottoms[i]){
                    cnt++;
                }
                else if(maxBotEle!=tops[i] and maxBotEle!=bottoms[i]){
                    return -1;
                }
            }
        }
        return cnt;
    }
};