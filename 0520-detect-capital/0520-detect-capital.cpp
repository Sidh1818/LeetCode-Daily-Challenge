class Solution {
public:
    bool detectCapitalUse(string word) {
        int totalCapital = 0,n=word.size();
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z')
                totalCapital++;
        }

        if(totalCapital == n || totalCapital == 0 || (totalCapital == 1 && word[0]>='A' && word[0]<='Z'))
            return true;
        return false;


    }
};