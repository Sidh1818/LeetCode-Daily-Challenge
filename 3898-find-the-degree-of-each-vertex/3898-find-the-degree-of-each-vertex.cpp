class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>ans;
        for(int i=0;i<matrix.size();i++){
            int x = matrix.size();
            int cnt=0;
            for(int j=0;j<x;j++){
                if(matrix[i][j]==1)
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};