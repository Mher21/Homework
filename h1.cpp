#include <iostream>
using namespace std;

int m,n;
void tex(int x,int d[]){
        for(int i=m+n-1;i>x;i--){
            d[i]=d[i-1];

           }
     }

int main(){
    
cout<<"Enter m: ";cin>>m;
cout<<"Enter n: ";cin>>n;
int x[m];
int y[n];
int z[m+n];


for(int i=0;i<m;i++){
    cout<<"x["<<i<<"]=";
    cin>>x[i];

     }
 for(int i=0;i<n;i++){
    cout<<"y["<<i<<"]=";
    cin>>y[i];

     }
for(int i=0;i<m+n;i++){
    z[i]=x[i];
    if(i>=m)
      z[i]=0;

    }
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(y[i]<=z[j]){
           tex(j,z);
           z[j]=y[i];
           break;
            };
        }
    z[m+i+1]=y[i+1];
    }
 for(int i=0;i<m+n;i++){
    cout<<"z["<<i<<"]="<<z[i]<<endl;

    }   

return 0;

    }
