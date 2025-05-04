// ******************   Undirected unweighted graph    **********************

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int vertex,edges;
    cout << "Enter vertexes: ";
    cin >> vertex;
    cout << "Enter edges: ";
    cin >> edges;
    vector<vector<int>>AdjList(vertex);
    int u,v;
    for(int i = 0 ; i < edges ; i++){
        cin >> u >> v;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
    }
    for(int i = 0 ; i < vertex ; i++){
        cout << i << " --> ";
        for(int j = 0 ; j < AdjList[i].size() ; j++){
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }
}

// ******************   Undirected  weighted graph    **********************

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int vertex,edges;
    cout << "Enter vertexes: ";
    cin >> vertex;
    cout << "Enter edges: ";
    cin >> edges;
    vector<vector<pair<int,int>>>AdjList(vertex);
    int u,v,w;
    for(int i = 0 ; i < edges ; i++){
        cin >> u >> v >> w;
            AdjList[u].push_back(make_pair(v,w));
            AdjList[v].push_back(make_pair(u,w));
    }
    for(int i = 0 ; i < vertex ; i++){
        cout << i << " --> ";
        for(int j = 0 ; j < AdjList[i].size() ; j++){
            cout << "("<< AdjList[i][j].first << "," << AdjList[i][j].second << ")" << " ";
        }
        cout << endl;
    }
}

// ******************   With Map and Linked List graph    **********************

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
  public:
  unordered_map<int,list<int> > adj;
  void addEdge(int u,int v , bool direction = 0 ){
    adj[u].push_back(v);
    if(!direction){
        adj[v].push_back(u);
    }
  }
  void printAdjList(int vertex){
     for(auto pair : adj){
        cout << pair.first << "-->";
        for(int neighbours : pair.second){
            cout << neighbours << ", ";
        }
        cout << endl;
     }
  }
};

int main(){
    int vertex,edges;
    cout << "Enter vertexes: ";
    cin >> vertex;
    cout << "Enter edges: ";
    cin >> edges;
    graph g;
    int u,v;
    for(int i = 0 ; i < edges ; i++){
        cin >> u >> v;
        g.addEdge(u,v);
    }
    g.printAdjList(vertex);
}

// ******************   BFS TRAVERSAL   **********************

// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// class graph {
// public:
//     int vertex;
//     vector<vector<int>> AdjList;
//     graph(int v) {
//         this->vertex = v;
//         AdjList.resize(v);
//     }
//     void addEdge(int u, int v,bool directed = 0) {
//         AdjList[u].push_back(v);
//         if(!directed){
//             AdjList[v].push_back(u);
//         }
//     }
//     vector<int> BfsOfGraph(){
//        queue<int>q;
//        q.push(0);
//        vector<bool>visited(this->vertex,0);
//        visited[0] = 1;
//        vector<int>ans;
//        while(!q.empty()){
//          int node = q.front();
//          q.pop();
//          ans.push_back(node);
//          for(int j = 0 ; j < AdjList[node].size();j++){
//             if(!visited[AdjList[node][j]]){
//                 visited[AdjList[node][j]] = 1;
//                 q.push(AdjList[node][j]);
//             }
//          }
//        }
//        return ans;
//     }
// };

// int main() {
//     int vertex, edges;
//     cout << "Enter vertexes: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;
//     graph g(vertex);
//     int u, v;
//     for (int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         g.addEdge(u, v);
//     }
//     for(auto x : g.BfsOfGraph()){
//           cout << x << " ";
//     }
// }

// ****************** WITH LIST AND MAP

// #include<iostream>
// #include<unordered_map>
// #include<vector>
// #include<list>
// #include<queue>
// using namespace std;

// class graph {
// public:
//     unordered_map<int, list<int>> AdjList;
//     int vertex = 0; // To keep track of the largest node index

//     graph(int v){
//         this->vertex = v;
//     }

//     void addEdge(int u, int v, bool directed = 0) {
//         AdjList[u].push_back(v);
//         if (!directed) {
//             AdjList[v].push_back(u);
//         }
//     }

//     vector<int> BfsOfGraph(int start) {
//         queue<int> q;

