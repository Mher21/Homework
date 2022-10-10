#include <iostream>
using namespace std;
template<typename T>
class Vector{
public:
Vector(){
    arr_=new T[1];
    capacity_=1;
    size_=0;

    }    
bool isEmpty(){
     return size_==0;
    

     }
int size(){
    return size_;
   
    
    }
int capacity(){
    return this-> capacity_;
    
    }
void addMemory(){
     capacity_*=2;
    T* tmp = arr_;
    arr_= new T[capacity_];
    for(int i=0; i<size_;++i){
    arr_[i]=tmp[i];
    delete[] tmp;
         }
    }
void pushBack(const T& value){
        if(size_==0){
          arr_[size_]=value;
          size_++; 
           }
       else  if (size_>=capacity_){ 
        addMemory();
        arr_[size_] = value;
        size_++;

           }

        }
void remove(int index){
            T* tmp = new T[size_-1];
                
            for(int i=index+1;i<size_;++i){
               tmp[i-1]=arr_[i];
                }
            for(int i=0;i<index;i++){
               tmp[i]=arr_[i]; }
            delete[] arr_;
            arr_=tmp;
            --size_;
    
            }
        

           
T& operator[](int index) {
           return arr_[index];


    }
const T& operator[](int index) const {
           return arr_[index];


    }
~Vector(){
    delete[] arr_;

    }


private:
    T* arr_;
    int size_;
    int capacity_;
      };

int main(){   
        Vector <int> V1;
        V1.pushBack(5); 
        V1.pushBack(12);
        
        V1.pushBack(19);
        V1.remove(1);
        cout<<"Results after remove"<<endl;
        cout<<V1[0]<<endl;
     /* cout<<V1.capacity();    
        V1.pushBack(19);   
        cout<<V1[0]<<endl;
        cout<<V1[1]<<endl;
        cout<<V1[2]<<endl;
        V1.remove(2);
        cout<<"Results after remove";    
        cout<<V1[0]<<endl;
        cout<<V1[1]<<endl;*/      
        }
