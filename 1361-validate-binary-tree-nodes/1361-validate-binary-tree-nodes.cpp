class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        
        vector<int> ind(n,0);
        queue<int> q;
        int cnt = 0,nd = -1;
        
        for(int i = 0 ; i < n ; ++i)            //calculating indegree , if ind>1 return false
        {
            if(lc[i]!=-1)
            {
                ind[lc[i]]++;
                if(ind[lc[i]]>1)    return 0;
            }

            if(rc[i]!=-1)
            {
                ind[rc[i]]++;
                if(ind[rc[i]]>1)    return 0;
            }
        }

        for(int i = 0 ; i < n ; ++i)    //counting 0 indegree nodes
            if(ind[i]==0)
            {
                cnt++;
                nd = i;
            }

        if(cnt != 1)                    //if not 1 return false
            return 0;

        q.push(nd);                     //do bfs, no need of bool vector as this graph does not have loops (indegree check above ) or undirected edges
        cnt = 0;

        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            cnt++;

            if(lc[f]!=-1)
                q.push(lc[f]);

            if(rc[f]!=-1)
                q.push(rc[f]);
        }
        return cnt==n;
    }
};