//         vector<bool> visited(vertex, false);
//         vector<int> ans;

//         q.push(start);
//         visited[start] = true;

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();
//             ans.push_back(node);

//             for (auto j : AdjList[node]) {
//                 if (!visited[j]) {
//                     visited[j] = true;
//                     q.push(j);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// int main() {
//     int vertex, edges;
//     cout << "Enter vertexes: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     graph g(vertex);
//     int u, v;
//     for (int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         g.addEdge(u, v);
//     }

//     vector<int> bfs = g.BfsOfGraph(0);
//     for (int x : bfs) {
//         cout << x << " ";
//     }
// }

// *****************************   DFS TRAVERSAL  *****************

// #include<iostream>
// #include<unordered_map>
// #include<vector>
// #include<list>
// using namespace std;

// class graph {
// public:
//     unordered_map<int, list<int>> AdjList;
//     int vertex = 0;

//     graph(int v){
//         this->vertex = v;
//     }

//     void addEdge(int u, int v, bool directed = 0) {
//         AdjList[u].push_back(v);
//         if (!directed) {
//             AdjList[v].push_back(u);
//         }
//     }

//     void dfs(int node, vector<bool>& visited, vector<int>& ans){
//         visited[node] = true;
//         ans.push_back(node);

//         for(auto neighbor : AdjList[node]){
//             if(!visited[neighbor]){
//                 dfs(neighbor, visited, ans);
//             }
//         }
//     }

//     vector<int> DfsTraversal(){
//         vector<bool> visited(vertex, false);
//         vector<int> ans;
//         for(int i = 0; i < vertex; i++){
//             if(!visited[i]){
//                 dfs(i, visited, ans);
//             }
//         }
//         return ans;
//     }
// };

// int main() {
//     int vertex, edges;
//     cout << "Enter vertexes: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     graph g(vertex);
//     int u, v;
//     for (int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         g.addEdge(u, v);
//     }

//     vector<int> dfs = g.DfsTraversal();
//     for(int x : dfs){
//         cout << x << " ";
//     }
// }

// ************************* Using stack

// // #include <iostream>
// // #include <unordered_map>
// // #include <list>
// // #include <vector>
// // #include <stack>
// // using namespace std;

// // class Graph {
// // public:
// //     int vertex;
// //     unordered_map<int, list<int>> AdjList;

// //     Graph(int v) {
// //         vertex = v;
// //     }

// //     void addEdge(int u, int v, bool directed = 0) {
// //         AdjList[u].push_back(v);
// //         if (!directed) {
// //             AdjList[v].push_back(u);
// //         }
// //     }
// //     vector<int> dfsIterative() {
// //         unordered_map<int, bool> visited;
// //         vector<int> ans;
// //         stack<int> st;

// //         for (auto &nodePair : AdjList) {
// //             int startNode = nodePair.first;
// //             if (!visited[startNode]) {
// //                 st.push(startNode);

// //                 while (!st.empty()) {
// //                     int node = st.top();
// //                     st.pop();

// //                     if (!visited[node]) {
// //                         visited[node] = true;
// //                         ans.push_back(node);

// //                         for (auto neighbor : AdjList[node]) {
// //                             if (!visited[neighbor]) {
// //                                 st.push(neighbor);
// //                             }
// //                         }
// //                     }
// //                 }
// //             }
// //         }

// //         return ans;
// //     }

// // };

// int main() {
//     int vertex, edges;
//     cout << "Enter vertexes: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     Graph g(vertex);
//     int u, v;
//     for (int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         g.addEdge(u, v);
//     }

//     vector<int> dfs = g.dfsIterative();
//     cout << "DFS Traversal: ";
//     for (int x : dfs) {
//         cout << x << " ";
//     }
//     cout << endl;

//     return 0;
// }

// // ************************   DETECT CYCLE (Undirected)   ***********************

// **************************** Using DFS

// #include<iostream>
// #include<unordered_map>
// #include<vector>
// using namespace std;

// class graph {
// public:
//     vector<vector<int>> AdjList;
//     int vertex = 0;

//     graph(int v){
//         this->vertex = v;
//         AdjList.resize(v);
//     }

