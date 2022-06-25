class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<points.size();i++){
            
            for(int j=0;j<points.size();j++){
                int dx=points[i][0]-points[j][0];
                int dy=points[i][1]-points[j][1];
                
                mp[dx*dx+dy*dy]++;
             
            }
            
            for(auto m:mp){
                if(m.second>1){
                    count+=m.second*(m.second-1);
                }
            }
            
            mp.clear();
        }
        
        return count;
    }
};