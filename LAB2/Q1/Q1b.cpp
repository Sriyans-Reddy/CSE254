#include <bits/stdc++.h>
// #include<iostream>
// #include<map>
using namespace std;

int merge(int a[],int b[],int m,int n,int c[]){
    int i=0,j=0,k=0;
    map<int,int> mp;
    while(i<m && j<n){
        if(a[i]<=b[j]){
            if(mp[a[i]]==0){
                mp[a[i]]=1;
                c[k]=a[i];
                k++;
            }
                i++;
        }else{
            if(mp[b[j]]==0){
                mp[b[j]]=1;
                c[k]=b[j];
                k++;
            }
                j++;
        }
        
    }
    while(i<m){
            if(mp[a[i]]==0){
                mp[a[i]]=1;
                c[k]=a[i];
                k++;
            }
                i++;
    }
    while(j<n){
            if(mp[b[j]]==0){
                mp[b[j]]=1;
                c[k]=b[j];
                k++;
            }
                j++;
    }
    return k;
}
int a[10000000],b[10000000],c[10000000];
int main(){
    ifstream inputFile("inputb.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("outputb.txt");
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