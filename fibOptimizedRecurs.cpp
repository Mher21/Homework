#include <iostream>
#include <ctime>
using namespace std;
double fib(int number, double* p){
    if (number == 0)
       return p[0]; 
    if (number == 1)
       return p[1];
    else{
        p[number - 1]=fib(number-1,p);
       } 
    return p[number-1] + p[number-2];
    
       }
 int main(){
    unsigned int start_time =  clock();
    double *p = new double[1000];
    p[0]=0;
    p[1]=1;
    int n;
    cout<<"Mutqagreq n-rd hamary"<<endl;
    cin >> n ;   
    cout << fib(n-1,p)<<endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout<<"time="<<search_time<<endl;
    return 0;
    }
