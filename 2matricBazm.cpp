#include <iostream>
using namespace std;
int m,n,t;
    
 int**  matricGum ( int** matrix1, int** matrix2, int** matrix3 ){
        
        int s=0;
          for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int r=0;r<n;r++){
                    
                        
                     t=matrix1[i][r]*matrix2[r][j];
                     s+=t;
                    }
                matrix3[i][j]=s;
                 }

            }
        return matrix3;
        }
int main(){
   

    
cout<<"enter the number of rows and columns "<<endl;
    cout<<"m=";cin>>m;
    cout<<"n=";cin>>n;
    int** matrix1 = new int*[m];
    for (int i=0;i<m;i++){
        matrix1[i]= new int[n];    
        }
    
    int** matrix2 = new int*[m];
    for (int i=0;i<m;i++){
        matrix2[i]= new int[n];
        }
    int** matrix3 = new int*[m];
    for (int i=0;i<m;i++){
        matrix3[i]= new int[n];
        }

    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<"matrix1["<<i<<"]["<<j<<"]=";
           cin>>matrix1[i][j];  
           
            }
        
        }
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<"matrix2["<<i<<"]["<<j<<"]=";
           cin>>matrix2[i][j];
           
            }
    }
 

matrix3=matricGum ( matrix1, matrix2, matrix3 );
for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<"matrix3["<<i<<"]["<<j<<"]="<<matrix3[i][j]<<endl;
        }
   }
delete[] matrix1,matrix2,matrix3;
}
