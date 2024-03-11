#include<bits/stdc++.h>
// #include<iostream>
// #include<map>
// #include<vector>
using namespace std;

void greedy(vector<double> &val,vector<double> &wts,int lim,int n){
    vector<pair<double,double>> vec(n);
    for(int i=0;i<n;i++){
        vec[i]={val[i]/wts[i],i};
    }
    sort(vec.begin(),vec.end());
    // for(int i=0;i<n;i++){cout<<vec[i].first<<" "<<vec[i].second<<" ";}
    // cout<<endl;
    int ans=0;
    int wt=0;
    for(int i=n-1;i>=0;i--){
        int j=vec[i].second;
        if(wt+wts[j]>lim){continue;}
        cout<<j+1<<" ";
        wt+=wts[j];
        ans+=val[j];
    }
    cout<<ans<<endl;

}

int main(){
    int n;
    cin>>n;
    vector<double> val(n);
    vector<double> wts(n);
    int lim;
    for(int i=0;i<n;i++){cin>>wts[i];}
    for(int i=0;i<n;i++){cin>>val[i];}
    cin>>lim;
    cout<<"Greedy: ";
    greedy(val,wts,lim,n);
    return 0;
}