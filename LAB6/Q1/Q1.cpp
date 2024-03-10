#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int V, E;
vector<int> adj[N];
bool v[N];

void dfs(int s, stack<int> &st){
    v[s] = 1;
    for(auto x:adj[s])
        if(!v[x])
            dfs(x, st);
    st.push(s);
}

void topological_sort(){
    stack<int> st;
    for(int i=0; i<V; i++)
        if(!v[i])
            dfs(i, st);
    while(!st.empty()){
        cout << st.top()+1 << " ";
        st.pop();
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
        cin >> V >> E;
        for(int i=0; i<V; i++){
            adj[i].clear();
            v[i] = 0;
        }
        for(int i=0; i<E; i++){
            int a, b; 
            cin>>a>>b;
            a--;b--;
            adj[a].push_back(b);
        }
        topological_sort();
        cout << endl;
}