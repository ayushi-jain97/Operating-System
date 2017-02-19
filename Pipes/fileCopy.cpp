#include<bits/stdc++.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<fstream>
using namespace std;

int main(int argc,char* argv[]){
    int fd[2];

    string from=argv[1];
    string to=argv[2];
    string comp="";
    pid_t pid;
    pipe(fd);
    pid=fork();
    if(!pid){
        close(fd[0]);
        ifstream s;
        s.open(&from[0]);
        string data;
        while(getline(s,data)){
            comp.append(data+"\n");
        }
        write(fd[1],&comp[0],comp.length()+1);
    }
    else{
        char text[10000];
        wait(NULL);
        close(fd[1]);
        ofstream s;
        s.open(&to[0]);
        read(fd[0],text,10000);
        s << text;
    }
    return 0;
}
