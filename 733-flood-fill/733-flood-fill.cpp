class Solution {
public:
    void helper(vector<vector<int>>& image,int row,int coloumn,int oldcolor,int newcolor)
    {
    if(row<0 || row>=image.size() || coloumn<0 || coloumn>=image[0].size() || image[row][coloumn]!=oldcolor)
    return;

        image[row][coloumn]=newcolor;

        helper(image,row+1,coloumn,oldcolor,newcolor);
        helper(image,row-1,coloumn,oldcolor,newcolor);
        helper(image,row,coloumn+1,oldcolor,newcolor);
        helper(image,row,coloumn-1,oldcolor,newcolor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc]==color)
            return image;

        helper(image,sr,sc,image[sr][sc],color);

        return image;

    }
};