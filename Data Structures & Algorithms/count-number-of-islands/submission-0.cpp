class Solution {
public:
    vector<vector<int>> vis;
    vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int i, int j,vector<vector<int>> &vis,vector<vector<char>>& grid){
        vis[i][j] = 1;
        for(auto[l,m] : directions){
            int x = l + i;
            int y = m + j;
            if(x>=0 && x < grid.size() && y >=0 && y < grid[0].size() && grid[x][y] == '1' && vis[x][y] == 0){
                dfs(x,y,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int no_of_islands = 0;
        vis.resize(grid.size(),vector<int>(grid[0].size(),0));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    no_of_islands++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return no_of_islands;
    }
};
