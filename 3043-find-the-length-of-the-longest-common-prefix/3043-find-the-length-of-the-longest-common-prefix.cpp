class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(int a:arr1){
            while(a>0){
                st.insert(a);
                a/=10;
            }
        }

        int ans=0;
        for(int a:arr2){
            while(a>0){
                if(st.count(a)){
                    int len = to_string(a).length();
                    ans = max(ans,len);
                    break;
                }
                a/=10;
            }
        }
        return ans;
    }
};