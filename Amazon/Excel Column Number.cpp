int Solution::titleToNumber(string A) {
    int count=0;
   for(int i=0;i<A.size();i++){
       count=count*26+(A[i]-64);
   }
  return count;
}
