int Solution::atoi(const string A) {
    int p=0;
    int m,i;
   for(m=0;m<A.length();m++){
       if(A[m]=='+'){
           continue;
       }
       if((A[m]>=48 && A[m]<=57)|| A[m]=='-'){
           break;
       }
       else{
           return 0;
       }
   }
    for( i=m;i<A.length();i++){
        if(i==m && A[m]==45){
            continue;
        }
        if((A[i]>=48 && A[i]<=57)){
           int k=(int)(A[i])-48;
            p=p*10+k;
        }
        else{
            break;
        }
    }
    if((i-m)>9 && A[m]!=45){
        return INT_MAX;
    }
    if((i-m)>10 && A[m]==45){
        return INT_MIN;
    }
    if(A[m]==45){
        int k=0-p;
        return (k);
    }
   return p; 
}
//InterviewBit
