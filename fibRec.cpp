2 changed by Mher

#include <iostream>
#include <ctime>
using namespace std;
double fib(int number){
    if (number == 0)
    return 0;
    if (number==1)
    return 1;
    return fib(number-1)+fib(number-2);
    }
int main(){
    unsigned int start_time =  clock();
    int num;
    cout<<"Write the number";
    cin>>num;
    cout<<fib(num-1)<<endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout<<"time="<<search_time<<endl;


    }
