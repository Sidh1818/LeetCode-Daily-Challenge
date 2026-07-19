class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>lastIdx(26,0);
        for(int i=0;i<s.size();i++)
            lastIdx[s[i]-'a'] = i;

        string res = "";
        vector<int>visited(26,0);

        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(visited[c-'a']){
                continue;
            }
            while(!res.empty() && res.back()>c && lastIdx[res.back()-'a']>i){
                visited[res.back()-'a'] = 0;
                res.pop_back();
            }
            res.push_back(c);
            visited[c-'a'] = 1;
        }
        return res;
    }
};