//This is the Brute force method and it is not the optimised method!!!

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int N, M;
//     cin >> N >> M;
//     vector<pair<int, int>> adj[N];

//     int a, b, wt;
//     for(int i = 0; i<M; i++){
//         cin >> a >>b >>wt;
//         adj[a].push_back(make_pair(b, wt));
//         adj[b].push_back(make_pair(a, wt));
//     }

//     int parent[N];
//     int key[N];
//     bool mst[N];

//     for(int i = 0; i < N; i++){
//         key[i] = INT_MAX;
//         parent[i] = -1;
//         mst[i] = false;
//     }

//     key[0] = 0;
//     parent[0] = -1;

//     for(int count = 0; count < N-1; count++){
        
//         //This is for finding the minimum value from the key array.
//         int mini = INT_MAX, u;
//         for(int v = 0; v < N; v++){
//             if(mst[v] == false && key[v] < mini){
//                 mini = key[v], u = v;
//             }
//         }
//         mst[u] = true;
//         //This is for updating the parent and mst array
//         for(auto it : adj[u]){
//             int v = it.first;
//             int weight = it.second;
//             if(mst[v] == false && weight < key[v]){
//                 parent[v] = u;
//                 key[v] = weight;
//             }
//         }
//     }


    // for(int i = 1; i < N; i++){
    //     cout << parent[i] << '-' << i << "\n";
    // }
    // return 0;
// }



// This is the optimised method in the comparison of the above method

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int N, M;
//     cin >> N >> M;
//     vector<pair<int, int>> adj[N];

//     int a, b, wt;
//     for(int i = 0; i<M; i++){
//         cin >> a >>b >>wt;
//         adj[a].push_back(make_pair(b, wt));
//         adj[b].push_back(make_pair(a, wt));
//     }

//     int parent[N];
//     int key[N];
//     bool mst[N];

//     for(int i = 0; i < N; i++){
//         key[i] = INT_MAX;
//         mst[i] = false;
//     }

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     key[0] = 0;
//     parent[0] = -1;
//     pq.push({0, 0});
//     for(int count = 0; count < N-1; count++){
//         int u = pq.top().second;
//         pq.pop();

//         mst[u] = true;

//         for(auto it : adj[u]){
//             int v = it.first;
//             int weight = it.second;
//             if(mst[v] == false && weight < key[v]){
//                 parent[v] = u;
//                 pq.push({key[v], v});
//                 key[v] = weight;
//             }
//         }
//     }
//     for(int i = 1; i < N; i++){
//         cout << parent[i] << '-' << i << "\n";
//     }
//     return 0;
// }