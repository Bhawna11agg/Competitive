class TrieNode{
    public:
    char data;
    vector<TrieNode*>children;
    bool terminal;
    TrieNode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children.push_back(NULL);
            terminal=false;
        }
    }
void insert(string word,TrieNode* root){
    if(word[0]=='\0'){
        root->terminal=true;
        return;
    }
     int c=word[0]-'a';
    if(root->children[c]==NULL){
        TrieNode* child=new TrieNode(word[0]);
        root->children[c]=child;
        insert(word.substr(1),root->children[c]);
    }
    else{
        insert(word.substr(1),root->children[c]);
    }
}
bool show(string word,TrieNode* root){
    if(word[0]=='\0'){
        if(root->terminal)
        return true;
        else
        return false;
    }
    int c=word[0]-'a';
    if(root->children[c]!=NULL){
        if(show(word.substr(1),root->children[c]))
        return true;
        else
        return false;
    }
    else{
        return false;
    }
}
};
vector<int> Solution::solve(string A, vector<string> &B) {
    vector<int>vect;
    unordered_map<int,int>map;
    int max1=0;
    TrieNode* root=new TrieNode('\0');
    string ask;
     for(int i=0;i<A.length()+1;i++){
         if(A[i]!='_' && A[i]!='\0'){
         ask=ask+A[i];
         }
         else{
             root->insert(ask,root);
                ask="";
         }
     }
     ask="";
     for(int i=0;i<B.size();i++){
         int count=0;
         for(int j=0;j<B[i].length()+1;j++){
                if(B[i][j]!='_' && B[i][j]!='\0')
                    ask=ask+B[i][j];
                 else{
                   if(root->show(ask,root)){
                       count++;
                       
                   }
                      ask="";
                 }
         }
         map[i]=count;
         if(count>max1){
             max1=count;
         }
     }
    while(max1>=0){
     for(int i=0;i<B.size();i++){
         if(max1==map[i]){
             vect.push_back(i);
         }
     }
     max1--;
     }
     return vect;
  
    //InterviewBit-Trees 
}
