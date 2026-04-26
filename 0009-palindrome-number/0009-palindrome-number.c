int getrev(int num){
    int rem;
    long rev=0;
    while(num!=0){
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    return rev;
}
bool isPalindrome(int x) {
    if(x<0)
        return false;
    if(x==0)
        return true;
    long revnum;
    revnum = getrev(x);
    if(revnum==x)
        return true;
    else
        return false;


}