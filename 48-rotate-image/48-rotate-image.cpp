class Solution {
public:
    void rotate(vector<vector<int>>& vect) {
        
        for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            if(i>=j){
                swap(vect[i][j],vect[j][i]);
            }
        }    
        
    }
        
        for(int i=0;i<vect.size();i++){
            reverse(vect[i].begin(),vect[i].end());
            
        }
        
        
        for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }    
        cout << endl;
    }
        
    }
};