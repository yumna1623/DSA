#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;  // Max grid size limit

struct Cell {
    int x, y, steps;
};

int dx[4] = {-1, 1, 0, 0};  // Up, Down, Left, Right
int dy[4] = {0, 0, -1, 1};

int findMinSteps(char grid[MAX][MAX], int N, int M) {
    bool visited[MAX][MAX] = {false};
    queue<Cell> q;

    int startX = -1, startY = -1;

    // Find Umar's starting position
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'U') {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    while (!q.empty()) {
        Cell current = q.front(); q.pop();

        // If Umar reached Home
        if (grid[current.x][current.y] == 'H') {
            return current.steps;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = current.x + dx[dir];
            int ny = current.y + dy[dir];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
                !visited[nx][ny] &&
                (grid[nx][ny] == '-' || grid[nx][ny] == 'H')) {
                visited[nx][ny] = true;
                q.push({nx, ny, current.steps + 1});
            }
        }
    }

    return -1;  // No path found
}

int main() {
    int N, M;
    cout << "Enter rows and columns: ";
    cin >> N >> M;

    char grid[MAX][MAX];

    cout << "Enter grid (U=Umar, H=Home, X=Obstacle, -=Empty):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout<< "Cell [" << i << "][" << j << "]: ";
            cin >> grid[i][j];
        }
    }

    int steps = findMinSteps(grid, N, M);

    if (steps != -1)
        cout << "Minimum steps Umar needs to reach Home: " << steps << endl;
    else
        cout << "No path found! Umar can't reach Home.\n";

    return 0;
}
