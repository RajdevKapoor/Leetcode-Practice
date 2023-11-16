class Solution {
public:
    string reformatNumber(string number) {
        string x="";
        for(int i=0;i<number.length();i++)
        {
            if(isdigit(number[i]))
            x+=number[i];
        }
        number=x;
        int k=0,i,r=0;
        if(x.length()>4)
        {
            for( i=3;i<number.length()-1;i++)
            {
                if((i)%3==0)
                {
                    x.insert(i+k,"-");
                    r=i+k;
                    k++;
                }
            }
            if(x.length()-r>3)
            {
               string q=x.substr(r+1);
               x.erase(r+1);
                
                    if(q.length()==4)
                    {
                        q.insert(2,"-");
                    }
                x+=q;
            
            }
        }
        else if(x.length()==4)
        {
                        x.insert(2,"-");

        }
       

    return x;
        
    }
};