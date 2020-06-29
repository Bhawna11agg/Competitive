#include<iostream>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    for(int i=0;i<row;i++){
          if(arr[i][0]==0){
             arr[i][0]=1; 
          }
        else{
            arr[i][0]=0;  
        }
    }
     for(int i=1;i<col;i++){
          if(arr[0][i]==0){
             arr[0][i]=1; 
          }
         else{
              arr[0][i]=0; 
         }
    }
    int flag=0;
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j]==0){
                int k=1;
                while(k<=arr[i-1][j-1]){
                    if(arr[i-k][j]==0){
                        flag=k;
                        break;
                    }
                    k++;
                }
                k=1;
                 while(k<=arr[i-1][j-1]){
                    if(arr[i][j-k]==0){
                        if(k<flag && flag!=0)
                        flag=k;
                        if(flag==0){
                            flag=k;
                        }
                        break;
                    }
                     k++;
                }
            
                if(flag==0){
                    arr[i][j]=arr[i-1][j-1]+1;
                }
                else{
                   arr[i][j]=flag;
                    flag=0;
                }
            }
            else{
                arr[i][j]=0;
            } 
            
        }
    }
    int sum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]>sum){
                sum=arr[i][j];
            }
        }
    }
    return sum;
}
