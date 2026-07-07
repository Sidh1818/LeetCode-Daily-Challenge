class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)
            return 0;

        string x = to_string(n);
        string ans;
        long long sum=0;

        for(char c:x){
            if(c!='0'){
                ans+=c;
                sum+=(c-'0');
            }
        }
        return stoi(ans) * sum;
    }
};