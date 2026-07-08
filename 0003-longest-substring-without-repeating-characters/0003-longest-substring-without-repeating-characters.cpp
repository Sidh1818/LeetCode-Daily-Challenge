class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        unordered_map<char,int>freq;
        int left=0,right=0;
        int len = INT_MIN,n=s.size();

        while(right<n){
            freq[s[right]]++;

            if(freq[s[right]]>1){
                while(freq[s[right]]>1){
                    freq[s[left]]--;
                    left++;
                }
            }
            len = max(len,right-left+1);
            right++;
        }
        return len;
    }
};