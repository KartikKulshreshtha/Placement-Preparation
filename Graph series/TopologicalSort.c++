#include<bits/stdc++.h>
using namespace std;

class Solution{
    void topo(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                topo(it, vis, st, adj);
            }
        }
        st.push(node);
    }

    vector<int> toposort(int V, vector<int> adj[]){
        stack<int> st;
        vector<int> vis[V, 0];
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                topo(i, vis, st, adj[]);
            }
        }

        vector<int> new;
        while(!st.empty()){
            new.push_back(st.top());
            st.pop();
        }

        return new;
    }
};