class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        
        vector <int> rb (n,0);
        vector <int> lb (n,0);
        
        stack<int> s;
        
        rb[n-1]=n;
        s.push(n-1);
        
        int i=n-2;
        
        while(i>-1){
            
            while(s.size()>0 and heights[s.top()]>= heights[i]){
                s.pop();
            }
            
            if(s.empty()){
                rb[i]=n;
            }else{
                rb[i]=s.top();
            }
            
            
            s.push(i);
            
            i--;
        }
        
        while(s.size()>0){
            s.pop();
        }
        
        lb[0]=-1;
        s.push(0);
        
        i=1;
        
        while(i<n){
            
            while(s.size()>0 and heights[s.top()]>= heights[i]){
                s.pop();
            }
            
            if(s.empty()){
                lb[i]=-1;
            }else{
                lb[i]=s.top();
            }
            
            
            s.push(i);
            
            i++;
        }
        
        
        
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans=max(ans, heights[i]*(rb[i]-lb[i]-1));
        }
        
        return ans;
    }
};