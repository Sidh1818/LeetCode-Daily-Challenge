class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastIdx(26,0);
        for(int i=0;i<s.length();i++)
            lastIdx[s[i]-'a'] = i;

        vector<int>ans;
        int strt=0,end=0;

        for(int i=0;i<s.length();i++){
            end = max(end,lastIdx[s[i]-'a']);

            if(i == end){
                ans.push_back(end - strt + 1);
                strt = i+1;
            }
        }
        return ans;
    }
};