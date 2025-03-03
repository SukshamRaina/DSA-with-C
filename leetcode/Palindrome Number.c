bool isPalindrome(int n) {
    long long rev = 0;
    int original = n;
    if (n<0) return false;
    else{
while (n != 0) {
    rev = n % 10 + rev * 10;
    n = n / 10;}
}
   if(original==rev) return true;
   else return false;
}
