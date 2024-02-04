#include <bits/stdc++.h>
using namespace std;

double median(vector<int>&a,vector<int>&b,long long n,long long m){
    vector<int> c(n+m);
    int i=0;
    int j=0;
    int k=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
        }else{
            c[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n){
        c[k]=a[i];
        i++;k++;
    }
    while(j<m){
        c[k]=b[j];
        j++;k++;
    }
    double f;
    if((m+n)%2){
        f= c[(m+n)/2];
    }else{
        f=(c[(m+n)/2]+c[(m+n-2)/2])/2.00;
    }
    return f;
}

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }
    long long n,m;
    inputFile>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++){
        inputFile>>a[i];
    }
    for(int i=0;i<m;i++){
        inputFile>>b[i];
    }
    outputFile<<"The median is "<<median(a,b,n,m)<<endl;
}