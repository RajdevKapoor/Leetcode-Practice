class Solution {
public:

    int n;
    unordered_map<string, int>mpp;

    string solve(int i, string tmp){
        if(i==0){
            if(mpp.find(tmp)==mpp.end()) return tmp;
            else return "";
        }
        string s1=solve(i-1, tmp+"1");
        string s2=solve(i-1, tmp+"0");
        
        if(s1=="") return s2;
        else return s1;

    }

    string findDifferentBinaryString(vector<string>& nums) {
        n=nums.size();
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        string tmp="";
        return solve(n, tmp);
    }
};