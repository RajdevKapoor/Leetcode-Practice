class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a=="0") return b;
        if(b=="0") return a;
        if(a=="0" && b=="0") return "0";
        
        int carry=0,x,y;
        
        string ans="";
        int sum=0;
        int i=a.size()-1,j=b.size()-1;
        
        while(i>=0 or j>=0){
            
            x=(i<0)?0:a[i]-'0';
            y=(j<0)?0:b[j]-'0';
            
            sum = x+y+carry;
            
            if(sum==0){
                ans+='0';
                carry=0;
                
            }else if(sum==1){
                
                ans+='1';
                carry=0;
                
            }else if(sum==2){
                
                ans+='0';
                carry=1;
                
            }else if(sum==3){
                
                ans+='1';
                carry=1;
                
            }
            
            
            i--;j--;
        }
        
        if(carry){
            ans+='1';
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};