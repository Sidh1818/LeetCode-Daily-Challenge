class Solution {
public:
    int findNthDigit(int n) {
        long long len=1,start=1,cnt=9;
        while(n>len*cnt){
            n-=len*cnt;
            len++;
            start*=10;
            cnt*=10;
        }
        long long number = start+(n-1)/len;
        string s = to_string(number);

        return s[(n-1)%len]-'0';
    }
};