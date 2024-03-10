#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int V, E;
vector<int> adj[N];
bool vis[N];

void dfs(int s, stack<int> &st){
    vis[s] = 1;
    for(auto x:adj[s])
        if(!vis[x])
            dfs(x, st);
    st.push(s);
}

vector<int> topological_sort(){
    stack<int> st;
    vector<int> vec;
    for(int i=0; i<V; i++)
        if(!vis[i])
            dfs(i, st);
    while(!st.empty()){
        vec.push_back(st.top());
        st.pop();
    }
    return vec;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
        cin >> V >> E;
        for(int i=0; i<V; i++){
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i=0; i<E; i++){
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
        }
        vector<int> vect = topological_sort();
        reverse(vect.begin(), vect.end());
        vector<int> dist(V);
        for(auto s:vect)
            for(auto x:adj[s])
                dist[s] = max(dist[s], dist[x]+1);
        cout << *max_element(dist.begin(), dist.end()) << endl;
}