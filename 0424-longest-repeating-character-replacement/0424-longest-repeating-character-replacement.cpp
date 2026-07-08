class Solution {
public:

    int find(vector<int>&freq){
        int maxlen = INT_MIN;
        for(int i=0;i<255;i++){
            if(freq[i]>maxlen)
                maxlen = freq[i];
        }
        return maxlen;
    }

    int characterReplacement(string s, int k) {
        int low=0,high=0,n=s.size(),diff=0,ans=0;
        vector<int>freq(256,0);
        for(high=0;high<n;high++){
            freq[s[high]]++;
            int len = high-low+1;
            int maxcnt = find(freq);
            diff = len - maxcnt;

            while(diff > k){
                freq[s[low]]--;
                low++;
                maxcnt = find(freq);

                len = high-low+1;
                diff = len-maxcnt;
            }

            len = high-low+1;

            ans = max(ans,len);
        }
        return ans;
    }
};