#include <iostream>
using namespace std;
int main(){

int a=15;
int* pa=&a;
char x='x';
cout << pa <<"  " <<  a <<endl;
*pa=x;
return 0;


    }
