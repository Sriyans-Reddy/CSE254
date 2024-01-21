#include <bits/stdc++.h>
// #include<iostream>
using namespace std;

void merge(int a[],int b[],int m,int n,int c[]){
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(a[i]<=b[j]){
            c[k]=a[i];
            i++;
        }else{
            c[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<m){
        c[k]=a[i];
        i++;k++;
    }
    while(j<n){
        c[k]=b[j];
        j++;k++;
    }
    return;
}

int a[10000000],b[10000000],c[10000000];
int main(){
    ifstream inputFile("inputa.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("outputa.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }
    int m,n;
    inputFile>>m>>n;
    for(int i=0;i<m;i++){inputFile>>a[i];}
    for(int i=0;i<n;i++){inputFile>>b[i];}
    clock_t start,end;
    start=clock();
    merge(a,b,m,n,c);
    end=clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);

    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec for "<<n<<" elements"<<endl;
    for(int i=0;i<n+m;i++){outputFile<<c[i]<<" ";}
    outputFile<<endl;
    return 0;
}