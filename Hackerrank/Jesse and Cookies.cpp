#include <bits/stdc++.h>
#include<queue>
using namespace std;

vector<string> split_string(string);

/*
 * Complete the cookies function below.
 */
int cookies(int k, vector<int> A) {
   priority_queue<int,vector<int>, greater<int>>queue;
   for(int i=0;i<A.size();i++){
       queue.push(A[i]);
   }
   int count=0;
   while(queue.top()<k && queue.size()>=2){
       int a=queue.top();
       queue.pop();
       int b=queue.top();
       queue.pop();
       int c=(a)+(2*b);
       queue.push(c);
       count++;
   }
   if(queue.size()<2){
       if(queue.top()<k)
       return -1;
   }
   return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
