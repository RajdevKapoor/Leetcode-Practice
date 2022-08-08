class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(targetCapacity==jug1Capacity+jug2Capacity || targetCapacity==jug1Capacity || targetCapacity==jug2Capacity) return true;
        
        if(targetCapacity>jug1Capacity+jug2Capacity) return false;
        
        set<pair<int,int>>s;
        queue<pair<int,int>>q;
        
        s.insert({0,0});
        q.push({0,0});
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            if(x==targetCapacity || y==targetCapacity || x+y==targetCapacity)
               return true;

            if(x>0)
            {
                if(s.find({0,y})==s.end())
                {
                    q.push({0,y});
                    s.insert({0,y});
                }
            }
            if(y>0)
            {
                if(s.find({x,0})==s.end())
                {
                    q.push({x,0});
                    s.insert({x,0});
                }
            }
            
            if(x<jug1Capacity)
            {
                if(s.find({jug1Capacity,y})==s.end())
                {
                    q.push({jug1Capacity,y});
                    s.insert({jug1Capacity,y});
                }
                int newx=min(jug1Capacity,x+y);
                int newy=max(0,y-(jug1Capacity-x));
                if(s.find({newx,newy})==s.end())
                {
                    q.push({newx,newy});
                    s.insert({newx,newy});
                }
            }
            
            if(y<jug2Capacity)
            {
                if(s.find({x,jug2Capacity})==s.end())
                {
                    q.push({x,jug2Capacity});
                    s.insert({x,jug2Capacity});
                }
                int newy=min(jug2Capacity,x+y);
                int newx=max(0,x-(jug2Capacity-y));
                if(s.find({newx,newy})==s.end())
                {
                    q.push({newx,newy});
                    s.insert({newx,newy});
                }
            }
        }
        
        return false;
    }
};