class Solution {
public:    
    static bool comp(string &a, string &b){
                       
        string dig1,dig2;
        int idx1, idx2;
        
        for(int i=0; i<a.size(); i++){
            if(a[i] == ' '){
                idx1 = i+1;
                break;
            }
            dig1 += a[i];
        }
        for(int i=0; i<b.size(); i++){
            if(b[i] == ' '){
                idx2 = i+1;
                break;
            }
            dig2 += b[i];
        }
        
        string aa = a.substr(idx1);
        string bb = b.substr(idx2);
        
        if(aa < bb) return true;
        else if(aa > bb) return false;
        else{
            if(dig1 < dig2) return true;
            else return false;
        }
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> vi_let, vi_dig;
        
        for(string ss:logs){
            if( isdigit(ss.back()) ) vi_dig.push_back(ss);
            else vi_let.push_back(ss);
        }
        
        sort(vi_let.begin(), vi_let.end(), comp);
        
        // append all digit logs
        for(auto i:vi_dig){
            vi_let.push_back(i);
        }
        return vi_let;
    }
};