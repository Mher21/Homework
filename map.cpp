#include <iostream>
using namespace std;
static int u=1;
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
    int maxHeight(list* x ) {
        if(x==NULL)
        return 0;
        else{
            int heightLeft=maxHeight(x->left);
            int heightRight=maxHeight(x->right);
            return max(heightLeft,heightRight)+1;

        }


    }
    int ByLevels(list* x){
       /* if(x!=NULL)
        
        cout<<"----"<<x->value<<"-----"<<;*/
       
        
        if(x->left!=NULL)
        cout<<"-----"<<x->left->value<<"-----";
         if(x->right!=NULL){
        cout<<"----"<<x->right->value<<"-----";
        cout<<endl;}
       else return 0;
     
           
            

            ByLevels(x->left);
            
            ByLevels(x->right);
            cout<<endl;
            
           
            
        }


    
   
int main(){   
      
list a;
list*p=&a; 
a.insert(15);
a.insert(30);
a.insert(5);
a.left->insert(6);
a.left->insert(2);
a.right->insert(16);
a.right->insert(32);

cout<<a.value<<"  ::first element"<<endl;
cout<<a.right->value<<"  ::second element"<<endl;
cout<<a.left->value<<"  :: third element"<<endl;
cout<<a.left->left->value<<endl;
cout<<a.left->right->value<<endl;
cout<<maxHeight(p)<<endl;
cout<<ByLevels(p);
return 0;
}