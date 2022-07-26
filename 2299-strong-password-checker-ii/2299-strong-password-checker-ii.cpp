class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n =password.size();
        int a=0,b=0,c=0,d=0;
        if(password.size()<8){
            return false;
        }
        
        for(int i=0;i<n;i++){
          
            if(i<n-1 and password[i]==password[i+1]){
                return false;
            }

            if(password[i]>=65 && password[i]<=90){
                a++;
            }

            if(password[i]>=97 && password[i]<=122){
                b++;
            }

            if(password[i]>=48 && password[i]<=57){
                c++;
            }

            if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || password[i]=='^' || password[i]=='&' || password[i]=='*' || password[i]=='(' || password[i]==')' || password[i]=='-' || password[i]=='+'){
                d++;
            }
        }
        if(a==0 || b==0 || c==0 || d==0){
            return false;
        }
    return true;
    }
};