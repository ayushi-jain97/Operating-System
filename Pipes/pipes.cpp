#include<bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#define BUFFER_SIZE 80
#define pb push_back


using namespace std;

int main(){
    int fd[2], nbytes;
    pid_t childpid;
    string msg_send = "Hello, world!\n";
    char msg_recv[90];

    pipe(fd);

    if((childpid = fork()) == -1){
        cout << "Fork Failure";
        return 0;
    }

    if(childpid != 0){
        close(fd[0]);
        write(fd[1], &msg_send[0], (msg_send.length()+1));
        close(fd[1]);
        exit(0);
    }
    else{
        wait(NULL);
        string x="";
        close(fd[1]);
        nbytes = read(fd[0], msg_recv, BUFFER_SIZE);
        for(int i=0;i<strlen(msg_recv);i++){
            if(msg_recv[i]>=97&&msg_recv[i]<=122)
                x.pb(msg_recv[i]-32);
            else if(msg_recv[i]>=65&&msg_recv[i]<=90)
                x.pb(msg_recv[i]+32);
            else
                x.pb(msg_recv[i]);
        }
        cout << x << endl << "Received string: " << msg_recv << endl;
        close(fd[0]);

    }

    return(0);
}
