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
    map<int,pair<int,char>> m;

    for(int i=0;i<n;i++){
        int a,b;
        char c;
        cin>>c>>a>>b;
        if(m[a].first<=b){
            m[a]={b,c};
        }
    }
    cout<<"Greedy: ";
    int ans=0;
    for(auto x:m){
        cout<<x.second.second<<" ";
        ans+=x.second.first;
    }
    cout<<ans<<endl;
    return 0;
}