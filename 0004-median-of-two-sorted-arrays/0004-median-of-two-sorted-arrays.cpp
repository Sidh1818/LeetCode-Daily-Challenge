class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int total = n+m;
        int start = 0,i=0,j=0;
        double ans=0,prev,ite;
        if(total%2==0)
            ite=total/2 + 1;
        else
            ite = total/2+1;
        while(start<ite){
            prev = ans;
            if(i<n && (j==m || nums1[i]<=nums2[j])){
                ans = nums1[i++];
                start++;
            }
            else{
                ans = nums2[j++];
                start++;
            }
        }
        if(total%2==0)
            return (prev+ans)/2.00;
        else
            return ans;
    }
};