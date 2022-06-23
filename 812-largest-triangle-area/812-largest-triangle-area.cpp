class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        
        double res = 0;
        
        for(int i=0; i<points.size(); i++)
            for(int j=i+1; j<points.size(); j++)
                for(int k=j+1; k<points.size(); k++)
                {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    
                    double a = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
                    double b = sqrt(pow(x1-x3, 2) + pow(y1-y3, 2));
                    double c = sqrt(pow(x2-x3, 2) + pow(y2-y3, 2));
                    
                    double s = (a + b + c)/2;
                    double area = sqrt(s*(s-a)*(s-b)*(s-c));
                    
                    res = max(res, area);
                }
        
        return res;  
    }
};