#include<bits/stdc++.h>
using namespace std;

bool Bipartite(int i, vector<int> adj[], vector<int> color[]){
    if(color[i] == -1) color[i] = 1;

    //This below loop is to check the adjacency node of this node and checking that is it colored or not
    for(auto it: adj[i]){
        if(color[it] == -1){
            color[it] = 1 - color[i];
            if(!Bipartite(it, adj, color)){
                return false;
            }
        }

        // If it is already colored then checking that is it equal to the previous node or not
        else if (color[it] == color[i])
        {
            return false;
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n){
    int color[n];
    memset(color,-1, sizeof color);
    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            if(!Bipartite(i, adj, color)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back[v];
        adj[v].push_back[u];
    }

    if(checkBipartite(adj, n)){
        cout << "It is a Bipartite graph";
    }
    else{
        cout << "It cannot be a Bipartite graph";
    }
    return 0;
}