// C++ program for implementation of Ford Fulkerson algorithm
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

// Number of vertices in given graph
#define V 110
// Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)
int graph[V][V];
int parent[V];  // This array is filled by BFS and to store path
int N;

/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(int s, int t){
    // Create a visited array and mark all vertices as not visited
    bool visited[N];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++){
            if (visited[v]==false && rGraph[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}

// Returns tne maximum flow from s to t in the given graph
int fordFulkerson(int s, int t){
    int u, v;


    for (u = 0; u < N; u++){
        for (v = 0; v < N; v++){
             rGraph[u][v] = graph[u][v];
        }
    }



    int max_flow = 0;  // There is no flow initially

    // Augment the flow while tere is path from source to sink
    while (bfs(s, t)){
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v]){
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        cout<<max_flow<<endl;
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}

// Driver program to test above functions
int main(){
    int R;
    cin>>N>>R;
    // Let us create a graph shown in the above example
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            graph[i][j] = 0;
        }
    }
    int a, b, w;
    for(int i = 0; i<R; i++){
        cin>>a>>b>>w;
        cout<<a<<b<<w<<endl;
        a--; b--;
        graph[a][b] = w;
    }

    int s,t,k;
    cin>>s>>t>>k;
    cout<<"before path"<<endl;
    cout << "The maximum possible flow is " << fordFulkerson(s-1, t-1);

    return 0;
}
