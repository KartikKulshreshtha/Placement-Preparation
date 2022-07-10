#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> bfsGraph(int N, vector<int> adj[]){
            vector<int> bfs;
            vector<int> vis(N+1, 0);
            for(int i = 1; i <= N; i++){
                if(vis[i] == 0){
                    queue<int> q;
                    q.push(i);
                    vis[i] = 1;
                    while(!q.empty()){
                        int node = q.front();
                        q.pop();
                        bfs.push_back(node);

                        //This for each loop is for the adjacency nodes of "node variable"
                        for(auto it : adj[node]){
                            if(!vis[it]){
                                q.push(it);
                                vis[it] = 1;
                            }
                        }
                    }
                }
            }
            return bfs;
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

            // This is for the directed graph
            adj[u].push_back(v);

            // This is for the undirected graph
            // adj[u].push_back(v);
            // adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.bfsGraph(N, adj);
        for(int i = 0; i<ans.size(); i++){
            cout<< ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}