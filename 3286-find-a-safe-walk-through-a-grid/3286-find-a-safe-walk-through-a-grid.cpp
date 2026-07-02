class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        deque<pair<int,int>>dq;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        dist[0][0] = grid[0][0];
        dq.push_front({0,0});

        while(!dq.empty()){
            auto[x,y] = dq.front();
            dq.pop_front();

            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx<0 || ny<0 || nx>=m || ny>=n)
                    continue;
                
                int newcost = dist[x][y] + grid[nx][ny];

                if(newcost < dist[nx][ny]){
                    dist[nx][ny] = newcost;
                    if(grid[nx][ny] == 0)
                        dq.push_front({nx,ny});
                    else
                        dq.push_back({nx,ny});
                }
            }
        }

        return dist[m-1][n-1] <= health-1;
    }
};