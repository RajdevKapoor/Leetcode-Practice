class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> & cells, int n) {

        vector<int> ans(8);

        
        n--;
        for(int i=0;i<8;i++){
            if(i==0 || i==7) ans[i]=0;
            else{
                ans[i]=cells[i-1]==cells[i+1]; 
            }
        }
        cells = ans;

        
        int k = n%14;
        for(int j=0;j<k;j++){
            for(int i=0;i<8;i++){
                if(i==0 || i==7) ans[i]=0;
                else{
                    ans[i]=cells[i-1]==cells[i+1]; 
                }
            }
            cells = ans;
        }

        return ans;
    }
};