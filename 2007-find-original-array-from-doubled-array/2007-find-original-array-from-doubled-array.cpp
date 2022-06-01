class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        int n=a.size();
        vector <int> ans;
        if(n&1){
            return ans;
        }
        
        map <int,int> m;
        for(int x:a){
            m[x]++;
        }
        
        
        if(m.find(0)!=m.end()){
            if(m[0]&1){
                return {};
            }
        }
        
       
        
        for(auto x: m){
            int key = x.first;
            int value = x.second;
            
            if(key==0){
                for(int i=0;i<value/2;i++){
                        ans.push_back(key);
                    }
                m[0]=0;
                continue;
            }
            
           
                if(m.find(key*2)!=m.end()){
                    for(int i=0;i<value;i++){
                        ans.push_back(key);
                    }
                    
                    m[key]-=value;
                    m[key*2]-=value;
                }
            
            
        }
        
        for(auto x: m){
            if(x.second!=0) return {};
        }
        
        
        if(ans.size()==n/2) return ans;
        return {};
        
        
    }
};