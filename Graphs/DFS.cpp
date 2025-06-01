#include<iostream>
#include<queue>
using namespace std;

class edge {
public:
    int data;
    int weight;
    edge* next;
};

class Node {
public:
    int data;
    edge* edgeList;
    Node* next;
};

class graph {
public:
    Node* start = NULL;

    void insertNode() {
        int a;
        cout << "Enter vertice number : ";
        cin >> a;
        Node* newNode = new Node();
        newNode->next = NULL;
        newNode->edgeList = NULL;
        newNode->data = a;
        if (start == NULL) {
            start = newNode;
        }
        else {
            Node* temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    Node* findver(int ver) {
        Node* temp = start;
        while (temp != NULL) {
            if (temp->data == ver)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void insertEdge() {
        int ver, ver2, w;
        cout << "Enter the vertice to insert the edge from ";
        cin >> ver;
        Node* v1 = findver(ver);
        cout << "Enter the second vertex it is connected to ";
        cin >> ver2;
        Node* v2 = findver(ver2);
        if (v1 == NULL || v2 == NULL) {
            cout << "One or both vertices not found!" << endl;
            return;
        }
        cout << "Enter the weight of the edge ";
        cin >> w;

        edge* newEdge = new edge();
        newEdge->data = ver2;
        newEdge->weight = w;
        newEdge->next = NULL;

        if (v1->edgeList == NULL) {
            v1->edgeList = newEdge;
        }
        else {
            edge* tempEdge = v1->edgeList;
            while (tempEdge->next != NULL) {
                tempEdge = tempEdge->next;
            }
            tempEdge->next = newEdge;
        }
    }

    void bfsTraversal(int startVertex) {
        const int MAX_VERTICES = 100;
        bool visited[MAX_VERTICES] = { false };
        queue<int> q;

        Node* startNode = findver(startVertex);
        if (!startNode) {
            cout << "Start vertex not found!" << endl;
            return;
        }

        q.push(startVertex);
        visited[startVertex] = true;

        cout << "BFS Traversal starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            Node* currentNode = findver(curr);
            edge* e = currentNode->edgeList;

            while (e != NULL) {
                if (!visited[e->data]) {
                    visited[e->data] = true;
                    q.push(e->data);
                }
                e = e->next;
            }
        }
        cout << endl;
    }

    void printNodes() {
        Node* temp = start;
        while (temp != NULL) {
            cout << temp->data << endl;

            if (temp->edgeList != NULL) {
                edge* e = temp->edgeList;
                while (e != NULL) {
                    cout << "Edge of vertice " << temp->data << " = ";
                    cout << e->data << " and weight is " << e->weight << endl;
                    e = e->next;
                }
                cout << endl;
            }

            temp = temp->next;
        }
    }
};

int main() {
    graph g;
    g.insertNode();
    g.insertNode();
    g.insertNode();
    g.insertNode();
    g.insertNode();
    g.insertNode();

    g.insertEdge();
    g.insertEdge();
    g.insertEdge();
    g.insertEdge();

    g.printNodes();

    cout << endl;
    g.bfsTraversal(1);
}
