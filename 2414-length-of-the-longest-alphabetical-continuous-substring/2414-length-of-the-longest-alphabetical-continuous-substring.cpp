class Solution
{
public:
    int longestContinuousSubstring(string s) 
	{
		int res=0, temp=1;
		for(int i=0; i<s.size()-1; i++)
		{
			if(s[i]+1==s[i+1])
			{	
				temp++;
				continue;
			}
			res=max(res, temp);
			temp=1;
		}

      	return max(res, temp); 
    }
};