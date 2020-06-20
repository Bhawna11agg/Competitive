string Solution::convert(string A, int B) {
    int x=0;
    if(B==1){
        return A;
    }
    string name="";
    if((A.length())%3==0){
        x=A.length()/3;
    }
    else{
        x=(A.length()/3)+1;
    }
    int k=0,m=0,n=0;
    char arr[B][A.length()+1];
    for(int i=0;i<B;i++){
        for(int j=0;j<A.length()+1;j++){
            arr[i][j]='-';
        }
    }
  while(1){
      if(A[k]=='\0'){
          break;
      }
      arr[m][n]=A[k];
    
      k++;
       if(n%2==0){
         m++;
       }
      else{
             m--;
       }
       if(m==B){
         n++;
         m=m-2;
        
      }
      if(m==-1){
          n++;
          m=m+2;
         
      }
     
  }
 
  for(int i=0;i<B;i++){
      for(int j=0;j<A.length()+1;j++){
         
          if(arr[i][j]!='-'){
              name=name+arr[i][j];
          }
      }
  }
  return name;
}
