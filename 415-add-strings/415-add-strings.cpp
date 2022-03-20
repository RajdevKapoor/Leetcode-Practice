class Solution {
public:
    string addStrings(string num1, string num2) {
        
        vector <int> ans;
        
        int n=num1.size()-1,m=num2.size()-1;
        
        int i=n,j=m;
        int carry =0;
        
        while(i>=0 or j>=0){
            
            int x,y,sum=0;
            
            x = (i<0) ? 0:num1[i]-'0';
            y = (j<0) ? 0:num2[j]-'0';
            
            sum = x+y+carry;
            ans.push_back(sum%10);
            carry = sum/10;
                    
            i--;j--;
        }
        
        if(carry){
            ans.push_back(carry);
        }
        
        reverse(ans.begin(),ans.end());
        
        string s="";
        
        for(auto x:ans){
            char c = x+'0';
            s+=c;
            
        }
        
        return s;
        
        
    }
};