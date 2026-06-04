class Solution {
public:

    int ValidWavis(int n){
        string s = to_string(n);
        if(s.size()<3)
            return 0;
        char prev,mid,next;
        int cnt=0;
        for(int i=1;i<s.size()-1;i++){
            prev = s[i-1];
            mid = s[i];
            next = s[i+1];

            if(mid<prev && mid<next)
                cnt++;
            else if(mid>prev && mid>next)
                cnt++;
        }
        return cnt;
    }


/*
    int validWavis(int n){
        if(n/100<=0)
            return 0;

        int x=n,cnt=0;
        int prev = x/10;
        x/=10;
        while(x>0 ){
            int mid = x/10;
            x/=10;
            int next = x%10;
            if(prev<mid && next<mid)
                cnt++;
            if(prev>mid && mid<next)
                cnt++;
            prev = mid;
        }
        return cnt;
    }
*/
    int totalWaviness(int num1, int num2) {
        long long ans = 0;
        while(num1<=num2){
            int a = ValidWavis(num1);
            num1++;
            ans+=a;
        }
        return ans;
    }
};