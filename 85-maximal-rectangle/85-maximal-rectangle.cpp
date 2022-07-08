class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights){
        int n=heights.size();
        vector <int> rb (n,0);
        vector <int> lb (n,0);
        
        stack<int> s;
        
        for(int i=n-1;i>=0;i--){
            
            while(s.size()>0 and heights[s.top()]>= heights[i]) s.pop();
            
            if(s.size()==0){
                rb[i]=n;
            }else{
                rb[i]=s.top();
            }
            
            s.push(i);
            
        }
        
        while(s.size()) s.pop();
        
        for(int i=0;i<n;i++){
            
            while(s.size() and heights[s.top()]>= heights[i]) s.pop();
            
            if(s.size()==0){
                lb[i]=-1;
            }else{
                lb[i]=s.top();
            }
            
            s.push(i);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans=max(ans, heights[i]*(rb[i]-lb[i]-1));
        }
        
        return ans;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        
        vector<vector<int>> mat(matrix.size(),vector<int> (matrix[0].size(),0));
        
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1') mat[i][j]=1;
            }
        }
        
        if(matrix.size()==0) return 0;
        if(matrix.size()==1) return largestRectangleArea(mat[0]);
        int ans=0;
        
        for(int i=1;i<mat.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(mat[i][j])mat[i][j]+=mat[i-1][j];
            }
        }
        
        for(auto v:mat){
            ans=max(ans,largestRectangleArea(v));
        }
        return ans;
    }
};