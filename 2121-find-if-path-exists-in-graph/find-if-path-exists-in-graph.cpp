class Solution {
public:

    void dfs(vector<vector<int>>&adj,int src,vector<bool>&vis){
        vis[src] = true;
        for(int i =0;i<adj[src].size();i++){
            int neigh = adj[src][i];
            if(vis[neigh] == false)
                dfs(adj,neigh,vis);
        }
        return ;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n,0);
        //creating adjency list

        for(int i = 0;i<edges.size();i++){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }

        dfs(adj,source,vis);

        return vis[destination];
    }
};