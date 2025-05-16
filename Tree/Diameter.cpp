#include<bits/stdc++.h>
using namespace std;
template<class T,class R>
class diameter{
    public:
    int max_node1=-1,max_node2=-1,max_dist=-1;
    vector<T>da,db;
    
    vector<T> bfs(const vector<vector<R>>&graph,int src){
        assert(src>=0 && src<=(int)graph.size());
        vector<T>dist((int)graph.size()+1,-1);
        dist[src]=0;
        queue<T>q;
        q.push(src);
        while(!q.empty()){
            T node=q.front();
            q.pop();
            for(auto &it :graph[node]){
                if(dist[it]<0){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        return dist;
    }
    diameter(const vector<vector<R>>&graph,int src){
        da=bfs(graph,src);
        max_node1=max_element(da.begin(),da.end())-da.begin();
        db=bfs(graph,max_node1);
        max_node2=max_element(db.begin(),db.end())-db.begin();
        max_dist=db[max_node2];
    }
};
int main(){
    diameter<long long ,int>diam(graph,1);    
}