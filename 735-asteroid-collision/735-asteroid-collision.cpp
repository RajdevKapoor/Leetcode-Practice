class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {

        stack <int> s;
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]>0){
                
                s.push(arr[i]);
                
            }else{
                
            
                
                while(s.size() and s.top()>0 and abs(s.top())<abs(arr[i])) s.pop();
                
                if(s.size() and s.top()>0 and abs(s.top())==abs(arr[i])) s.pop();
                
                else if(s.size()==0 or s.top()<0) s.push(arr[i]);
                
                else{
                    continue;
                }
            }
            
            
        }
        
       vector<int> ans(s.size());
        
       for(int i=s.size()-1;i>=0;i--){
           ans[i]=s.top();s.pop();
       }
        return ans;
    }
};