#include <iostream>
using namespace std;
void zuyg (int n){
for (int i=1;i<n;i++){
if( i % 2 == 0){

cout << i << endl;
}
}
}
void kent (int n){
for (int i=1;i<n;i++){
if( i % 2 == 1){

cout << i << endl;
}
}
}
int main() {
int n;
cin >> n;
if(n % 2 == 0){
zuyg(n);

}
else {
kent(n);
}



}     
