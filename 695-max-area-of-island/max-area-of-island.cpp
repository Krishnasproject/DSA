class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j) {

    queue<pair<int,int>> q;
    q.push({i,j});

    grid[i][j] = 0;

    int count = 0;

    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    while(!q.empty()) {

        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        count++;

        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1){
                grid[nr][nc] = 0;
                q.push({nr, nc});
            }
        }
    }

    return count;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
       int maxArea = 0;

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int count = bfs(grid,i,j);
                    maxArea = max(maxArea,count);
                }
            }
        }
        return maxArea;
    }
};