class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        
        int a,b,c,d;
        
        string s="";
        
        int i=0;
        while(num1[i]!='+'){
            s+=num1[i];
            i++;
        }
        i++;
        a=stoi(s);
        s="";
        while(num1[i]!='i'){
            s+=num1[i];
            i++;
        }
        b=stoi(s);
        s="";
        i=0;
        while(num2[i]!='+'){
            s+=num2[i];
            i++;
        }
        i++;
        c=stoi(s);
        s="";
        while(num2[i]!='i'){
            s+=num2[i];
            i++;
        }
        d=stoi(s);
        cout<<a<<" "<<b<<" "<<c<<" "<<d;
        int r = a*c-b*d;
        int imag =b*c+a*d;
        
        return to_string(r)+"+"+to_string(imag)+"i";
        
        
    }
};