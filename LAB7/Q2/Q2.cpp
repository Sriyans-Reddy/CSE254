#include<bits/stdc++.h>
using namespace std;

void Greedy(vector<pair<int,pair<int,char>>> &m, int n){
    sort(m.rbegin(),m.rend());
    vector<char> v(n,'#');
    int ans=0;
    for(int i=0;i<n;i++){
        int a=min(n,m[i].second.first);
        while(a>0){
            if(v[a-1]=='#'){v[a-1]=m[i].second.second;ans+=m[i].first;break;}
            a--;
        }
    }
    for(int i=0;i<n;i++){
        if(v[i]!='#'){
            cout<<v[i]<<" ";
        }
    }
    cout<<endl<<ans<<endl;;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<pair<int,pair<int,char>>> m(n);

    for(int i=0;i<n;i++){
        int a,b;
        char c;
        cin>>c>>a>>b;
        m[i].first=b;
        m[i].second.second=c;
        m[i].second.first=a;
    }
    cout<<"Greedy: ";
    Greedy(m,n);
    return 0;
}