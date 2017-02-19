#include<bits/stdc++.h>
#include<stdlib.h>
#include<unistd.h>

using namespace std;

void check(int pid){
	if(!pid){
		
		cout << "Child : Hello I am the child process\n";
   		cout << "Child : Child’s PID: "<<getpid() << endl;
    		cout << "Child : Parent’s PID: "<<getppid() << endl;
		//execl("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *) 0);
		system("ps --forest");
		//kill(getpid(),SIGKILL);
		
	}
	else if(pid>0){
		
		
		cout << "Parent : Hello I am the parent process\n";
   		cout << "Parent: Parent’s PID: "<< getpid() << endl;
    		cout << "Parent: Child’s PID: "<< pid << endl;
		//kill(getpid(),SIGKILL);
	}
	else{
		cout << "Process failed";
	}

}

int main(){
	cout <<"Hello World\n";
int n;
cin >> n;
	cout << "Start: "<<getpid() << endl;
	check(fork());
	check(fork());
	return 0;
}
