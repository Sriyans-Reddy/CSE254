#include <bits/stdc++.h>
using namespace std;

int recc_func(int visit,int curr,vector<vector<int>> dist,map<pair<int,int>,int>&dyP){
    int n=dist.size();
    if(visit == (1 << n)-1){return dist[curr][0];}
    
    pair<int,int> p={visit,curr};
    if(dyP.find(p)!=dyP.end()){
        return dyP[p];
    }

    int minDist=INT_MAX;
    for(int i=0;i<n;++i){
        if((visit & (1<<i))==0){
            int visits_now = visit | (1<<i);
            int res=dist[curr][i]+recc_func(visits_now,i,dist,dyP);
            minDist=min(minDist,res);
        }
    }
    dyP[p]=minDist;
    return minDist;
}

int main(){
    ifstream inputFile("lab1qn3in.txt");
    ofstream outputFile("lab1qn3out.txt");
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

    vector<vector<int>> dist(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j){dist[i][i]=0;}
            else{
                int k;
                inputFile>>k;
                dist[i][j]=k;
                dist[j][i]=k;
            }
        }
    }
    //     vector<vector<int>> dist = {
    //     {0, 10, 15, 20},
    //     {10, 0, 35, 25},
    //     {15, 35, 0, 30},
    //     {20, 25, 30, 0}
    // };
    map<pair<int,int>,int> dyP;
    inputFile.close();
    outputFile<<"Minimum Distance:"<<recc_func(1,0,dist,dyP);
    outputFile.close();
return 0;
}