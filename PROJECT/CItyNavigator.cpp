#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <set>
#include <ctime>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

struct Edge {
    int distance;    // in km
    double speed;    // in km/h
};

vector<string> placeNames;
vector<vector<Edge>> graph;
bool specialDay = false;
double trafficMultiplier = 1.0;

// Read places from JSON file
bool loadPlaces(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open places file: " << filename << endl;
        return false;
    }
    json places_json;
    file >> places_json;
    placeNames = places_json.get<vector<string>>();
    return true;
}

// Read edges from JSON file
bool loadEdges(const string& filename, int n) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open edges file: " << filename << endl;
        return false;
    }
    json edges_json;
    file >> edges_json;

    graph.assign(n, vector<Edge>(n, {0, 0}));

    for (const auto& e : edges_json) {
        int u = e["u"];
        int v = e["v"];
        int dist = e["distance"];
        double spd = e["speed"];

        graph[u][v] = {dist, spd};
        graph[v][u] = {dist, spd};
    }
    return true;
}

// Check if today is special day from events JSON file
bool isSpecialDayFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open file " << filename << endl;
        return false;
    }

    json events;
    file >> events;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int day = ltm->tm_mday;
    int month = ltm->tm_mon + 1;

    for (const auto &event : events) {
        if (event["day"] == day && event["month"] == month) {
            cout << "🎉 Today is " << event["event"] << "!\n";
            return true;
        }
    }

    return false;
}

struct Node {
    int vertex;
    double dist;
    vector<int> path;

    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

void findTwoShortestPaths(int src, int dest, int n, bool useDistance, bool specialDay, double trafficMultiplier) {
    vector<vector<double>> dist(n, vector<double>(2, 1e9));
    vector<vector<vector<int>>> paths(n, vector<vector<int>>(2));
    
    priority_queue<Node> pq;

    dist[src][0] = 0;
    paths[src][0] = {src};
    pq.push({src, 0, {src}});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;
        double d = current.dist;
        vector<int>& p = current.path;

        if (u == dest && dist[dest][1] < 1e9) {
            break;
        }

        for (int v = 0; v < n; v++) {
            if (graph[u][v].distance > 0) {
                double weight;
                if (useDistance) {
                    weight = graph[u][v].distance;
                } else {
                    weight = graph[u][v].distance / graph[u][v].speed;
                    if (specialDay) weight *= 1.2;
                    weight *= trafficMultiplier; 
                }

                double newDist = d + weight;

                if (newDist < dist[v][0]) {
                    dist[v][1] = dist[v][0];
                    paths[v][1] = paths[v][0];

                    dist[v][0] = newDist;
                    paths[v][0] = p;
                    paths[v][0].push_back(v);

                    pq.push({v, dist[v][0], paths[v][0]});
                } else if (newDist > dist[v][0] && newDist < dist[v][1]) {
                    dist[v][1] = newDist;
                    paths[v][1] = p;
                    paths[v][1].push_back(v);

                    pq.push({v, dist[v][1], paths[v][1]});
                }
            }
        }
    }

    auto printPath = [&](int idx) {
        for (size_t i = 0; i < paths[dest][idx].size(); i++) {
            cout << placeNames[paths[dest][idx][i]];
            if (i + 1 < paths[dest][idx].size()) cout << " -> ";
        }
    };

    if (dist[dest][0] == 1e9) {
        cout << "No path from " << placeNames[src] << " to " << placeNames[dest] << endl;
        return;
    }

    cout << (useDistance ? "Shortest distance path:" : "Shortest time path:") << endl;
    cout << "1) Distance: " << dist[dest][0] << (useDistance ? " km" : " hours") << endl;
    if (!useDistance) cout << "   (" << int(dist[dest][0] * 60) << " minutes)" << endl;
    cout << "   Path: "; printPath(0);
    cout << endl;

    if (dist[dest][1] < 1e9) {
        cout << "2) Distance: " << dist[dest][1] << (useDistance ? " km" : " hours") << endl;
        if (!useDistance) cout << "   (" << int(dist[dest][1] * 60) << " minutes)" << endl;
        cout << "   Path: "; printPath(1);
        cout << endl;

        if (!useDistance) {
            double diff = (dist[dest][1] - dist[dest][0]) * 60;
            cout << "   Second path is approx. " << int(diff) << " minutes slower than the first.\n";
        }
    } else {
        cout << "No second shortest path found.\n";
    }

    cout << "\n";
}

#include <iostream>
using namespace std;

int main() {
    if (!loadPlaces("places.json")) {
        cout << " Failed to load places data.\n";
        return 1;
    }
    int n = (int)placeNames.size();

    if (!loadEdges("edges.json", n)) {
        cout << " Failed to load edge data.\n";
        return 1;
    }

    specialDay = isSpecialDayFromFile("events.json");

    cout << "\n==============================\n";
    cout << "    Welcome to Route Finder\n";
    cout << "==============================\n";

    cout << "\nPlease select the time of day:\n";
    cout << "   morning\n";
    cout << "   noon\n";
    cout << "   evening\n";
    cout << "   night\n";
    cout << "Your choice: ";

    string timeOfDay;
    cin >> timeOfDay;

    if (timeOfDay == "morning" || timeOfDay == "evening") {
        trafficMultiplier = 1.5;
    } else if (timeOfDay == "noon") {
        trafficMultiplier = 1.1;
    } else if (timeOfDay == "night") {
        trafficMultiplier = 1.3;
    } else {
        cout << " Invalid time of day. Using default traffic settings.\n";
        trafficMultiplier = 1.0;
    }

    cout << "\n Available Places:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  [" << i << "] " << placeNames[i] << endl;
    }

    int src, dest;
    cout << "\nEnter the **source** place number (0 - " << n - 1 << "): ";
    cin >> src;

    if (src < 0 || src >= n) {
        cout << " Invalid source index. Please restart the program.\n";
        return 1;
    }

    cout << "Enter the destination place number (0 - " << n - 1 << "): ";
    cin >> dest;

    if (dest < 0 || dest >= n) {
        cout << " Invalid destination index. Please restart the program.\n";
        return 1;
    }

    cout << "\n Calculating shortest paths by distance...\n";
    findTwoShortestPaths(src, dest, n, true, specialDay, 1.0);

    cout << "\n Calculating shortest paths by **time** (considering traffic)...\n";
    findTwoShortestPaths(src, dest, n, false, specialDay, trafficMultiplier);

}
