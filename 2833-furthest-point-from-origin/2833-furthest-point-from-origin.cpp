class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,d=0;
        for(char c:moves){
            if(c=='R')
                r++;
            else if(c=='L')
                r--;
            else
                d++;
        }
        return abs(r)+d;
    }
};