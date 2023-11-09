class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool>isPrime( right+1 ,true);
        isPrime[0]=false, isPrime[1]=false;
        for( int i =2 ; i<=right; i++){
            if( isPrime[i] and (long long) i*i <=right){
                for( int j = i* i ; j<= right ; j +=i){
                    isPrime[j]=false;
                }
            }
        }
        vector<int> prime;
        for( int i =0; i<= right; i++){
            if( isPrime[i]){
                prime.push_back(i);
            }
        }
        int minDiff=INT_MAX;
        vector<int>ans;
        for( int i =1; i<prime.size(); i++){
            if( prime[i]-prime[i-1]< minDiff and prime[i-1] >= left and prime[i]<= right){
                minDiff = prime[i]-prime[i-1];
                ans.clear();
                ans.push_back(prime[i-1]);
                ans.push_back(prime[i]);
            }
            

        }
        if( ans.size()==0){
            return {-1,-1};
        }
        return ans;
        
    }
};