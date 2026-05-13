class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int l = idx-1;

        while(k--){
            if(l<0)
                idx++;
            else if(idx>= arr.size())
                l--;
            else if(abs(arr[l]-x) <= (arr[idx]-x))
                l--;
            else
                idx++;
        }

        return vector<int>(arr.begin()+l+1 , arr.begin()+idx);




        /*
        int idx = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        vector<int>ans;
        int l = k/2;
        if(idx-l>=0){
            int left = idx-l;
            while(left!=idx){
                ans.push_back(arr[left]);
                left++;
            }
        }
        else{
            int left = 0;
            while(left!=idx){
                ans.push_back(arr[left]);
                left++;
            }
        }
        ans.push_back(arr[idx]);
        int total = ans.size();
        int right = idx+1;
        while(right<arr.size() && total!=k){
            ans.push_back(arr[right]);
            right++;
            total++;
        }

        return ans;
        */
    }
};