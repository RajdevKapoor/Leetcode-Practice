class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        unsigned long long int  sum = 0;
        
        for(int c:chalk){
            sum+=c;
        }
        
        k=k%sum;
        cout<<k;
        for(int i=0;i<chalk.size();i++){
            
            if(chalk[i]<=k){
                k-=chalk[i];
            }else{
                return i;
            }
            
        }
        
        return 0;
    }
};