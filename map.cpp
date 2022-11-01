#include <iostream>
using namespace std;
 class list {
        public:
        int value=NULL;
        list* left=NULL;
        list* right=NULL;
        
        
        void insert(int value){
            if (this->value==NULL)
            this->value=value;
            if(this->value!=NULL){
                
                if(value > this->value){
                this-> right= new list();
                this -> right->insert(value);
                }
                if(value < this->value){
                this -> left= new list();
                this -> left -> insert(value);
                
                }
            }

            

        }
    };
int main(){   
        
list a;
a.insert(15);
a.insert(30);
a.insert(5);
a.left->insert(6);
a.left->insert(2);

cout<<a.value<<"  ::first element"<<endl;
cout<<a.right->value<<"  ::second element"<<endl;
cout<<a.left->value<<"  :: third element"<<endl;
cout<<a.left->left->value<<endl;
cout<<a.left->right->value<<endl;
return 0;
}