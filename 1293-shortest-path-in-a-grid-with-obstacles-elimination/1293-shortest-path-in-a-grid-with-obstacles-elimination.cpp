class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        if(k>=m+n-2)
            return m+n-2;
        vector<vector<int>>best(m,vector<int>(n,-1));
        queue<tuple<int,int,int,int>>q;

        q.push({0,0,k,0});
        best[0][0] = grid[0][0];

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!q.empty()){
            auto[x,y,rem,steps] = q.front();
            q.pop();

            if(x == m-1 && y == n-1)
                return steps;
            
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx<0 || ny<0 || nx>=m || ny>=n)
                continue;

                int newrem = rem - grid[nx][ny];

                if(newrem < 0 )
                    continue;

                if(newrem <= best[nx][ny])
                    continue;
                
                best[nx][ny] = newrem;
                q.push({nx,ny,newrem,steps+1});

            }
        }
        return -1;
    }
};