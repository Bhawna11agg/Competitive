
#include<algorithm>
int MakeChange(int* denominations,int numDenominations,int value,int** arr){
     if(value==0){
        return 1;
    }
    if(numDenominations<=0 || value<denominations[0]){
        return 0;
    }
    if(arr[numDenominations][value]!=-1){
        return arr[numDenominations][value];
    }
    int x=MakeChange(denominations,numDenominations,value-denominations[0],arr);
    int y=MakeChange(denominations+1,numDenominations-1,value,arr);
    arr[numDenominations][value]=x+y;
    return x+y;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int** arr=new int*[numDenominations+1];
    for(int i=0;i<numDenominations+1;i++){
        arr[i]=new int[value+1];
        for(int j=0;j<value+1;j++){
            arr[i][j]=-1;
        }
    }
    sort(denominations,denominations+numDenominations);
   return MakeChange(denominations,numDenominations,value,arr);  
}
