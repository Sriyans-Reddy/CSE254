#include <bits/stdc++.h>
// #include<iostream>
// #include<map>
using namespace std;

int merge(int a[],int b[],int m,int n,int c[]){
    int k=0;
    map<int,int> mp;
    for(int i=0;i<m;i++){
        mp[a[i]]=1;
    }
    for(int i=0;i<n;i++){
        if(mp[b[i]]==1){
            c[k]=b[i];
            k++;
            mp[b[i]]=0;
        }
    }
    return k;
}
int a[10000000],b[10000000],c[10000000];
int main(){
    ifstream inputFile("inputc.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("outputc.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }
    int m,n;
    inputFile>>m>>n;
    for(int i=0;i<m;i++){inputFile>>a[i];}
    for(int i=0;i<n;i++){inputFile>>b[i];}
    clock_t start,end;
    start=clock();
    int k=merge(a,b,m,n,c);
    end=clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);

    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec for "<<n<<" elements"<<endl;
    for(int i=0;i<k;i++){outputFile<<c[i]<<" ";}
    outputFile<<endl;
    return 0;
}