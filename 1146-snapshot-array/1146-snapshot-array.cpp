class SnapshotArray {
    unordered_map<int,unordered_map<int,int>> hmap;
    int snapid=0;
public:
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        hmap[snapid][index]=val;
        
    }
    
    int snap() {
        snapid++;
        return snapid-1;
    }
    
    int get(int index, int snap_id) {
        
        for(int i=snap_id;i>=0;i--)
        {
            if(hmap[i].count(index)==1)
                return hmap[i][index];
        }
        return 0;
    }
};