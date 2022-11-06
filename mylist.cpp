#include <iostream>
#include <stdlib.h>
using namespace std;
static int p=0;
class list {
    public:
    int value;
    list* next;
    list* prev;
    
    
   void push_back(list* a[],int value,list*& head){
     int i=0;
     head=a[0];
     
     while(head->next!=NULL){
       head=a[i]->next;
        i++; 
     }
     
     a[i+1]=new list();
     head->next = a[i+1];
     a[i+1] ->prev =head;
     a[i+1]->value=value;
     head=a[i+1];
     }
     void push_front(list* a[],int value,list*& head,list*& begin){
           int i=0;
           while(head->prev != NULL){
        head = head->prev;
        i++; 
     }
     a[i+1]=new list();
     begin->prev=a[i+1];
     a[i+1]->next=begin;
     a[i+1]->value=value;
     
     a[i+1]->prev=NULL;
     begin=a[i+1];
     while(head->next!=NULL)
     head=head->next;
     

        }
        void insert(list* a[],int value,list*& head,list*& begin,int pos){
           int i,j=0;
           list* temp;
             while(head->prev != NULL){
                    head = head->prev;
                    i++; 
                }
             a[i+1]=new list();
             

             head=begin;
             while(j!=pos-1){
                head=head->next;
                j++;
             }
             temp=head->next;
             head->next=a[i+1];
             a[i+1]->prev=head;
             a[i+1]->next=temp;
             a[i+1]->value=value;
             temp->prev=a[i+1];

            while(head->next!=NULL)
                head=head->next;
     

        

        }
        
        
    
};

 
    
     

int main(){
    int n;
    cout<<"enter the amount of numbers:  ";
    cin>>n;
    
   list* a[n*2];
   

   
    //list* temp;
    list* head;
    list* temp;

    for (int i=0;i<n;i++){
        a[i]=new list();
        
       }
     list* end=a[(n*2)-1];
     list* begin=a[0];
    for(int i=0;i<n;i++){
        if(i==0){
            cout<<"a["<<i<<"]=";
            cin>>a[i]->value;
            a[0]->next=a[1];
            a[0]->prev=NULL; 
            continue;
        }
        cout<<"a["<<i<<"]=";
        cin>>a[i]->value;
        a[i]->next=a[i+1];
        a[i]->prev=a[i-1];
    }
    a[n-1]->next=NULL;
    temp=a[0];
for(int i=0;i<n;i++){
    cout<< temp->value<<endl;
    temp=temp->next;
    }
    temp=a[n-1];
    cout<<"IN REVERSE ORDER!"<<endl;
    for(int i=0;i<n;i++){
    cout<< temp->value<<endl;
    temp=temp->prev;
    }
    a[2]->push_back(a,25,head);
    cout<<"AFTER PUSH_BACK,value(25)"<<endl;
    temp=head;
    for(int i=0;i<=n;i++){
    cout<< temp->value<<endl;
    temp=temp->prev;
    }
    a[3]->push_back(a,35,head);
    a[3]->push_back(a,46,head);
    temp=head;
    cout<<"AFTER TWICE PUSH_BACK,VALUES(46,35)"<<endl;

    do{
        cout<< temp->value<<endl;
        temp=temp->prev;
        
    }
    while(temp->prev != NULL);
    cout<<temp->value<<endl;
    a[4]->push_front(a,88,head,begin);
    a[5]->push_front(a,99,head,begin);
    a[5]->push_front(a,101,head,begin);
    cout<<"AFTER Thrice PUSH_FRONT,VALUES(88,99,101)"<<endl;
    temp=head;
 do{
        cout<< temp->value<<endl;
        temp=temp->prev;
        
    }
    while(temp->prev != NULL);
    cout<<temp->value<<endl;
    
   a[3]->insert(a,33,head,begin,3);
   cout<<"INSERT IN POS 3,value (33):"<<endl;
   temp=head;
 do{
        cout<< temp->value<<endl;
        temp=temp->prev;
        
    }
    while(temp->prev != NULL);
    cout<<temp->value<<endl;



while(temp->prev!=NULL)
delete (temp);



}
