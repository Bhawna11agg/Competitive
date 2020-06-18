#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<string.h>
#include <algorithm>
using namespace std;
int flag1=0;
class TrieNode{
    public:
    char data;
    bool isTerminal;
    vector<TrieNode*>children;
    TrieNode(char data){
        this->data=data;
        for(int i=0;i<10;i++){
            children.push_back(NULL);
            isTerminal=false;
        }
    }
    string insert(TrieNode* root,string word){
        string n="";
        if(word[0]=='\0'){
            for(int i=0;i<10;i++){
                if(root->children[i]!=NULL){
                    flag1=1;
                    return "";
                }
            }
            if(root->isTerminal){
                flag1=1;
            }
            root->isTerminal=true;
            return "";
        }
        int c=word[0]-'a';
        if(root->children[c]==NULL){
            TrieNode* root1=new TrieNode(word[0]);
            root->children[c]=root1;
        }
        else{
            if(root->children[c]->isTerminal && word[1]!='\0'){
                return word[0]+n;
            }
        }
        return word[0]+insert(root->children[c],word.substr(1));
    }
};

int main() {
    int n,flag=0;
    cin>>n;
    TrieNode* root=new TrieNode('\0');
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        string x=root->insert(root,name);
        int k=x.compare(name);
        if(k!=0 || flag1==1){
            cout<<"BAD SET"<<endl;
            cout<<name;
            flag=1;
            break;
        }
    } 
    if(flag==0){
        cout<<"GOOD SET"<<endl;
    }
    return 0;
}
