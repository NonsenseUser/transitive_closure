#include <iostream>
#include <vector>
#include <queue>
#include <set>
void BFSvect(std::vector<std::vector<int>> graph) {
    int n = graph.size();
    std::vector<std::vector<int>> closure(n, std::vector<int>(n, 0));

    for (int j = 0; j < n; ++j) {
        std::queue<int> toCheck;
        std::set<int> checked;
        closure[j][j] = 1;

        for (int neighbor : graph[j]) {
            if (neighbor >= 0 && neighbor < n) {
                toCheck.push(neighbor);
                closure[j][neighbor] = 1;
            }

            while (!toCheck.empty()) {
                int vertex = toCheck.front();
                toCheck.pop();

                for (int neighbor : graph[vertex]) {
                    if (closure[j][neighbor] == 0 && !checked.count(vertex)) {
                        closure[j][neighbor] = 1;
                        toCheck.push(neighbor);
                    }
                }
                checked.insert(vertex);
            }
        }
    }
    /*std::cout << "Transitive closure:" << "\n";
    for (const auto& row : closure) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }*/
}
//Польностью хаполненные матрицы с количеством вершин от 5 до 20