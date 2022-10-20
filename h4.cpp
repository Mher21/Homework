#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";cin>>n;
    int inp[n];
    int out[n];
    for(int i=0;i<n;i++){
       cout<<"inp["<<i<<"]=";
       cin>>inp[i];
       out[n-1-i]=inp[i];
      }
    for(int i=0;i<n;i++)
       cout<<"out["<<i<<"]="<<out[i]<<endl;
   return 0;


}
