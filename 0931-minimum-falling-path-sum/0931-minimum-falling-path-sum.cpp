class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        /*
        int m = matrix.size();
        int n = matrix[0].size();

        if(n == 1){
            int sum = 0;
            for(int i = 0; i < m; i++){
                sum += matrix[i][0];
            }
            return sum;
        }

        vector<vector<int>>dp(m,vector<int>(n,0));

        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1;i<m;i++){
            dp[i][0] = min((matrix[i][0]+dp[i-1][0]),(matrix[i][0]+dp[i-1][1]));
        }

        for(int i=1;i<m;i++){
            dp[i][n-1] = min((matrix[i][n-1]+dp[i-1][n-1]),matrix[i][n-1]+dp[i-1][n-2]);
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n-1;j++){
                dp[i][j] = min((matrix[i][j]+dp[i-1][j]),(min((matrix[i][j]+dp[i-1][j-1]),(matrix[i][j]+dp[i-1][j+1]))));
            }
        }
        int ans = dp[m-1][0];
        for(int i=1;i<n;i++){
            ans = min(ans,dp[m-1][i]);
        }
        return ans;
        */
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i - 1][j];
                int leftDiag = (j > 0) ? dp[i-1][j-1]:INT_MAX;
                int rightDiag = (j<n-1)?dp[i-1][j+1]:INT_MAX;

                dp[i][j] = matrix[i][j]+min(up,min(leftDiag,rightDiag));
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};