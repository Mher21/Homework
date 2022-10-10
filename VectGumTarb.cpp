#include <iostream>
#include <vector>
using namespace std;
vector <int> VectGum( vector <int> Vec1, vector <int> Vec2,vector <int> Vec3){
    for(int i=0;i<Vec1.size();i++){
        Vec3[i]=Vec1[i]+Vec2[i];    
      }
     return Vec3;
    }

void VectTarb( vector <int> Vec1, vector <int> Vec2,vector <int> Vec3){
    for(int i=0;i<Vec1.size();i++){
        Vec3[i]=Vec1[i]-Vec2[i];      
      }
    }


vector <int> V1={4,5,3};
vector <int> V2={5,6,2};
vector <int> V3(3);

int main(){
    
V3=VectGum(V1,V2,V3);
for(int i=0;i<4;i++){
        cout<<"V1["<<i<<"]="<<V1[i]<<endl;
    }
for(int i=0;i<4;i++){
        cout<<"V2["<<i<<"]="<<V2[i]<<endl;
    }
for(int i=0;i<4;i++){
    cout<<"V3["<<i<<"]="<<V3[i]<<endl;
    }

 
}

