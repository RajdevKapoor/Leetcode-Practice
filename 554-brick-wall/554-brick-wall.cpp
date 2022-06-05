class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
         unordered_map<int,int>gap;
         int n=wall.size()  ;

        for(auto v:wall){
             int sum=0; //to count the prefix sum in each row
             for(int col=0;col<v.size()-1;++col){
                 sum+=v[col];
                 ++gap[sum]; //frequency of the gap is increased.
             } 
        }

        int res=n;
        for(auto it:gap){
            res=min(res,n-it.second); 
        }
        return res;  
    }
};