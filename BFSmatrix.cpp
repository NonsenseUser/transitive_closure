#include <iostream>
#include <vector>
#include <queue>
#include <set>

void BFSmatrix(std::vector<std::vector<int>> graph) {
    int n = graph.size();
    std::vector<std::vector<int>> closure(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        closure[i][i] = 1;
    }

    for (int start = 0; start < n; ++start) {
        std::queue<int> toCheck;
        std::set<int> checked;
        toCheck.push(start);

        while (!toCheck.empty()) {
            int vertex = toCheck.front();
            toCheck.pop();

            for (int neighbor = 0; neighbor < n; ++neighbor) {
                if (graph[vertex][neighbor] != 0 && !checked.count(vertex)) {
                    closure[start][neighbor] = 1; 
                    toCheck.push(neighbor); 
                }
            }
            checked.insert(vertex);
        }
    }


   /*for (const auto& row : closure) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }*/
}
