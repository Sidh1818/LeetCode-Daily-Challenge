class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
            return x;
        int strt=1,end=x,mid;
        while(strt<=end){
            mid = strt+(end-strt)/2;

            if((long)mid*mid > (long)x)
                end = mid-1;
            else if((long)mid * mid == x)
                return mid;
            else
                strt = mid+1;
        }

        return end;
    }
};