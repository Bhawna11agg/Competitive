//https://www.hackerrank.com/challenges/journey-to-the-moon/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
int search(int** arr,int i,int* visited,int n){
    visited[i]=1;
    int count=0;
    for(int j=0;j<n;j++){
          if(j==i){
              continue;
          }
          if(visited[j]==1){
              continue;
          }
          if(arr[i][j]==1){
              count+=search(arr,j,visited,n);
          }
    }
    return count+1;
}
int journeyToMoon(int n, vector<vector<int>> astronaut) {
      int** arr=new int*[n];
      for(int i=0;i<n;i++){
          arr[i]=new int[n];
          for(int j=0;j<n;j++){
              arr[i][j]=-1;
          }
      }
    for(int i=0;i<astronaut.size();i++){
        arr[astronaut[i][0]][astronaut[i][1]]=1;
        arr[astronaut[i][1]][astronaut[i][0]]=1;
    }
    int* visited=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    long long int count=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            int c=search(arr,i,visited,n);
            count=(long long)(count+(long long)((n-c)*c));   
        }
    }
    count=(long long)(count/2);
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = journeyToMoon(n, astronaut);

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
