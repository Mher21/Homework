#include <iostream>
using namespace std;

int main() {
    
    int a = 10, b = 20;
    cout << "a=10  b=20"<<endl;	
    cout << "a & b = " << (a & b) << endl;
    cout << "a | b = " << (a | b) << endl;
    cout << "a ^ b = " << (a ^ b) << endl;
    cout << "~(" << a << ") = " << (~a) << endl;
    cout << "a >> " << 2 << " = " << (a >> 2) << endl;
    cout << "b << " << 2 << " = " << (b << 2) << endl;
    cout << sizeof(a) << endl;
    cout << "a=" << a <<"  b=" << b << endl;
return 0;

}
