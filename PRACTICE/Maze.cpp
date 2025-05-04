#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib> 
#include <ctime>  
using namespace std;

struct Cell {
    int x, y;
    vector<pair<int, int>> path;  
};

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// BFS function to find shortest path
void bfsMazePath(vector<vector<int>> &maze, int N, int M) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<Cell> q;
    q.push({0, 0, {{0, 0}}});
    visited[0][0] = true;

    bool found = false;

    while (!q.empty()) {
        Cell current = q.front(); q.pop();

        if (current.x == N - 1 && current.y == M - 1) {
            found = true;

            cout << "\nPath from (0,0) to (" << N-1 << "," << M-1 << "):\n";
            for (auto p : current.path) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << endl;
            break;
        }

        for (int dir = 0; dir < 8; dir++) {
            int nx = current.x + dx[dir];
            int ny = current.y + dy[dir];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
                maze[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                auto newPath = current.path;
                newPath.push_back({nx, ny});
                q.push({nx, ny, newPath});
            }
        }
    }

    if (!found) {
        cout << "\nNo path found!\n";
    }
}

int main() {
    int N, M;
    cout << "Enter rows (N): ";
    cin >> N;
    cout << "Enter columns (M): ";
    cin >> M;

    vector<vector<int>> maze(N, vector<int>(M));
    srand(time(0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            maze[i][j] = rand() % 2;
        }
    }

    maze[0][0] = 0;
    maze[N - 1][M - 1] = 0;

    cout << "\nGenerated Maze (0=open, 1=blocked):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    bfsMazePath(maze, N, M);

}
