class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &v, int s, int t) {
        int n = v.size();
        map<int, vector<int>> mp;
        
        // for each stop storing the buses that go through it ....
        for(int i = 0; i < n; i++) 
            for(auto &x: v[i]) mp[x].push_back(i);
        
        // we need to find minimum number of buses so we use BFS ....
        queue<int> q; 
        q.push(s);

        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int x = q.front(); q.pop();
                if(x == t) return cnt;  // if target found ...

                for(auto &bus: mp[x]) { // iterating on all buses that go through this stop
                    for(auto &Stop: v[bus]) q.push(Stop); // we go to all others stop that bus goes
                    v[bus].clear(); // clear bus data to avoid revisiting ...
                }
                mp.erase(x); // clear Stop data to avoid revisiting ...
            }
            cnt++; // denotes number of buses used ....
        } 

        return -1;  // not possible to reach target
    }
};