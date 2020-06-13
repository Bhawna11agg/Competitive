// root of Trie is always '\0'

// insert word in trie
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

//search any word in Trie
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
//remove any word from trie
void remove(string word,TrieNode* root){
    if(word[0]=='\0'){
       root->terminal=false;
       return;
    }
    int c=word[0]-'a';
    if(root->children[c]!=NULL){
        remove(word.substr(1),root->children[c]);
    }
    else{
        cout<<"Not found";
        return;
    }
}

//There are two types of Trie:
Compressed Trie and Suffix Trie.
In suffix Trie we can find any pattern that can exists.
