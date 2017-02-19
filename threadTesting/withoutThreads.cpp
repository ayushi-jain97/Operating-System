#include<iostream>
#include<sys/time.h>
#include<bits/stdc++.h>


using namespace std;

int a[100][100],b[100][100],ans[100][100];
int r=0;

void parse(string line,int x){
    int n=line.length();
    int i,k=0;
    string l="";
    for(i=0;i<n-1;i++){
        if(line[i]!=' ')
            l=l+line[i];
        else{
            int c=atoi(l.c_str());
            if(x==1)
                a[r][k++]=c;
            else
                b[r][k++]=c;
            l="";
        }
    }
    if(x==1)
        a[r][99]=atoi(l.c_str());
    else
        b[r][99]=atoi(l.c_str());
    r++;
}


void open_fileA(){
    r=0;
    ifstream myfile("matrixA");
    string line;
    if(myfile.is_open()){
        while(getline(myfile,line)){
            //cout << line << endl;
            parse(line,1);
        }
    }
}

void open_fileB(){
    r=0;
    ifstream myfile("matrixB");
    string line;
    if(myfile.is_open()){
        while(getline(myfile,line)){
            //cout << line << endl;
            parse(line,2);
        }
    }
}


int main(){
    clock_t tstart=clock();
    open_fileA();
    open_fileB();

    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)
            ans[i][j]=a[i][j]*b[i][j];
    }
     cout << "Matrix A" << endl;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            cout << a[i][j] << " ";
        }
           cout << endl;
    }
    cout << endl << "Matrix B" << endl;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            cout << b[i][j] << " ";
        }
           cout << endl;
    }
    cout << endl << "Matrix C" << endl;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            cout << ans[i][j] << " ";
        }
           cout << endl;
    }
    cout << (clock()-tstart)*1.0/CLOCKS_PER_SEC << endl;
    return 0;
}
