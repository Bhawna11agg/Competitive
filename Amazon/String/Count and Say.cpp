string Solution::countAndSay(int A) {
    string p="1";
    if(A==1){ //InterviewBit  
        return "1";
    }
    string ans="";
    for(int i=2;i<=A;i++){
        int count=0;
        if(ans!="")
        p=ans;
        ans="";
        char x=p[0];
        for(int j=0;j<p.length();j++){
            count=0;
            while(p[j]==x && j<p.length()){
                count++;
                j++;
            }
            ans=ans+(char) ('A'-16+count-1)+x;
            x=p[j];
            j--;
        }
    }
    return ans;
}
