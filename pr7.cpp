#include <iostream>
#include <vector>
#include <limits>
#define MAX_NUM_CITIES 10
using namespace std;

struct Edge {
    int start, end, wt;
};

class Graph {
    int adj_mat[MAX_NUM_CITIES][MAX_NUM_CITIES];
    string city_names[MAX_NUM_CITIES];
    int city_count;
    Edge mst[MAX_NUM_CITIES - 1];
    int cost;
    void add_to_list(vector<Edge>&, Edge);
public:
    Graph();
    void prims_algo(int);
    void display_mst();
};

void Graph::add_to_list(vector<Edge>& list, Edge e) {
    list.push_back(e);
    for (int i = list.size() - 1; i > 0; i--) {
        if (list[i].wt < list[i - 1].wt) {
            swap(list[i], list[i - 1]);
        } else {
            break;
        }
    }
}

Graph::Graph() {
    cost = 0;
    cout << "Enter number of cities (1-" << MAX_NUM_CITIES << "): ";
    cin >> city_count;
    city_count = min(city_count, MAX_NUM_CITIES);
    for (int i = 0; i < city_count; i++) {
        cout << "Enter city name " << i + 1 << ": ";
        cin >> city_names[i];
    }
    for (int i = 0; i < city_count; i++)
        for (int j = 0; j < city_count; j++)
            adj_mat[i][j] = numeric_limits<int>::max();
    int num_pairs;
    cout << "Enter number of city pairs: ";
    cin >> num_pairs;
    cout << "City codes:\n";
    for (int i = 0; i < city_count; i++) {
        cout << i << " - " << city_names[i] << endl;
    }
    int x, y, wt;
    for (int i = 0; i < num_pairs; i++) {
        cout << "Enter city indices for pair " << i + 1 << ": ";
        cin >> x >> y;
        if (x >= city_count || y >= city_count || x < 0 || y < 0) {
            cout << "Invalid city indices. Try again." << endl;
            i--;
            continue;
        }
        cout << "Enter cost between " << city_names[x] << " & " << city_names[y] << ": ";
        cin >> wt;
        adj_mat[x][y] = adj_mat[y][x] = wt;
    }
}

void Graph::prims_algo(int start) {
    bool visited[MAX_NUM_CITIES] = {0};
    int visited_count = 1;
    visited[start] = 1;
    vector<Edge> adj;
    for (int i = 0; i < city_count; i++) {
        if (adj_mat[start][i] != numeric_limits<int>::max()) {
            Edge e = {start, i, adj_mat[start][i]};
            add_to_list(adj, e);
        }
    }
    while (visited_count < city_count) {
        Edge m = adj.front();
        adj.erase(adj.begin());
        if (!visited[m.end]) {
            mst[visited_count - 1] = m;
            cost += m.wt;
            for (int i = 0; i < city_count; i++) {
                if (adj_mat[m.end][i] != numeric_limits<int>::max() && !visited[i]) {
                    Edge e = {m.end, i, adj_mat[m.end][i]};
                    add_to_list(adj, e);
                }
            }
            visited[m.end] = 1;
            visited_count++;
        }
    }
}

void Graph::display_mst() {
    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < city_count - 1; i++) {
        cout << city_names[mst[i].start] << " - " << city_names[mst[i].end] << " : " << mst[i].wt << endl;
    }
    cout << "Total Cost: " << cost << endl;
}

int main() {
    Graph g;
    int start;
    cout << "Enter start city index: ";
    cin >> start;
    start = (start >= MAX_NUM_CITIES || start < 0) ? 0 : start;
    g.prims_algo(start);
    g.display_mst();
    return 0;
}