//     void addEdge(int u, int v, bool directed = 0) {
//         AdjList[u].push_back(v);
//         if (!directed) {
//             AdjList[v].push_back(u);
//         }
//     }
//     bool detectHelper(int node , int parent , unordered_map<int,bool>& visited){
//         visited[node] = 1;
//         for(int i = 0 ; i < AdjList[node].size();i++){
//             if(visited[AdjList[node][i]] && parent != AdjList[node][i]){
//                 return true;
//             }
//             if(!visited[AdjList[node][i]]){
//                 if(detectHelper(AdjList[node][i],node,visited)) return true;
//             }
//         }
//         return false;
//     }

//     bool detectCycle() {
//         unordered_map<int, bool> visited;
//         int parent = -1;
//         for(int i = 0 ; i < vertex ; i++){
//             if(!visited[i]) {
//                 if(detectHelper(i, -1, visited)) return true;
//             }
//         }
//         return false;
//     }

// };

// int main() {
//     int vertex, edges;
//     cout << "Enter vertexes: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     graph g(vertex);
//     int u, v;
//     for (int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         g.addEdge(u, v);
//     }

//     if(g.detectCycle()){
//         cout << "Cycle Detected...";
//     }else{
//         cout << "Cycle Not Detected...";
//     }
// }

// ************************* With List And Map


// #include<iostream>
// #include<unordered_map>
// #include<vector>
// #include<list>
// using namespace std;

// class graph {
// public:
//     unordered_map<int, list<int>> AdjList;
//     int vertex = 0;

//     graph(int v){
//         this->vertex = v;
//     }

//     void addEdge(int u, int v, bool directed = 0) {
//         AdjList[u].push_back(v);
//         if (!directed) {
//             AdjList[v].push_back(u);
//         }
//     }
//     bool detectHelper(int node , int parent , unordered_map<int,bool>& visited){
//         visited[node] = 1;
//         for(auto &neighbour : AdjList[node]){
//             if(visited[neighbour] && neighbour != parent){
//                 return true;
//             }
//             if(!visited[neighbour]) {
//                 if(detectHelper(neighbour, node, visited)) return true;
//             }
//         }
//         return false;
//     }

//     bool detectCycle() {
//         unordered_map<int, bool> visited;
//         for(auto& pair : AdjList){
//             if(!visited[pair.first]) {
//                 if(detectHelper(pair.first, -1, visited)) return true;
//             }
//         }
//         return false;
//     }

// };

// int main() {
//     int vertex, edges;
//     cout << "Enter vertexes: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     graph g(vertex);
//     int u, v;
//     for (int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         g.addEdge(u, v);
//     }

//     if(g.detectCycle()){
//         cout << "Cycle Detected...";
//     }else{
//         cout << "Cycle Not Detected...";
//     }
// }


// ***************************   With BFS     ***********************


// *********************** Basic Version


// #include<iostream>
// #include<unordered_map>
// #include<queue>
// #include<list>
// using namespace std;

// class graph {
// public:
//     vector<vector<int>> AdjList;
//     int vertex = 0;

//     graph(int v){
//         this->vertex = v;
//         AdjList.resize(v);
//     }

//     void addEdge(int u, int v, bool directed = 0) {
//         AdjList[u].push_back(v);
//         if (!directed) {
//             AdjList[v].push_back(u);
//         }
//     }
//     bool BFS(unordered_map<int,bool>&visited,int start = 0){
//         queue<pair<int,int>>q;
//         visited[start] = 1;
//         q.push({start,-1});
//         while(!q.empty()){
//             int node = q.front().first;
//             int parent = q.front().second;
//             q.pop();
//             for(int i = 0 ; i < AdjList[node].size();i++){
//                 if(AdjList[node][i] == parent){
//                     continue;
//                 }
//                 if(visited[AdjList[node][i]]){
//                    return 1;
//                 }
//                 visited[AdjList[node][i]] = 1;
//                 q.push({AdjList[node][i],node});
//             }
//         }
//         return 0;
//     }
//     bool detectCycle(int start = 0){
//         unordered_map<int,bool>visited;
//         for(int i = 0 ; i < vertex ; i++){
//             if(!visited[i]) {
//                 if(BFS(visited, i)) {
//                     return 1;
//                 }
//             }
//         }
//         return 0;
//     }
// };

