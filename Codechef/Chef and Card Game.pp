
#include<iostream>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int n;
        cin>>n;
        int chef=0,mont=0;
        for(int j=0;j<n;j++){
            long int a,b;
            cin>>a>>b;
            long long int total1=0,total2=0;
            while(a>0){
                total1+=(a%10);
                a=a/10;
            }
            while(b>0){
                total2+=(b%10);
                b=b/10;
            }
            if(total2>total1){
                mont++;
            }
            else if(total1>total2){
                chef++;
            }
            else{
                chef++;
                mont++;
            }
        }
        if(chef>mont){
            cout<<"0"<<" "<<chef<<endl;
        }
         if(chef<mont){
            cout<<"1"<<" "<<mont<<endl;
        }
         if(chef==mont){
            cout<<"2"<<" "<<chef<<endl;
        }
    }
}
