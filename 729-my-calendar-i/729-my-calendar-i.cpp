class MyCalendar {
private:
    vector <pair<int,int>> v;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (v.empty()){
            v.push_back({start, end-1});
            return true;
        }
        for (auto p1:v){
            bool cond1 = (p1.first<=start && p1.second>=start);
            bool cond2 = (p1.first<=end-1 && p1.second>=end-1);
            bool cond3 = (start<=p1.first && end-1>=p1.first);
            bool cond4 = (p1.second>=start && p1.second<=end-1);
            if (cond1 || cond2 || cond3 || cond4)
                return false;
        }
        v.push_back({start, end-1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */