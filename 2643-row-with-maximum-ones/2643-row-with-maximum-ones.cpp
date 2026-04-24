class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int maxOne=-1;
        int rowIdx=0;
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1)
                    cnt++;
            }
            if(cnt>maxOne){
                maxOne = cnt;
                rowIdx = i;
            }
        }
        return {rowIdx,maxOne};
    }
};