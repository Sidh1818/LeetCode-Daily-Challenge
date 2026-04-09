class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(t[i]!='\0'){
            if(t[i]==s[j])
                j++;
            i++;
        }
        if(s[j]=='\0')
            return true;
        return false;

    }
};