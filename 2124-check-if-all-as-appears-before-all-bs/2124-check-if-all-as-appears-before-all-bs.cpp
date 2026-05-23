class Solution {
public:
    bool checkString(string s) {
        if(s.size()==1)
            return true;
        int strtA=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b')
                break;
            else
                strtA++;
        }
        if(strtA==s.size())
            return true;
        else{
            while(strtA != s.size()){
                strtA++;
                if(s[strtA] == 'a')
                    return false;
            }
        }
        return true;

    }
};