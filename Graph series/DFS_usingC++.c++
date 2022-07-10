#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs){
    storeDfs.push_back(node);
    vis[node] = 1;
    for(auto it:
     adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, storeDfs);
        }
    }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> storeDfs;
        vector<int> vis(V+1, 0);
        for(int i = 0; i <= V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, storeDfs);
            }
        }
        
        return storeDfs;
    }
        
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int N, M;
        cin>>N>>M;
        vector<int> adj[N];
        for(int i = 0; i<N;i++){
            int u, v;
            cin>>u>>v;
            //for the directed graph
            adj[u].push_back(v);

            //This is for the undirected graph
            // adj[u].push_back(v);
            // adj[v].puch_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsGraph(N, adj);
        for(int i = 0; i<ans.size(); i++){
            cout<< ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}