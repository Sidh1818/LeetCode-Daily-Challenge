class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int>freq(26,0);
        vector<int>nums(10,0);

        for(char c:s){
            if(c>='a' && c<='z'){
                freq[c-'a']++;
            }
            else
                nums[c-'0']++;
        }

        int ans = 0;
        /*
        for(char c:s){
            if(c>='a'&&c<='z'){
                int first = c-'a';
                int mirror = 25 - first;
                ans=ans+(abs(freq[first]-freq[mirror]));
            }
            else{
                int first = c-'0';
                int mirror = 9-first;
                ans=ans+(abs(nums[first]-nums[mirror]));
            }
        }
        */

        for(int i=0;i<26;i++){
            int mirror = 25-i;
            if(i<=mirror)
                ans = ans+abs(freq[i]-freq[mirror]);
        }

        for(int i=0;i<10;i++){
            int mirror = 9-i;
            if(i<=mirror)
                ans+=abs(nums[i]-nums[mirror]);
        }
        return ans;
    }
};