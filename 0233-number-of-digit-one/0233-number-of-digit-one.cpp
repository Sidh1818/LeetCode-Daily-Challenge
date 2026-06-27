class Solution {
public:
    int countDigitOne(int n) {
        long long cnt = 0;
        for(long long factor = 1;factor<=n;factor*=10){
            long long low = n%factor;
            long long curr = (n/factor)%10;
            long long high = n / (factor*10);

            if(curr == 0)
                cnt += high * factor;
            else if(curr == 1)
                cnt += high * factor + low + 1;
            else
                cnt += (high+1)*factor;
        }
        return (int)cnt;
    }
};