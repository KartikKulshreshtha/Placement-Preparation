// //Representation of a graph using a Adjacancy matrix.

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n, m;
//     cin>>n >>m;

//     //declare the adjacency matrix
//     int arr[n+1][n+1];

//     for(int i=0; i<m; i++){
//         int u, v;
//         cin>>u >>v;
//         arr[u][v] = 1;
//         arr[v][u] = 1;
//     }
// }


// //Representation of a graph using a Adjacancy List.

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n, m;
//     cin>>n >>m;

//     vector<int> arr[n+1];
//     for(int i=0; i<m; i++){
//         int u, v;
//         cin>>u >>v;

//         arr[u].push_back(v);
//         arr[v].push_back(u);
//     }
// }

