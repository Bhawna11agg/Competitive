#include<iostream>
using namespace std;
void reset(char** arr,int* arr1,string name,int start,int end,int check){
    if(check==1){
        for(int i=0;start+i<10;i++){
            if(name[i]=='\0'){
                return;
            }
            if(arr1[i]==1){
                arr[start+i][end]='-';
            }
        }
        return;
    }
    for(int i=0;end+i<10;i++){
         if(name[i]=='\0'){
                return;
            }
       if(arr1[i]==1){
           arr[start][end+i]='-';
       }
    }
}
void fill(char** arr,int* arr1,string name,int start,int end,int check){
    if(check==1){
        for(int i=0;i<10;i++){
            if(name[i]=='\0'){
                return;
            }
            if(arr[start+i][end]=='-'){
                arr1[i]=1;
            }
            arr[start+i][end]=name[i];
        }
        return;
    }
    for(int i=0;i<10;i++){
         if(name[i]=='\0'){
                return;
            }
        if(arr[start][end+i]=='-'){
            arr1[i]=1;
        }
         arr[start][end+i]=name[i];
    }
}
int check(char** arr,int start,int end,string name){
  
    int i;
    for(i=0;end+i<10;i++){
        if(name[i]=='\0'){
            return 2;
        }
        if(arr[start][end+i]=='-' || arr[start][end+i]==name[i]){
            
        }
        else{
            break;
        }
    }
     if(name[i]=='\0'){
            return 2;
        }
    for( i=0;start+i<10;i++){
         if(name[i]=='\0'){
            return 1;
        }
        if(arr[start+i][end]=='-' || arr[start+i][end]==name[i]){
            
        }
        else{
           return 0;
        }
    }
     if(name[i]=='\0'){
            return 1;
        }
    return 0;
}
void find(char** arr,string name){
    if(name.length()==0){
         for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<arr[i][j];
            }
            cout<<endl;
        } 
        return;
    }
    string name1="";
    for(int i=0;i<=name.length();i++){
        if(name[i]==';' || name[i]=='\0'){
            name1[i]='\0';
              if(name[i]!='\0')
            name=name.substr(i+1);
            break;
        }
        name1=name1+name[i];
    }
   if(name==name1){
       name="";
   }
       for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j]=='-' || arr[i][j]==name1[0]){
                int c=check(arr,i,j,name1);
                 if(c==1 || c==2){
                   int *arr1=new int[name1.length()];
                    for(int i=0;i<name1.length();i++){
                        arr1[i]=0;
                    }
                    fill(arr,arr1,name1,i,j,c);  
                                          
                    find(arr,name);
                    reset(arr,arr1,name1,i,j,c);
                }
            }
        }
} 
}
int main(){
    char** arr=new char*[10];
    for(int i=0;i<10;i++){
        arr[i]=new char[10];
        for(int j=0;j<10;j++){
            cin>>arr[i][j];
        }
    }
    string name;
     cin >>name;
    find(arr,name);
}
