#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addEdge(int u,int v, int weight){
        pair<int,int> p = {v,weight};
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }cout<<endl;
        }
    }

    // topological sort
    void dfs(int node, unordered_map<int,bool> &visited, stack<int> &s ){
        visited[node] = true;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first, visited, s);
            }
        }
        s.push(node);
    }

};

int main(){

    int n;
    cout<<"Enter the number of nodes"<<endl;

    cin>>n;
    int m;
    cout<<"Enter thr number of edges "<<endl;
    cin>>m;

    Graph g;

    /*
    0 1 5
    0 2 3
    1 2 2
    1 3 6
    2 3 7
    2 4 4
    2 5 2
    3 4 -1
    4 5 -2
    */

    for(int i =0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        // creating the undirected graph
        g.addEdge(u,v,w);
    }

    g.printAdj();


    // topological sort
    unordered_map<int,bool> visited;
    stack<int> s;

    for(int i = 0;i<m;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }

    }

    int src = 1;
    vector<int> dist(n);
    for(int i =0;i<n;i++){
        dist[i] = INT_MAX;
    }

    dist[src]=0;
    while(!s.empty()){
        int top = s.top();
        s.pop();

        if(dist[top] != INT_MAX){
            for(auto i: g.adj[top]){
                if(dist[top] + i.second < dist[i.first]){
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }

    cout<<" Answer is: "<<endl;
    for(int i =0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }cout<<endl;
    
    return 0;
}