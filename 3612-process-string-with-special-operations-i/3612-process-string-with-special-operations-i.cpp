class Solution {
public:
    string processStr(string s) {
        string ans;
        int i=0;
        for(int i=0;i<s.length();i++){
            if(islower(s[i])){
                ans=ans+s[i];
            }
            else if(s[i]=='*'){
                if (!ans.empty()) {
                    ans.pop_back();
                }    
            }
            else if(s[i]=='#'){
                ans=ans+ans;
            }
            else if(s[i]=='%'){
                reverse(ans.begin(),ans.end());
            }
            else{
                continue;
            }
        }
        return ans;
    }
};