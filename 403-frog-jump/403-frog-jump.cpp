class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,unordered_set<int>>mp;
        unordered_set<int>st;
        for(auto it : stones)
            mp[it]=st;
        mp[stones[0]].insert(1);
        for(int i=0;i<n;i++){
            int currStone=stones[i];
            unordered_set<int>jumps=mp[currStone];
            for(auto jump : jumps){
                int pos=currStone+jump;
                if(pos==stones[n-1])
                    return true;
                if(mp.find(pos)!=mp.end())
                {
                    if(jump-1>0){
                        mp[pos].insert(jump-1);
                    }
                    mp[pos].insert(jump);
                    mp[pos].insert(jump+1);
                }
            }
        }
        return false;
    }
};