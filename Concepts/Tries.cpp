// root of Trie is always '\0'

//TrieNode class
class TrieNode {
	public :
	char data;
	vector<TrieNode *>children(26);
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children.push_back( NULL);
		}
		isTerminal = false;
	}
};
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

//Pattern Matching: It founds the pattern like if word is are then if we going to find ar then it must return true
bool patternMatching(vector<string> vect, string pattern) {
		for(int i=0;i<vect.size();i++){
            for(int j=0;j<vect[i].length();j++){
                insert(vect[i].substr(j),root);
            }
        }
          if( show(pattern,root))
              return true;
        else
            return false;
	}

//AutoComplete word:: Its not based on pattern matching we have to check the terminal..

 void find(TrieNode* root,string pattern){
        pattern=pattern+root->data;
        if(root->isTerminal==true){
            cout<<pattern<<endl;
        }
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                find(root->children[i],pattern);
            }
        }
    }
    void Complete(TrieNode* root,string pattern,string output){
      if(pattern[0]=='\0'){
          if(root->isTerminal==true)
        cout<<output<<endl;
           for(int i=0;i<26;i++){
              if(root->children[i]!=NULL){
                  find(root->children[i],output);
              }
          }
          return;
      }
        int c=pattern[0]-'a';
        if(root->children[c]==NULL){
            return;
        }
        else{
            Complete(root->children[c],pattern.substr(1),output);
        }
    }
    void autoComplete(vector<string> input, string pattern) {
           for(int i=0;i<input.size();i++){
               insertWord(input[i],root);
           }
       string output=pattern;
        Complete(root,pattern,output);
    }
    
//There are two types of Trie:
Compressed Trie and Suffix Trie.
In suffix Trie we can find any pattern that can exists.
