
#include<iostream>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int n,p;
        cin>>n;
        p=n;
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
               if(p==n && p>0){
                   cout<<"O";
                   p--;
                   continue;
               }
               if(p<n && p>0){
                 cout<<".";
                 p--;
               }
               else{
                 cout<<"X";  
               }
            }
            cout<<endl;
        }
    }
}
