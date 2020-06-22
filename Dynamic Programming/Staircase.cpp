long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
 long int* arr=new long int[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=0;i<=n;i++){
        if(i-1>=0){
            arr[i]=arr[i-1];
        }
        if(i-2>=0){
            arr[i]+=arr[i-2];
        }
         if(i-3>=0){
            arr[i]+=arr[i-3];
        }
    }
  return arr[n];
}
