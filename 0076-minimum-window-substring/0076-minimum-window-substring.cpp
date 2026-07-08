class Solution {
public:
    bool findright(vector<int>&have,vector<int>&needed){
        for(int i=0;i<127;i++){
            if(needed[i]>have[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        if(m>n)
            return "";
        vector<int>needed(128,0);
        vector<int>have(128,0);

        for(char c:t)
            needed[c]++;

        int high=0,low=0,len,res=INT_MAX,strt=-1;

        for(high=0;high<s.size();high++){
            have[s[high]]++;

            while(findright(have,needed)){
                len = high-low+1;
                if(res>len){
                    res = len;
                    strt = low;
                } 
                have[s[low]]--;
                low++;
            }
        }
        if(res == INT_MAX)
            return "";
        return s.substr(strt,res);
    }
};