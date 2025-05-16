#include<bits/stdc++.h>
using namespace std;

template<class T,class R>
vector<T>dijsktra(vector<vector<pair<T,T>>>&graph,R src){
    assert(src>=0 && src<=(int)graph.size());
    vector<T>dist((int)graph.size()+1,1e18);
    dist[src]=0;
    priority_queue<pair<T,T>,vector<pair<T,T>>,greater<pair<T,T>>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        T node=pq.top().second;
        T nodeDist=pq.top().first;
        pq.pop();
        if(nodeDist>dist[node])continue;
        for(auto &it :graph[node]){
            if(nodeDist+it.second<dist[it.first]){
                dist[it.first]=nodeDist+it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    return dist;
}
int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<long long ,long long >>>graph(n+1);
    for(int i=0;i<m;i++){
        long long  u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    vector<long long >dist=dijsktra(graph,1);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}