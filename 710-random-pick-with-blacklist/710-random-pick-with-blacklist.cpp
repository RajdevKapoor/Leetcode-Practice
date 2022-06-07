class Solution {
private:
    unordered_map <int,int> mp;
    int top;
public:
    Solution(int n, vector<int>& blacklist) {
        top = n - blacklist.size();
        unordered_set <int> s(blacklist.begin(),blacklist.end());
        n--;
        
        for(int x:blacklist){
            if(x<top){
                while(s.find(n)!=s.end()){
                    n--;
                }
                mp[x]=n;
                n--;
            }
        }
        
    }
    
    int pick() {
        
        int num = rand()%top;
        if(mp.count(num)){
            return mp[num];
        }
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */