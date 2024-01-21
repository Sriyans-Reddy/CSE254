#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

int a[10000000];
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }
    int n;
    inputFile>>n;
    for(int i=0;i<n;i++){inputFile>>a[i];}
    clock_t start,end;
    start=clock();
    int m1=min(a[0],a[1]);
    int m2=max(a[0],a[1]);
    for(int i=0;i<n;i++){
        if(a[i]<=m1){
            m2=m1;
            m1=a[i];
        }else if(a[i]<m2){
            m2=a[i];
        }
    }
    inputFile.close();
    end=clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);

    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec for "<<n<<" elements"<<endl;
    outputFile<<"The two minmas are "<<m1<<" and "<<m2<<endl;
    outputFile.close();
    return 0;
}