class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //sort(points.begin(),points.end());

        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        });
        int n=points.size();

        int range=points[0][1];
        int arrows=1;
        for(int i=1;i<n;i++){
            if(points[i][0]>range){
                arrows++;
                range = points[i][1];
            }
        }
        return arrows;
    }
};