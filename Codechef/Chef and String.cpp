
#include<iostream>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        long long int sum=0;
        for(int j=0;j<n-1;j++){
            sum+=abs(arr[j+1]-arr[j])-1;
        }
        cout<<sum<<endl;
    }
}
