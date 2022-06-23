class Solution {
public:
    bool judgeSquareSum(int c) {
        
        
        int high = sqrt(c);
        int low = 0;
        
        
        while (low <= high)
        {
            
            if (c - high*high == low*low) 
                return true;
            
            int mid = low + (high -low)/2;
            
          
            
            if (low*low < c - high*high)
            {
                low = (mid*mid < c - high*high)? mid + 1: low+1;
            }
            else 
            {
                high = (low*low > c - mid*mid)?mid-1: high-1;
            }
             
            
        }
        
        return false;
        
    }
};