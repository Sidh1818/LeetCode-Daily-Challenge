class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //priority_queue<vector<int>,vector<vector<int>>,greater<>>Heap;
        priority_queue<int>Heap;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                Heap.push(matrix[i][j]);
                if(Heap.size()>k)
                    Heap.pop();
            }
        }
        return Heap.top();
        /*
        for(int i=0;i<k-1;i++)
            Heap.pop();
        return Heap.top();
        */
    }
};