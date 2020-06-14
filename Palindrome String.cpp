//Strings-InterviewBit
#include<stack>
int Solution::isPalindrome(string A) {
    stack<char>stack,stack1;
    for(int i=0;i<A.length();i++){
        if(A[i]>=65 && A[i]<=90){
           stack.push(A[i]+32);
        }
        if((A[i]>=49 && A[i]<=57) ||(A[i]>=97 && A[i]<=122)){
           stack.push(A[i]);
        }
        if((A[A.length()-i-1]>=49 && A[A.length()-i-1]<=57)||(A[A.length()-i-1]>=97 && A[A.length()-i-1]<=122)){
           stack1.push(A[A.length()-i-1]);
        }
        if(A[A.length()-i-1]>=65 && A[A.length()-i-1]<=90){
           stack1.push(A[A.length()-i-1]+32);
        }
    }
    while(stack.size()>0){
        if(stack.top()==stack1.top()){
            stack.pop();
            stack1.pop();
        }
        else{
            return 0;
        }
    }
    return 1;
}
