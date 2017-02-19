#include<bits/stdc++.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

using namespace std;

void check(int x){
	if(!x){
		cout << "Child: " << getpid() << endl;
	}
	else{
        cout << "Parent " << getpid() << endl;
 	}
}

int main(){
	int x=fork();
	check(x);
	int y=fork();
	check(y);
	int z=fork();
	check(z);
	cout << "Hello" << endl;
	return 0;
}
