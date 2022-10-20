#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

int main() {
   stringstream ss; 
   
   char h[100];
   cout<<"Enter the number for convertation: "; 
   cin.getline(h,100); 
   string str = h;
   
   
   int num;
   
   cout<<"this is string: "<<str<<endl;
    
   
   ss << str;
   
   
   ss >> num;
   
   
   cout <<"this is int number: "<<num<< endl; 
}
