class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1,ans=0,width,ht,area;
        while(left<right){
            width = right-left;
            ht = min(height[left],height[right]);
            area = width * ht;
            ans = max(area,ans);

            height[left]<height[right]?left++:right--;
        }
        return ans;
    }
};