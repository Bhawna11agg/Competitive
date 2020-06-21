#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        unordered_map<int,int>map;
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
            if(map.count(arr[j])==0)
            map[arr[j]]=1;
            else{
                map[arr[j]]++;
            }
        }
        sort(arr,arr+n);
        int count1=0;
        for(int j=0;j<n;j++){
            if(arr[j]>m){
                count1=n-j;
                break;
            }
        }
        int k=1,flag=0;
        while(1){
            if((m-k)<=0){
                break;
            }
            if(map.count(m-k)!=0){
                count1+=map[m-k];
            }
            else{
                flag=1;
            }
            k++;
        }
        if(count1==0 || flag==1){
            cout<<"-1"<<endl;
        }
        else
        cout<<count1<<endl;
    }
}
