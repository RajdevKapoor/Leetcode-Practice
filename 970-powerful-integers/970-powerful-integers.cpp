class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        if(x==1 and y==1) {
            if(bound>=2){
                return {2};
            }
            return {};
        }
        
        vector <int> ans;
        
        if(x==1 or y==1){
            int z = max(x,y);
            int pow=1;
            while(pow<bound){
                ans.push_back(pow+1);
                pow*=z;
            }
            
            return ans;
            
        }
        
        vector <int> powOfx, powOfy;
        
        int pow =1;
        while(pow<bound){
            powOfx.push_back(pow);
            pow*=x;
        }
        pow=1;
        while(pow<bound){
            powOfy.push_back(pow);
            pow*=y;
        }
        
        
        for(int q:powOfx){
            cout<<q<<" ";
        }
        cout<<endl;
        for(int q:powOfy){
            cout<<q<<" ";
        }
        cout<<endl;
        
        set<int> s;
        for(int a:powOfx){
            for(int b:powOfy){
                int temp=a+b;
                if(temp<=bound){
                    s.insert(temp);
                }
            }
        }
        ans.assign(s.begin(),s.end());
        return ans;
        
        
    }
};