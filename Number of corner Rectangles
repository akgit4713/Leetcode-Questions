class Solution {
public:
    /**
     * @param grid: the grid
     * @return: the number of corner rectangles
     */

    int countCornerRectangles(vector<vector<int>> &grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>cr(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                v.push_back(j);
            }
            for(int j=0;j<v.size();j++){
                for(int k=j+1;k<v.size();k++)
                    ans+=cr[v[j]][v[k]],cr[v[j]][v[k]]++;
            }
        }
        return ans;   
    }
};
