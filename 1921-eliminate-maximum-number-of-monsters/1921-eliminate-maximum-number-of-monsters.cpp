class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        vector<float> time;
        int n=dist.size();
        for(int i=0;i<n;i++){
            time.push_back((float)dist[i]/(float)speed[i]);
        }
        
        sort(time.begin(),time.end());
        
        for(int i=0;i<n;i++){
            if(time[i]<=i){
                return i;
            }
        }
        
        return n;
    }
};