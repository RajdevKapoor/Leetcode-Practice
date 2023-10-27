class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int count = 1;
        vector<int> temp;
        for(int i=0;i<s.length();i++){
            if(s[i]==s[i+1]){
                count++;
            }else{
                
                temp.push_back(count);
                count=1;
                
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<temp.size()-1;i++){
            ans+=min(temp[i],temp[i+1]);
        }
        
        return ans;
        
    }
};