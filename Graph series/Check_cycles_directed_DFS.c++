#inclue <bits/stdc++.h>
using namespace std;

class Solutin{
    public:
    bool checkcycle(int node, vector<int> adj[], int vis[], int dfsvis[]){
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(checkcycle(it, adj, vis, dfsvis)) return true;
            }
            else if(dfsvis[it]) return true;
        }
        
        dfsvis[node] = 0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V], dfsvis[V];
        memset(vis, 0, sizeof vis);
        memset(dfsvis, 0, sizeof dfsvis);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(checkcycle(i, adj, vis, dfsvis)) return true;
            }
        }
        return false;
    }
};


int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin>>V>>E;
        vector<int> adj[V];
        for(int i = 0; i<E; i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if(ans){
            cout<< "1\n";
        }
        else{
            cout<<"0\n";
        }
    }
    return 0;
}