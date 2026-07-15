class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evens=n*(n-1),odds=n*n;
        return gcd(evens,odds);
    }
};