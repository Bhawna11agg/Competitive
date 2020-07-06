#include <bits/stdc++.h>
using namespace std;
int calculate(int** arr,int start,int end,int* arr1,int row){
      for(int i=0;i<row;i++){
          arr1[i]+=arr[i][end];
      }
    int index1=0,index2=0,sum=0,max=0;
    for(int i=0;i<row;i++){
        sum+=arr1[i];
        if(sum<=0){
            sum=0;
          continue;  
        }
        if(sum>max){
            max=sum;
        }
    }
    return max;
}
int solve(int** arr,int row,int col){
    int max=0;
    for(int i=0;i<col;i++){
        int* arr1=new int[row];
             for(int j=0;j<row;j++){
                 arr1[j]=arr[j][i];
              }
       for(int j=i+1;j<col;j++){
          int sum= calculate(arr,i,j,arr1,row);
           if(sum>max){
               max=sum;
           }
       }
    }
    return max;
}
int main()
{
    int row,col;
    cin>>row>>col;
    int** arr=new int*[row];
    for(int i=0;i<row;i++){
        arr[i]=new int[col];
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
   int p=solve(arr,row,col); 
    if(p==0){
        int max=-10000;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(max<arr[i][j]){
                    max=arr[i][j];
                }
            }
        }
        p=max;
    }
   cout<<p;
}
