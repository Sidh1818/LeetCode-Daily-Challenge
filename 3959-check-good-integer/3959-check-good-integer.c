bool checkGoodInteger(int n) {
    int sum=0,square=0;
    while(n!=0){
        int rem = n%10;
        n/=10;

        sum += rem;
        square += (rem*rem);
    }
    return square - sum >= 50;
}