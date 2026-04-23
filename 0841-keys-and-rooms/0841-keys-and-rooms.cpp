class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        queue<int>q;
        vis[0] = 1;
        q.push(0);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto a:rooms[x]){
                if(vis[a]==0){
                    vis[a]=1;
                    q.push(a);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0)
                return false;
        }
        return true;
    }
};