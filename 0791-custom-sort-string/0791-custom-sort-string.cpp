class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>freq(26,0);
        for(char a:s){
            freq[a-'a']++;
        }
        string res = "";
        for(char a:order){
            while(freq[a-'a'] > 0){
                res+=a;
                freq[a-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            while(freq[i]>0){
                res+=(i+'a');
                freq[i]--;
            }
        }

        return res;
    }
};