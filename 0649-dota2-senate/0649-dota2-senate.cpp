class Solution {
private:
    void removeNext(string &senate, vector<bool>&removed, char c, int ind){
        while(1){
            if(senate[ind]==c && removed[ind]==false){
                removed[ind] = true;
                break;
            }
            ind = (ind+1)%senate.size();
        }
    }
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        vector<bool>removed(n, false);
        int r_count = count(senate.begin(), senate.end(), 'R');
        int d_count = n-r_count;
        int ind = 0;

        
        while(r_count && d_count){
            if(removed[ind]==false){
                if(senate[ind]=='R'){
                    removeNext(senate, removed, 'D', (ind+1)%n);
                    d_count--;
                }
                else{
                    removeNext(senate, removed, 'R', (ind+1)%n);
                    r_count--;
                }
            }
            ind = (ind+1)%n;
        }
        return r_count==0 ? "Dire" : "Radiant";
    }
};