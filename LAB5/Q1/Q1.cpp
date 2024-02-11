#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
using namespace std;

int DFS(vector<vector<int>>&v,int i,int j){

    if(v[i][j]==0){return 0;}
    else{
        v[i][j]=0;
        int ans=1;
        ans+=DFS(v,i+1,j)+DFS(v,i+1,j+1)+DFS(v,i-1,j)+DFS(v,i+1,j-1)+DFS(v,i,j+1)+DFS(v,i,j-1)+DFS(v,i-1,j+1)+DFS(v,i-1,j-1);
        return ans;
    }
}

int main(){
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }
    int n;
    inputFile>>n;
    vector<vector<int>> v(n+2,vector<int>(n+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            inputFile>>v[i][j];
        }
    }
    int mn=INT32_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mn=max(DFS(v,i,j),mn);
        }
    }
    outputFile<<mn<<endl;
    return 0;
}