#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}


void revDfs(int node, vector<int> &vis, vector<int> transform[]){
    cout<< node;
    vis[node] = 1;
    for(auto it: transform[node]){
        if(!vis[it]){
            revDfs(it, vis, transform);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // This is for the Topological sort
    stack<int> st;
    vector<int> vis(n, 0);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, vis, adj, st);
        }
    }

    // This is for the change the direction of the graph
    vector<int> transform[n];
    for(int i = 0; i < n; i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            transform[it].push_back(i);
        }
    }


    // This is for the printing the elements of the transform array
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            cout<< "SCC : ";
            revDfs(node, vis, transform);
            cout << endl;
        }
    }
}