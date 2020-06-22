Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1




Code:
#include <bits/stdc++.h>
using namespace std;
#include<vector>
int ways(string &vec,int* arr,int index){
    if(arr[vec.length()-index]!=-1){
        return arr[vec.length()-index];
    }
    if(index==vec.length()){
        return 1;
    }
    if(index>=vec.length()-1 && vec[vec.length()-1]!='0'){
        return 1;
    }
    if(vec[index]=='0'){
        return 0;
    }
    long long int ans=ways(vec,arr,index+1);
    if(index+1<=vec.length()-1 && ((vec[index]-48)*10+(vec[index+1]-48))<=26){
       ans= (ans+ways(vec,arr,index+2))%(1000000007);
    }
    arr[vec.length()-index]=ans;
    return ans;
}
int main()
{
   string n;
   cin>>n;
     while(n[0]!='0'){
       int arr[5000];
       for(int i=0;i<5000;i++){
           arr[i]=-1;
       }
      cout<< ways(n,arr,0)<<endl;
       string j;
       cin>>j;
       n=j;
   }
}
//strings are passed by value by default
