#include <iostream>
using namespace std;

const int MAX_VERTICES = 20;
int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int vertices, edgeCount = 0;
bool isDirected;

// Insert edge
void insertEdge(int v1, int v2) {
    if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
        if (graph[v1][v2] == 0) {
            graph[v1][v2] = 1;
            edgeCount++;
            if (!isDirected) {
                graph[v2][v1] = 1;
            }
        }
    } else {
        cout << "Invalid vertices!\n";
    }
}

// Display adjacency matrix
void displayMatrix() {
    cout << "\nAdjacency Matrix:\n    ";
    for (int i = 0; i < vertices; i++) cout << i << " ";
    cout << "\n   ";
    for (int i = 0; i < vertices; i++) cout << "--";
    cout << "\n";
    
    for (int i = 0; i < vertices; i++) {
        cout << i << " | ";
        for (int j = 0; j < vertices; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Total vertices: " << vertices << endl;
    cout << "Total edges: " << edgeCount << endl;
}

// Degree calculation
void calculateDegrees() {
    cout << "\nDegree Information:\n";
    for (int i = 0; i < vertices; i++) {
        int inDeg = 0, outDeg = 0;
        for (int j = 0; j < vertices; j++) {
            if (graph[j][i]) inDeg++;
            if (graph[i][j]) outDeg++;
        }

        if (isDirected) {
            cout << "Vertex " << i << ": In-degree = " << inDeg << ", Out-degree = " << outDeg << endl;
        } else {
            cout << "Vertex " << i << ": Degree = " << inDeg << endl;
        }
    }
}

// Find path using manual stack
void findPath(int start, int end) {
    bool visited[MAX_VERTICES] = {false};
    int stack[MAX_VERTICES], top = -1;

    stack[++top] = start;

    while (top != -1) {
        int current = stack[top--];
        if (current == end) {
            cout << "Path exists from " << start << " to " << end << "!\n";
            return;
        }
        if (!visited[current]) {
            visited[current] = true;
            for (int i = vertices - 1; i >= 0; i--) {
                if (graph[current][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    cout << "No path exists from " << start << " to " << end << ".\n";
}

int main() {
    cout << "==== Graph using Adjacency Matrix ====\n";
    cout << "Enter number of vertices (max " << MAX_VERTICES << "): ";
    cin >> vertices;

    if (vertices > MAX_VERTICES || vertices <= 0) {
        cout << "Invalid number of vertices!\n";
        return 1;
    }

    int graphType;
    cout << "Choose graph type:\n1. Directed\n2. Undirected\nEnter your choice: ";
    cin >> graphType;
    isDirected = (graphType == 1);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Edge\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Show Degree Info\n";
        cout << "4. Find Path Between Two Vertices\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int v1, v2;
                cout << "Enter edge (From -> To): ";
                cin >> v1 >> v2;
                insertEdge(v1, v2);
                break;
            }
            case 2:
                displayMatrix();
                break;
            case 3:
                calculateDegrees();
                break;
            case 4: {
                int start, end;
                cout << "Enter start and end vertex: ";
                cin >> start >> end;
                findPath(start, end);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
