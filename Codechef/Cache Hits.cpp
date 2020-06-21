#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int n,b,m;
        cin>>n>>b>>m;
        int arr[m];
        for(int j=0;j<m;j++){
            cin>>arr[j];
            arr[j]=arr[j];
        }
        int count=0,start=0,end=0;
        for(int k=0;k<m;k++){
             if(arr[k]>=start && arr[k]<end){
                 
             }
             else{
                 count++;
                 start=b*(arr[k]/b);
                 end=start+b;
             }
        }
        cout<<count<<endl;
    }
}
