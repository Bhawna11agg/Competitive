
#include<bits/stdc++.h>
#include<set>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int n;
        cin>>n;
        n=(4*n);
        unordered_set<long long int>map,map1;
        for(int j=1;j<n;j++){
            long long int a,b;
            cin>>a>>b;
            if(map.count(a)){
              
                map.erase(a);
            }
            else{
               map.insert(a);
            }
            if(map1.count(b))
                map1.erase(b);
            else
               map1.insert(b);
        }
        cout<<(*map.begin())<<" "<<*map1.begin()<<endl;
        
    }
}
