vector<string> Solution::fizzBuzz(int A) {
    vector<string>vect;
    int i=1;
   while(i<=A){
       string name="";
      if(i%3==0 && i%5==0){
         vect.push_back("FizzBuzz");
         i++;
         continue;
      } 
      if(i%3==0){
          vect.push_back("Fizz");
          i++;
          continue;
      }
       if(i%5==0){
          vect.push_back("Buzz");
          i++;
          continue;
      }
      int k=i;
      while(k>0){
         name=(char)((k%10)+48)+name;
         k=k/10;
      }
      vect.push_back(name);
      i++;
   }
   return vect;
}
