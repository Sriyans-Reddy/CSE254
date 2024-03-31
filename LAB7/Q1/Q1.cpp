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
        wt+=wts[j];
        ans+=val[j];
    }
    cout<<ans<<endl;

}
int knapSack(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    vector<vector<int> > K(n + 1, vector<int>(W + 1)); 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max(val[i - 1] 
                                  + K[i - 1][w - wt[i - 1]], 
                              K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
    return K[n][W]; 
}
void dp(vector<double> &val,vector<double> &wts,int lim,int n){
    
    vector<vector<double>> vec(n+1, vector<double>(lim+1));
    for(int i=0;i<=n;i++){
        for(int w=0;w<=lim;w++){
            if(i==0 || w==0){vec[i][w]=0;}
            else if(wts[i-1]<=w){vec[i][w]=max(vec[i-1][w],vec[i-1][w-wts[i-1]]+val[i-1]);}
            else{vec[i][w]=vec[i-1][w];}
        }
    }
    cout<<vec[n][lim]<<endl;;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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
    cout<<"Dynamic Approach: ";
    dp(val,wts,lim,n);
    return 0;
}