#include <string.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <pthread.h>
#include "chess.h"
#include <thread>    

using namespace std;
void *t1(void *);
void *t2(void *);
static int listenFd;
bool mov=true;
ChessBoard qGame;
int main (int argc, char* argv[])
{   pthread_t threadA[3];
    int  portNo;
    bool loop = false;
    struct sockaddr_in svrAdd;
    struct hostent *server;
    
    if(argc < 3)
    {
        cerr<<"Please Enter : ./client <host name> <port>"<<endl;
        return 0;
    }
    
    portNo = atoi(argv[2]);
    
    if((portNo > 65535) || (portNo < 2000))
    {
        cerr<<"Please enter port number between 2000 - 65535"<<endl;
        return 0;
    }       
    
    //create client skt
    listenFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(listenFd < 0)
    {
        cerr << "Cannot open socket" << endl;
        return 0;
    }
    
    server = gethostbyname(argv[1]);
    
    if(server == NULL)
    {
        cerr << "Host does not exist" << endl;
        return 0;
    }
    
    bzero((char *) &svrAdd, sizeof(svrAdd));
    svrAdd.sin_family = AF_INET;
    
    bcopy((char *) server -> h_addr, (char *) &svrAdd.sin_addr.s_addr, server -> h_length);
    
    svrAdd.sin_port = htons(portNo);
    
    int checker = connect(listenFd,(struct sockaddr *) &svrAdd, sizeof(svrAdd));
    
    if (checker < 0)
    {
        cerr << "Cannot connect!" << endl;
        return 0;
    }
    pthread_create(&threadA[0], NULL, t1, NULL);
    pthread_create(&threadA[1], NULL, t2, NULL);
     for(int i = 0; i < 2; i++)
    {   
        pthread_join(threadA[i], NULL);
    }
}
    //send stuff to server
   void *t1 (void *dummyPt)
    {
   
     
   
     while(true)
    {   
        
        char s[300];
        char sa[300];
        int is,ie;
       
        if(mov==true){
        bzero(s, 301);
        cin.getline(s, 300);
        is=atoi(s);
        string ss (s);
        
        if(ss=="exit"){
        write(listenFd,s,strlen(s));
        exit(0);
        }
        
     

        cout<<"to"<<endl;
     
        cin.getline(sa, 300);
        ie=atoi(sa);
        string st (sa);
        
        if(st=="exit"){
        write(listenFd,sa,strlen(sa));

        exit(0);
        }
     
        qGame.Start(is,ie);
        if (qGame.bValidMove==true){
        write(listenFd, s, strlen(s));
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        write(listenFd, sa, strlen(s)); 
        } 
       

        bzero(sa,300);
        if(qGame.bValidMove==true){
        mov=false;}
         
         }
        
     }
}
// receiving from the server
void *t2 (void *dummyPt)
{    char s[300];
     bzero(s, 301);   
     char si[300];
     bzero(si, 301);
     read(listenFd, si, 300);
     string msg4 (si);
     cout<<msg4<<endl<<endl;   
     bzero(si, 301);
     read(listenFd, si, 300);
     string msg2 (si);
     cout<<msg2<<endl<<endl;
     cout<<"\u233e = white space"<<endl;
     cout<<"Blank space = black space"<<endl;
     cout<<"Move by selecting row & column to another valid location using row & column"<<endl<<endl<<endl;

     qGame.mqGameBoard.Print();
    
       
     int is,ie;
     while(true)
    {
        
       
        
        bzero(s, 301);
        

    
        read(listenFd, s, 1000);
        string ss (s);
        is=atoi(s);
        
        
        if(ss=="exit" || ss=="W's player closed the connection" || ss=="B's player closed the connection"){
        cout<<ss<<endl;
        exit(0);  
        }
        if(is==0){
        cout<<ss<<endl;
        }
        else {
        cout<<is<<endl;
        bzero(s, 301);
        }
        read(listenFd, s, 1000);
        string st (s);
        ie=atoi(s);
        if(st=="exit" || st=="W's player closed the connection" || st=="B's player closed the connection" ){
          cout<<st<<endl;  
          exit(0);
        }
        if(ie==0){
        cout<<st<<endl;
        }
        else {
        cout<<ie<<endl;

        }
    
    if (is!=0 && ie!=0){
    qGame.Start(is,ie);
    mov=true;
       

         }

     
    }   
    
        

    }


