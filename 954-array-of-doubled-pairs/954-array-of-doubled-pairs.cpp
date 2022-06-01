class Solution {
public:
    
    bool canReorderDoubled(vector<int>& v) {
        int n=v.size();
        map<int, int> mpp;
        map<int, int> mpn;
        
        for(int i=0; i<n; i++) {
            if(v[i]>0) mpp[v[i]]++;
            else if (v[i]<0) mpn[-v[i]]++;
        }

        for(auto itr : mpp){
            int c = itr.second;
            if (c){
                int c2 = mpp[itr.first*2];
                if (c2>= c){
                    mpp[itr.first*2]-=c;
                    mpp[itr.first]-=c;
                } 
            }
        }
        for(auto itr : mpn){
            int c = itr.second;
            if (c){
                int c2 = mpn[itr.first*2];
                if (c2>= c){
                    mpn[itr.first*2]-=c;
                    mpn[itr.first]-=c;
                } 
            }
        }
        
        for(auto itr : mpp){
            if(itr.second!=0) {	
                return false;
            }
        }
        for(auto itr : mpn){
            if(itr.second!=0) {	
                return false;
            }
        }
        return true;
       }
};