// Perform BFS to collect all nodes belonging to the same connected component.
void bfs(int start, vector<int> &vis, vector<vector<int>> &graph,
         unordered_map<int, vector<int>> &components) {

    queue<int> q;
    vis[start] = 1;
    components[start].push_back(start);
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Visit all unvisited neighbors.
        for (int neighbor : graph[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push(neighbor);
                components[start].push_back(neighbor);
            }
        }
    }
}

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        // Build adjacency list.
        vector<vector<int>> graph(n);

        // Store all edges for fast existence checking.
        set<pair<int, int>> edgeSet;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            // Store both directions since the graph is undirected.
            edgeSet.insert({u, v});
            edgeSet.insert({v, u});
        }

        unordered_map<int, vector<int>> components;
        vector<int> vis(n, 0);

        // Find all connected components.
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bfs(i, vis, graph, components);
            }
        }

        int completeComponents = 0;

        // Check every connected component.
        for (auto &entry : components) {

            vector<int> &nodes = entry.second;
            bool isComplete = true;

            // Every pair of vertices must have an edge.
            for (int i = 0; i < nodes.size() && isComplete; i++) {
                for (int j = i + 1; j < nodes.size(); j++) {

                    if (!edgeSet.count({nodes[i], nodes[j]})) {
                        isComplete = false;
                        break;
                    }
                }
            }

            if (isComplete)
                completeComponents++;
        }

        return completeComponents;
    }
};