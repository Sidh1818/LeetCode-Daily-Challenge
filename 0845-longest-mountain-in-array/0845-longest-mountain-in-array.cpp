class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int peak,j,k,n=arr.size();
        int ht=0;
        for(int i=1;i<n-1;i++){
            if(arr[i-1]<arr[i] && arr[i+1]<arr[i]){
                j=i,k=i;

                while(j>0 && arr[j]>arr[j-1])
                    j--;
                while(k<n-1 && arr[k]>arr[k+1])
                    k++;

                ht = max(ht,k-j+1);
                i=k;
            }
        }
        return ht;
    }
};