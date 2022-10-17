#include <iostream>
using namespace std;
class node {
    public:
    int value;
    node* next;
};
int main(){
    int n;
    cout<<"Enter the number n: ";
    cin>>n;
    node* a[100];
    node* head;
    for (int i=0;i<=99;i++){
        a[i]=new node();
        
       }
    for (int i=0;i<=99;i++){
       a[i]->value=rand();
       a[i]->next=a[i+1]; 
       }
    a[99]->next=NULL;
    head=a[0];
for(int i=0;i<=99;i++){
    if(i==99-n){cout<< head->value<<endl;
      }
    head=head->next;
    }

for (int i=0;i<99;i++){
      delete  a[i];

       }



}
