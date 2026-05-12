class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const vector<int>&a , vector<int>&b){
            return (a[1]-a[0] > b[1] - b[0]);
        });
        int curr_en = 0;
        int total_en = 0;

        for(auto &a:tasks){
            int actual = a[0];
            int minimum = a[1];

            if(minimum > curr_en){
                total_en += (minimum - curr_en);
                curr_en = minimum;
            }
            curr_en -= actual;
        }
        return total_en;
    }
};