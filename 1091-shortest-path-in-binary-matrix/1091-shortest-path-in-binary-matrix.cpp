class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]==1)
            return -1;
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vis[0][0] = 1;
        
        int cost=0;
        int dx[8] = {0,-1,0,1,-1,1,1,-1};
        int dy[8] = {-1,0,1,0,1,-1,1,-1};

        while(!q.empty()){
            auto p = q.front();

            int x = p.second.first;
            int y = p.second.second;

            cost = p.first;
            if(x==n-1 && y==n-1)
                    return cost;
            q.pop();

            for(int i=0;i<8;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && vis[nx][ny]==0 && grid[nx][ny]==0){
                    vis[nx][ny] = 1;
                    q.push({cost+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
};