class Solution {
public:
    bool check(string target){
        int n=target.size();
        for(int i=0;i<n;i++){
            if(target[i]!='?')
                return false;
        }
        return true;
    }
    bool compare(string a,string b){
        bool ans=false;
        for(int i=0;i<a.size();i++){
            if(a[i]=='?')
                continue;            
            else if(a[i]!=b[i])
                return false;
            else
                ans=true;
        }
        return ans;
    }
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>answer;
        int moves=0,prevmoves=0;
        int n=stamp.size(),m=target.size();
        while(moves<10*m){
            prevmoves=moves;
            for(int i=0;i<m-n+1;i++){
                //cout << target.substr(i,n) << " " << target << endl;
                if(compare(target.substr(i,n),stamp)){
                    moves++;
                    answer.push_back(i);
                    for(int j=i;j<i+n;j++)
                        target[j]='?';
                }
            }
            if(prevmoves==moves){
                answer.clear();
                return answer;
            }
            if(check(target)){
                reverse(answer.begin(),answer.end());
                return answer;
            }
        }
        answer.clear();
        return answer;
    }
};