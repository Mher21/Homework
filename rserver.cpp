#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <pthread.h>
using namespace std;

void *task1(void *);
void *task2(void *);


static int connFd1,connFd2;



int main(int argc, char* argv[])
{
    int pId, portNo, listenFd;
    socklen_t len; //store size of the address
    bool loop = false;
    struct sockaddr_in svrAdd, clntAdd1,clntAdd2;
    
    pthread_t threadA[3];
    
    if (argc < 2)
    {
        cerr << "Please Enter : ./server <port>" << endl;
        return 0;
    }
    
    portNo = atoi(argv[1]);
    
    if((portNo > 65535) || (portNo < 2000))
    {
        cerr << "Please enter a port number between 2000 - 65535" << endl;
        return 0;
    }
    
    //create socket
    listenFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    
    if(listenFd < 0)
    {
        cerr << "Cannot open socket" << endl;
        return 0;
    }
    
    bzero((char*) &svrAdd, sizeof(svrAdd));
    
    svrAdd.sin_family = AF_INET;
    svrAdd.sin_addr.s_addr = INADDR_ANY;
    svrAdd.sin_port = htons(portNo);
    
    //bind socket
    if(bind(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0)
    {
        cerr << "Cannot bind" << endl;
        return 0;
    }
    
    listen(listenFd, 5);
    

    
       socklen_t len1 = sizeof(clntAdd1);
       cout << "Listening" << endl;

        //this is where client connects. svr will hang in this mode until client conn
        connFd1 = accept(listenFd, (struct sockaddr *)&clntAdd1, &len1);

        if (connFd1 < 0)
        {
            cerr << "Cannot accept connection" << endl;
            return 0;
        }
        else
        {
            cout << "Connection successful" << endl;
        }
        
        pthread_create(&threadA[0], NULL, task1, NULL); 
        
       
    
       socklen_t len2 = sizeof(clntAdd2);
       cout << "Listening" << endl;

        //this is where client connects. svr will hang in this mode until client conn
        connFd2 = accept(listenFd, (struct sockaddr *)&clntAdd2, &len2);
        char msg4[]="PLAYER 2 CONNECTED SUCCESSFULLY";
        char msg5[]="!!!! WELCOME TO CHESS GAME!!!  YOU ARE THE BLACK TEAM !!!!! ";
        if (connFd2 < 0)
        {
            cerr << "Cannot accept connection" << endl;
            return 0;
        }
        else
        {
            cout << "Connection successful" << endl;
            write(connFd1,msg4,strlen(msg4));
            write(connFd2,msg5,strlen(msg5));

        }

        pthread_create(&threadA[1], NULL, task2, NULL);

        


    for(int i = 0; i < 3; i++)
    {
        pthread_join(threadA[i], NULL);
    }
    
    
}
// function for thread #1
void *task1 (void *dummyPt)
{
    cout << "Thread No: " << pthread_self() << endl;
    char test[1000];
    bzero(test, 1001);
    bool loop = false;
    char msg2[200]="!!!! WELCOME TO CHESS GAME!!!  YOU ARE THE WHITE TEAM !!!!! WAIT FOR CONNECTION PLAYER 2 AND  ENTER YOUR FIRST MOVE ";
    char msgex1[100]="W's player closed the connection";
    write(connFd1,msg2,strlen(msg2));
     while(!loop)
    {   bzero(test,1001);
        read(connFd1, test, 1000);
        string tester (test);
        cout << tester << endl;
        if(tester == "exit"){
            write(connFd2,msgex1,strlen(msgex1));
            break;
          }       
        write(connFd2,test,strlen(test));
        read(connFd1, test, 1000);
        string  tester1 (test);
        cout << tester1 << endl;
        if(tester1 == "exit"){
            write(connFd2,msgex1,strlen(msgex1));
            break;
         }

        write(connFd2,test,strlen(test));
    }
    cout << "\nClosing thread and conn" << endl;
    close(connFd1);
    exit(0);
}
// function for thread #2
void *task2 (void *dummyPt)
{
    cout << "Thread No: " << pthread_self() << endl;
    char test[1000];
    bzero(test, 1001);
    bool loop = false;
    char msg2[100]="WAIT FOR MOVE PLAYER 1 AND  ENTER YOUR FIRST MOVE ";
    char msgex2[100]="B's player closed the connection";
    write(connFd2,msg2,strlen(msg2));
  
    while(!loop)
    {
        bzero(test,1001);
        read(connFd2, test, 1000);
        string tester (test);
        cout << tester << endl;
        if(tester == "exit"){
            write(connFd1,msgex2,strlen(msgex2));
            break;}
        write(connFd1,test,strlen(test));
        read(connFd2, test, 1000);
        string tester1 (test);
        cout << tester1 << endl;
        if(tester1 == "exit"){
            write(connFd1,msgex2,strlen(msgex2));
            break;}
        write(connFd1,test,strlen(test));    
     }
        
    
    cout << "\nClosing thread and conn" << endl;
    close(connFd2);
    exit(0);
}

