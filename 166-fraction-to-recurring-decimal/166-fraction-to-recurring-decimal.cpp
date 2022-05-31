class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
        {
            return "0";
        }
        
        auto sign = (numerator < 0) ^ (denominator < 0);        
        string result = sign ? "-" : "";
        
        long n = abs(numerator);
        long d = abs(denominator);
        
        result += to_string(n/d);
        
        n = n % d;
        
        if(n == 0)
        {
            return result;
        }
        
        cout << result << endl;
        result += ".";
        
        unordered_map<long, int> visited;
        while(n)
        {
            if(visited.find(n) == visited.end())
            {
                visited[n] = result.size();
                n *= 10;
                result += to_string(n/d);
                n = n % d;                
            }
            else
            {
                result.insert(visited[n], "(");
                result += ")";
                break;
            }
        }
        
        return result;
    }
};