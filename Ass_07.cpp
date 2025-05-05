#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#define SIZE 6

using namespace std;

class Graph {
private:
    string cities[SIZE];
    int adj_mat[SIZE][SIZE];

public:
    Graph() {}

    void prims_shortest_path(int start) {
        if (start >= SIZE)
            return;

        int parent[SIZE];     // To store MST
        int key[SIZE];        // Minimum weights to include vertex
        bool mstSet[SIZE];    // Vertices included in MST

        for (int i = 0; i < SIZE; ++i) {
            key[i] = 999;
            mstSet[i] = false;
        }

        key[start] = 0;
        parent[start] = -1; // First node is root of MST

        for (int count = 0; count < SIZE - 1; ++count) {
            int min = 999, u;

            for (int v = 0; v < SIZE; ++v)
                if (!mstSet[v] && key[v] < min)
                    min = key[v], u = v;

            mstSet[u] = true;

            for (int v = 0; v < SIZE; ++v)
                if (adj_mat[u][v] && !mstSet[v] && adj_mat[u][v] < key[v])
                    parent[v] = u, key[v] = adj_mat[u][v];
        }

        // Output MST
        int total = 0;
        cout << "\nMinimum Spanning Tree Edges:\n";
        for (int i = 0; i < SIZE; ++i) {
            if (parent[i] != -1) {
                cout << "Going from " << cities[parent[i]] << " - " << cities[i]
                     << " (Cost: " << adj_mat[i][parent[i]] << ")\n";
                total += adj_mat[i][parent[i]];
            }
        }

        cout << "\nTotal cost of Minimum Spanning Tree = " << total << endl;
    }

    void get_routes() {
        for (int i = 0; i < SIZE; ++i) {
            cout << "Enter city-" << i + 1 << ": ";
            cin >> cities[i];
        }

        cout << "\nIf no connectivity, enter Cost = 0.\n";
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (i == j) {
                    adj_mat[i][j] = 0;
                    continue;
                }

                cout << cities[i] << " -> " << cities[j] << ": ";
                cin >> adj_mat[i][j];

                // For undirected graph, mirror the weight
                adj_mat[j][i] = adj_mat[i][j];
            }
        }
    }

    void show_chart() {
        cout << "\n------------------- Adjacency Matrix -------------------\n";
        cout << setw(10) << "|";
        for (int i = 0; i < SIZE; ++i)
            cout << setw(cities[i].length() + 2) << cities[i] << "|";
        cout << "\n--------------------------------------------------------";
        for (int i = 0; i < SIZE; ++i) {
            cout << "\n" << setw(9) << cities[i] << "|";
            for (int j = 0; j < SIZE; ++j)
                cout << setw(cities[j].length() + 2) << adj_mat[i][j] << "|";
        }
        cout << "\n--------------------------------------------------------\n";
    }
};

int main() {
    Graph G1;
    G1.get_routes();
    G1.show_chart();
    G1.prims_shortest_path(0);  // Starting from the first city

    return 0;
}
