class Solution {
public:
    int numSquares(int n) {
       int* arr=new int[n+1];
        arr[0]=0;
        arr[1]=1;
        if(n>=2){
            arr[2]=2;
        }
        int max=INT_MAX,sum=0;
        for(int i=3;i<=n;i++){
           for(int j=1;j<=sqrt(i);j++){
               int p=i-pow(j,2);
               sum=1+arr[p];
               if(sum<max){
                  max=sum;
               }
           } 
            arr[i]=max;
            max=INT_MAX;
        }
        return arr[n];
    }
};
