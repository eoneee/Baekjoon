#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d;
const int MAXX = 51;
int graph[MAXX][MAXX];
bool visited[MAXX][MAXX];
int cnt = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs() {
    queue<pair<int, int>> clean;
    clean.push({r, c});

    while (!clean.empty()) {
        int x = clean.front().first;
        int y = clean.front().second;
        clean.pop();

        if (!visited[x][y] && graph[x][y] == 0) {
            visited[x][y] = true;
            cnt++;
        }

        bool moved = false;

        for (int i = 0; i < 4; i++) {
            int nd = (d + 3 - i) % 4;
            int nx = x + dx[nd];
            int ny = y + dy[nd];

            if (isValid(nx, ny) && !visited[nx][ny] && graph[nx][ny] == 0) {
                clean.push({nx, ny});
                d = nd;
                moved = true;
                break;
            }
        }

        if (!moved) {
            int bx = x - dx[d];
            int by = y - dy[d];
            if (isValid(bx, by) && graph[bx][by] == 0) {
                clean.push({bx, by});
            }
        }
    }
}

int main() {
    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    bfs();
    cout << cnt << endl;

    return 0;
}
