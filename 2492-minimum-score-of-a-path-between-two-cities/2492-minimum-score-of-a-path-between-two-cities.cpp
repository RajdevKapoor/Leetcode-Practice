class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<vector<int>>>graph;
        map<pair<int,int>,int>visited;
        for(auto x:roads)
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        int ans  = INT_MAX;
        queue<int>q;
        q.push(1);
        while(q.size())
        {
            int i = q.front();
            q.pop();
            {
                for(auto x:graph[i])
              {
                if(!visited[{i,x[0]}]&&!visited[{x[0],i}])
                {
                    visited[{i,x[0]}]=1;
                    visited[{x[0],i}]=1;
                    ans = min(ans,x[1]);
                    q.push(x[0]);
                }
             }
           }
        }
        return ans;
    }
};