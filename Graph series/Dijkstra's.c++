#include<bits/std.c++.h>
using namespace std;

int main(){
    int n, m, source;
    cin>>n >>m;
    vector<pair<int, int>> g[n+1];

    int a, b, wt;
    for(int i = 0; i < m; i++){
        cin >> a >>b >> wt;
        g[a].push_back(make_pair(b, wt));
        g[b].push_back(make_pair(a, wt));
    }

    cin>>source;

    //From here the dijkstra algorithm is being starting
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    //In pair = (dist, from where did it came)
    vector<int> distTo(n+1, INT_MAX);

    distTo[source] = 0;
    pq.push(make_pair(0, source)); //(dist, from)

    while(!pq.empty()){
        int dist = pq.top().first;
        int prev = pq.top().second; //distance of the edge from the source
        pq.pop();

        vector<pair<int, int>>::iterator it;
        for(auto it: g[prev]){
            int next = it.first;
            int nextDist = it.second;
            if(distTo[next] > prev + nextDist){
                distTo[next] =  distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next].next));
            }
        }
    }

    cout<< "The distance from the source, "<< source << ", are : \n";
    for(int i = 1; i <= n; i++) cout << distTo[i] << " ";
    cout << "\n";



    return 0;
}