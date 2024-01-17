#include <bits/stdc++.h>
using namespace std;

vector<int> adj[20001];
int colors[20001];

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    colors[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (colors[v] == colors[u]) {
                return false; // Not Bipartite
            }
            if (colors[v] == 0) {
                colors[v] = -colors[u];
                q.push(v);
            }
        }
    }

    return true; // Bipartite
}

bool isBipartite(int n) {
    for (int i = 1; i <= n; ++i) {
        if (colors[i] == 0 && !bfs(i)) {
            return false; // Not Bipartite
        }
    }
    return true; // Bipartite
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            colors[i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (isBipartite(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}