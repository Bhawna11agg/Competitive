int Solution::isPalindrome(int A) {
    int x=0;
    int b=A;
    while(b>0){
      x=x*10+(b%10);
      b=b/10;
    }
    if(x==A){
        return 1;
    }
    else{
        return 0;
    }
}
