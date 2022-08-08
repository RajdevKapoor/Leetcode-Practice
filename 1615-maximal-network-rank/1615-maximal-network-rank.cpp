class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        unordered_map<int,int> mymp;  
        for(int i=0; i<roads.size(); i++)
        {
            mymp[roads[i][0]]++;
            mymp[roads[i][1]]++;
        }
        
        set<pair<int,int>> edges;    
        
        for(int i=0; i<roads.size(); i++)
        {
            edges.insert({roads[i][0], roads[i][1]});
            edges.insert({roads[i][1], roads[i][0]});
        }
        int ans=0, temp=0;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                temp= mymp[i]+mymp[j];
                if(edges.find({i,j})!= edges.end())
                    temp--;
                ans= max(ans, temp);
            }
        }
        
        return ans;
    }
};