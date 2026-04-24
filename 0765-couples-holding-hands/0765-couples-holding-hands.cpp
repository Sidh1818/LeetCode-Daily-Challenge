class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        int cnt=0;
        for(int i=0;i<n;i+=2){
            int x = row[i];
            int y = x^1;;
            if(row[i+1]!=y){
                for(int j=i+2;j<n;j++){
                    if(row[j]==y){
                        int temp = row[j];
                        row[j] = row[i+1];
                        row[i+1] = temp;
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};