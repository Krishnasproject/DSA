class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int oldColor = image[sr][sc];

        // Already the required color
        if(oldColor == color)
            return image;

        queue<pair<int,int>> q;

        q.push({sr, sc});
        image[sr][sc] = color;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Check 4 directions
            for(int i = 0; i < 4; i++) {
                
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Inside grid + same original color
                if(nr >= 0 && nr < image.size() &&
                   nc >= 0 && nc < image[0].size() &&
                   image[nr][nc] == oldColor) {
                    
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};