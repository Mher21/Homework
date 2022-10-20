#include <iostream>
#include <cstring>    
#include <string>
using namespace std;
int main(){
    char input[100];
    int n,q=0,max=0;
    cout<<"Input: ";
    cin.getline(input,101);
    cout<<strlen(input)<<endl;
    n=strlen(input);
    int p[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(input[i]==input[j]){
            q+=1;
            }  
          }
       if(input[i]!=32) 
       cout<<input[i]<<" -n "<<"handipel e "<<q<<"angam"<<endl;
       p[i]=q;
       q=0;
       if(p[i]>=max) max=p[i]; 
         
       }    
cout<<"the number of the  most common symbol is : "<<max<<endl;
return 0;
    }
