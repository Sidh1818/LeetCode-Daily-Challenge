class Solution {
public:
    bool isvalid(int num){
        bool valid = false;
        int x = num;
        while(x>0){
            int d = x%10;
            if(d==2 || d==5 || d==6 || d==9)
                valid=true;
            if(d==3 || d==4 || d==7)
                return false;
            x = x/10;
        }
        return valid;
    }

    int rotatedDigits(int n) {
        int ans=0;
        for(int i=2;i<=n;i++){
            if(isvalid(i))
                ans++;
        }
        return ans;
    }
};