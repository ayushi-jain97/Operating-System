#include<bits/stdc++.h>
#include<sys/time.h>

using namespace std;

int a[10][10],b[10][10],ans[10][10];
int r=0;

typedef struct{
    int idx,idy;
}args;

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
        a[r][9]=atoi(l.c_str());
    else
        b[r][9]=atoi(l.c_str());
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


void *thread_func(void* x){
    args *ag=(args *)x;
    int i=(ag->idx);
    int j=(ag->idy);
    //cout << i << " " << j << endl;
    ans[i][j]=a[i][j]*b[i][j];
}

int main(){
    clock_t tstart=clock();
    pthread_t thread[100];
    int i,j,k=0;
    open_fileA();
    open_fileB();
    args ag;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            ag.idx=i;
            ag.idy=j;
            pthread_create(&thread[k++],NULL,thread_func,(void *)(&ag));
        }
    }
    for(i=0;i<100;i++){
        pthread_join(thread[i],NULL);
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
