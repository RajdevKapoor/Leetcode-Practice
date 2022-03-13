class Solution {
public:
   string& toLowerCase(string& str)
{
    for(char& c:str)
    {
        if(c<='Z' && c>='A')
        c|=0b00100000;
    }
    return str;
}
};