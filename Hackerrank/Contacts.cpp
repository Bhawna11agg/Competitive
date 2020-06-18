#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    bool isTerminal;
    int count;
    vector<TrieNode*>children;
    TrieNode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children.push_back(NULL);
            isTerminal=false;
        }
    }
    void insert(TrieNode* root,string word){
        root->count+=1;
        if(word[0]=='\0'){
            root->isTerminal=true; 
            return;
        }
        int c=word[0]-'a';
        if(root->children[c]==NULL){
            TrieNode* root1=new TrieNode(word[0]);
            root->children[c]=root1;
        }
        insert(root->children[c],word.substr(1));
    }
    int search(TrieNode* root,string word){
        if(word[0]=='\0'){
            return root->count;
        }
       int c=word[0]-'a';
       if(root->children[c]==NULL){
           return 0;
       }
       else{
           return search(root->children[c],word.substr(1));
       }
    }
};

vector<int> contacts(vector<vector<string>> queries) {
     vector<int>vect;
    TrieNode* root=new TrieNode('\0');
    for(int i=0;i<queries.size();i++){
        if(queries[i][0]=="add"){
             root->insert(root,queries[i][1]);
        }
        else{
             vect.push_back(root->search(root,queries[i][1]));
        }
    }
     return vect;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
