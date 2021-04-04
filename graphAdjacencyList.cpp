#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int nodes;
    list<int>* adjList;
public:
    Graph(int nodes){
        this->nodes=nodes;
        adjList=new list<int>[nodes];
    }

    void addEdge(int u, int v);
    void printGraph(int n);
    void bfs(int v);
    void dfsRecur(vector<bool> &visited, int u);
    void dfs(int n);
};


void Graph::addEdge(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::printGraph(int n){
    for(int i=0;i<n;i++){
        cout<<"Elements adjacent to "<<i<<" are: ";
        for(auto ele:adjList[i]){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
}

void Graph::bfs(int v){
    bool *visited=new bool[nodes];
    for(int i=0;i<nodes;i++)
        visited[i]=false;
    list<int> queue;
    visited[v]=true;
    queue.push_back(v);
    while(!queue.empty()){
        v=queue.front();
        cout<<v<<" ";
        queue.pop_front();
        for(auto ele:adjList[v]){
            if(!visited[ele]){
                visited[ele]=true;
                queue.push_back(ele);
            }
        }
    }
}

void Graph::dfsRecur(vector<bool> visited, int u){
    visited[u]=true;
    cout<<u<<" ";
    for(int v=0; v<adjList[u].size(); v++){
        if(visited[adjList[u][v]]==false)
            dfsRecur(visited,adjList[u][v]);
    }
}

void Graph::dfs(int n){
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(visited[i]==false)
            dfsRecur(visited,i);
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    Graph graph(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph.addEdge(u,v);
    }
    graph.dfs(n);
    return 0;
}