// int main() {
//     int vertex, edges;
//     cout << "Enter vertexes: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     graph g(vertex);
//     int u, v;
//     for (int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         g.addEdge(u, v);
//     }

//     if(g.detectCycle()){
//         cout << "Cycle Detected...";
//     }else{
//         cout << "Cycle Not Detected...";
//     }
// }

// *********************** Advanced Version

#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> AdjList;
    int vertex = 0;

    graph(int v){
        this->vertex = v;
    }

    void addEdge(int u, int v, bool directed = 0) {
        AdjList[u].push_back(v);
        if (!directed) {
            AdjList[v].push_back(u);
        }
    }

    bool detectCycle(int start = 0){
        unordered_map<int,bool>visited;
        for(auto &pairs: AdjList){
            int start = pairs.first;
            if(!visited[start]){
                queue<pair<int,int>>q;
                q.push(make_pair(start,-1));
                visited[start] = 1;
                while(!q.empty()){
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for(auto &j : AdjList[node]){
                        if(visited[j] && parent != j) return 1;
                        if(!visited[j]){
                            visited[j] = 1;
                            q.push({j,node});
                        }
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    int vertex, edges;
    cout << "Enter vertexes: ";
    cin >> vertex;
    cout << "Enter edges: ";
    cin >> edges;

    graph g(vertex);
    int u, v;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if(g.detectCycle()){
        cout << "Cycle Detected...";
    }else{
        cout << "Cycle Not Detected...";
    }
}

// ****************************    FINDING PATH    *************************

// **************************** BFS

// #include <iostream>
// #include <algorithm>
// #include <unordered_map>
// #include <vector>
// #include <list>
// #include <queue>
// using namespace std;

// class Graph {
// public:
//     int vertex;
//     unordered_map<int,list<int>> AdjList;

//     Graph(int v) {
//         vertex = v;
//     }

//     void addEdge(int u, int v, bool directed = 0) {
//         AdjList[u].push_back(v) ;
//         if (!directed)
//         AdjList[v].push_back(u);
//     }

//     void printMatrix() {
//         cout << "\nAdjacency Matrix:\n";
//         for (auto& pair : AdjList) {
//             cout << pair.first << " --> ";
//             for (auto& neighbours: pair.second) {
//                 cout << neighbours << " ";
//             }
//             cout << endl;
//         }
//     }

//     void findPath(int start, int end) {

//         unordered_map<int,bool> visited;
//         vector<int> parent(vertex, -1);
//         queue<int> q;

//         q.push(start);
//         visited[start] = true;

//         while (!q.empty()) {
//             int curr = q.front(); q.pop();

//             if (curr == end) break;

//             for (auto& neighbours : AdjList[curr]) {
//                 if (!visited[neighbours]) {
//                     visited[neighbours] = true;
//                     parent[neighbours] = curr;
//                     q.push(neighbours);
//                 }
//             }
//         }

//         if (parent[end] == -1) {
//             cout << "No path found.\n";
//             return;
//         }

//         // Trace path
//         vector<int> path;
//             for (int i = end; i != -1; i = parent[i]){
//                 path.push_back(i);
//             }
//         reverse(path.begin(), path.end());

//         cout << "Path: ";
//         for (int node : path)
//             cout << node << " ";
//         cout << endl;
//     }
// };

// int main() {
//     int vertex, edges;
//     cout << "Enter vertexes: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     Graph g(vertex);
//     int u, v;
//     cout << "Enter edges (u v):\n";
//     for (int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         g.addEdge(u, v);
//     }

//     g.printMatrix();
//     do{
//         cout << "Enter paths to find (u v): ";
//         cin >> u >> v;
//         g.findPath(u, v);
//     }while(u != -1 || v != -1);

//     return 0;
// }


// **************************** DFS


// #include <iostream>
// #include <algorithm>
// #include <unordered_map>
// #include <vector>
// #include <list>
// using namespace std;

// class Graph {
// public:
//     int vertex;
//     unordered_map<int, list<int>> AdjList;

//     Graph(int v) {
//         vertex = v;
//     }

//     void addEdge(int u, int v, bool directed = 0) {
//         AdjList[u].push_back(v);
//         if (!directed)
//             AdjList[v].push_back(u);
//     }

//     void printMatrix() {
//         cout << "\nAdjacency List:\n";
//         for (auto &pair : AdjList) {
//             cout << pair.first << " --> ";
//             for (auto &neighbours : pair.second) {
//                 cout << neighbours << " ";
//             }
//             cout << endl;
//         }
//     }

//     void findPath(int start, int end, unordered_map<int, bool> &visited, vector<int> &parent) {
//         visited[start] = true;
//         if (start == end) {
//             visited[end] = true;
//             return;
//         }
//         for (auto &neighbour : AdjList[start]) {
//             if (!visited[neighbour]) {
//                 parent[neighbour] = start;
//                 findPath(neighbour, end, visited, parent);
//             }
//         }
//     }

//     void isPathFound(int u, int v) {
//         unordered_map<int, bool> visited;
//         vector<int> parent(vertex, -1);

//         findPath(u, v, visited, parent);

//         if (parent[v] == -1) {
//             cout << "No path found.\n";
//             return;
//         }

//         vector<int> path;
//         for (int i = v; i != -1; i = parent[i]) {
//             path.push_back(i);
//         }
//         reverse(path.begin(), path.end());

//         cout << "Path: ";
//         for (int node : path)
//             cout << node << " ";
//         cout << endl;
//     }
// };

// int main() {
//     int vertex, edges;
//     cout << "Enter vertexes: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     Graph g(vertex);
//     int u, v;
//     cout << "Enter edges (u v):\n";
//     for (int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         g.addEdge(u, v);
//     }

//     g.printMatrix();

//     do {
//         cout << "\nEnter paths to find (u v) or -1 -1 to exit: ";
//         cin >> u >> v;
//         if (u == -1 && v == -1) break;
//         g.isPathFound(u, v);
//     } while (true);

//     return 0;
// }


// ***************************   Cycle Detection (directed)  ***********************


// #include<iostream>
// #include<unordered_map>
// #include<list>
// using namespace std;

// class graph {
// public:
//     unordered_map<int, list<int>> AdjList;
//     int vertex = 0;

//     graph(int v){
//         this->vertex = v;
//     }

//     void addEdge(int u, int v, bool directed = 0) {
//         AdjList[u].push_back(v);
//         if (!directed) {
//             AdjList[v].push_back(u);
//         }
//     }

//     void printAdjList(){
//         for(auto pair : AdjList){
//             cout << pair.first << "-->";
//             for(int neighbours : pair.second){
//                 cout << neighbours << ", ";
//             }
//             cout << endl;
//         }
//     }

//     bool detectHelper(int start,unordered_map<int,bool>&visited,unordered_map<int,bool>&DfsVisited){
//         visited[start] = 1;
//         DfsVisited[start] = 1;
//         for(auto& neighbour: AdjList[start]){
//             if(!visited[neighbour]){
//              if(detectHelper(neighbour,visited,DfsVisited)){
//                 return true;
//              };   
//             }
//             if(visited[neighbour] && DfsVisited[neighbour]){
//                 return true;
//             }
//         }
//         DfsVisited[start] = false;
//         return false;
//     }

//     bool detectCycle(){
//         unordered_map<int,bool>visited;
//         unordered_map<int,bool>DfsVisited;
//         for(auto& pairs : AdjList){
//             int start = pairs.first;
//             if(!visited[start]){
//                 if(detectHelper(start,visited,DfsVisited))
//                 return true;
//             }
//         }
//         return false;
//     }
// }; 

// int main() {
//     int vertex, edges;
//     cout << "Enter vertexes: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     graph g(vertex);
//     int u, v;
//     for (int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         g.addEdge(u, v,1);
//     }
//     g.printAdjList();
//     if(g.detectCycle()){
//         cout << "Cycle Detected...";
//     }
//     else{
//         cout << "No Cycle Detected...";
//     }
// }




// ************************  BFS (Topological sort se hoga)