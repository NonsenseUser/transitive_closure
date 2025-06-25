/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <chrono>
#include "BFSmatrix.h"
#include "BFSvect.h"
#include <cmath>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int matrWrapper(std::vector<std::vector<int>> graphMatr) {
    auto start = std::chrono::high_resolution_clock::now();
    BFSmatrix(graphMatr);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    //std::cout << "Time taken by BFSmatrix: " << duration.count() << " milliseconds." << std::endl;
    return duration.count();
}

 int vectWrapper(std::vector<std::vector<int>> graphVect) {
    auto start = std::chrono::high_resolution_clock::now();
    BFSvect(graphVect);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    //std::cout << "Time taken by BFSvect: " << duration.count() << " milliseconds." << std::endl;
    return duration.count();
}

// Function to generate a matrix filled with zeros and ones
vector<vector<int>> generateMatrix(int size, float density) {
    vector<vector<int>> matrix(size, vector<int>(size, 0));
    int numOnes = static_cast<int>(size * size * density);

    // Randomly place ones in the matrix
    while (numOnes > 0) {
        int row = rand() % size;
        int col = rand() % size;
        if (matrix[row][col] == 0) {
            matrix[row][col] = 1;
            numOnes--;
        }
    }
    return matrix;
}

// Function to convert matrix to adjacency list
vector<vector<int>> matrixToAdjacencyList(const vector<vector<int>>& matrix) {
    vector<vector<int>> adjList(matrix.size());
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}

// Function to align adjacency lists by adding zeros
void alignAdjacencyLists(vector<vector<int>>& adjLists) {
    // Find the maximum size of the lists
    size_t maxSize = 0;
    for (const auto& list : adjLists) {
        maxSize = max(maxSize, list.size());
    }

    // Pad each list with zeros until they are all the same size
    for (auto& list : adjLists) {
        while (list.size() < maxSize) {
            list.push_back(0); // Padding with zero
        }
    }
}

int main()
{   
    int exit = -1;
    //do{
    //    //std::vector<std::vector<int>> graphMatr = {
    //    //{0, 1, 1, 1, 1},
    //    //{1, 0, 1, 1, 1},
    //    //{1, 1, 0, 1, 1},
    //    //{1, 1, 1, 0, 1},
    //    //{1, 1, 1, 1, 0}
    //    //};
    //    //std::cout << "Example 1 (matrix):" << '\n';
    //    //matrWrapper(graphMatr);

    //    //std::vector<std::vector<int>> graphVect = {
    //    //{2, 3, 4, 5},
    //    //{1, 3, 4, 5},
    //    //{1, 2, 4, 5},
    //    //{1, 2, 3, 5},
    //    //{1, 2, 3, 4}
    //    //};
    //    //std::cout << "Example 1 (vector):" << '\n';
    //    //vectWrapper(graphVect);

    //    //graphMatr = std::vector<std::vector<int>>(100, std::vector<int>(100, 0));

    //    //// Заполнение матрицы смежности
    //    //graphMatr[0][1] = 1;
    //    //graphMatr[0][2] = 1;
    //    //graphMatr[1][3] = 1;
    //    //graphMatr[3][4] = 1;
    //    //graphMatr[5][6] = 1;
    //    //graphMatr[6][7] = 1;
    //    //graphMatr[8][9] = 1;
    //    //graphMatr[10][11] = 1;
    //    //graphMatr[12][13] = 1;
    //    //graphMatr[14][15] = 1;

    //    //std::cout << "Example 2 (matrix):" << '\n';
    //    //matrWrapper(graphMatr);

    //    //graphVect = std::vector<std::vector<int>>(100);

    //    //// Заполнение списков смежности
    //    //graphVect[0] = { 2, 3 };
    //    //graphVect[1] = { 4 };
    //    //graphVect[3] = { 5 };
    //    //graphVect[5] = { 7 };
    //    //graphVect[6] = { 8 };
    //    //graphVect[8] = { 10 };
    //    //graphVect[10] = { 12 };
    //    //graphVect[12] = { 14 };
    //    //graphVect[14] = { 16 };

    //    //std::cout << "Example 2 (vector):" << '\n';
    //    //vectWrapper(graphVect);
       /* int inputType = -1;
        double inputValue;
        int rows, cols;

        // Prompt for input type
        do {
            std::cout << "Press 1 to enter an adjacency matrix, or 2 to enter adjacency lists" << '\n';
            std::cin >> inputType;
        } while ((inputType != 1) && (inputType != 2));


        do {
            if (inputType == 2) {
                std::cout << "Enter the number of rows (integer): ";
            }
            else
            {
                std::cout << "Enter the number of vertices (integer): ";
            }
            std::cin >> inputValue;
        } while ((inputValue <= 0) && (floor(inputValue) == inputType)); // Ensure a valid positive integer
       rows = inputValue;

        if (inputType == 2) {
           do {
                std::cout << "Enter the number of columns (integer): ";
                std::cin >> inputValue;
            } while ((inputValue <= 0) && (floor(inputValue) == inputType)); // Ensure a valid positive integer
            cols = inputValue;
        }
        else {
            cols = rows;
        }

        if (inputType == 1) {
            std::cout << "Enter values (0 or 1):" << '\n';
        }

        if (inputType == 2) {
            std::string str = std::format("Enter values (integers, more or equal to zero, no more than {}):", rows);
            std::cout << str << '\n';
        }

        std::vector<std::vector<int>> graph(rows, std::vector<int>(cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (inputType == 1) {
                    do {
                        std::string str = std::format("Value for cell ({}, {})", i+1, j+1);
                        std::cout << str << '\n';
                        std::cin >> inputValue;
                    } while (!(inputValue == 0) && !(inputValue == 1)); // Check for valid integer input
                }
                else {
                    do {
                        std::string str = std::format("Value for cell ({}, {})", i+1, j+1);
                        std::cout << str << '\n';
                        std::cin >> inputValue;
                    } while (!(floor(inputValue) == inputType) && !(inputValue <= rows)); // Check for valid integer input
                }
                graph[i][j] = inputValue - 1;
            }
        }

       if (inputType == 1) {
           matrWrapper(graph);
        }
        else {
            vectWrapper(graph);
        }

        std::cout << "Press escape to exit the program, press any other key for a new calculation"<< '\n';
        do {
            if (_kbhit()) { // Проверяет, была ли нажата клавиша
                char ch = _getch(); // Считывает нажатую клавишу
                if (ch == 27) { // Код клавиши ESC - 27
                    std::cout << "ESC pressed. Exiting..." << std::endl;
                    exit = 1; // Выход из цикла
                }
                else {
                    exit = 0;
                }
            }
        } while ((exit != 1) && (exit != 0));
    } while (exit != 1);*/
    
    /*std::vector<std::vector<int>> graphMatr = {
        {1, 1, 0},
        {0, 0, 1},
        {0, 0, 0},
      };
    std::cout << "Example 1 (matrix):" << '\n';
    matrWrapper(graphMatr);

    std::cout << "Example 1 (adjList):" << '\n';
    vectWrapper(matrixToAdjacencyList(graphMatr));

    std::cout << '\n';
    graphMatr = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 0, 1},
    };
    std::cout << "Example 2 (matrix):" << '\n';
    matrWrapper(graphMatr);
    std::cout << "Example 2 (adjList):" << '\n';
    vectWrapper(matrixToAdjacencyList(graphMatr));*/

    srand(static_cast<unsigned>(time(0)));
    
    vector<float> matrTime = vector<float>(15, 0);
    vector<float> vectTime = vector<float>(15, 0);
    for (int k = 0; k < 10; ++k) {
        vector<int> sizes;
       
        for (int i = 5; i < 20; ++i) {
            sizes.push_back(i);
        }
        vector<float> densities = { 1.0f };

        for (int j = 0; j < sizes.size(); ++j) {
            //std::cout << "Size: " << sizes[j] << '\n';
            for (float density : densities) {
                vector<vector<int>> matrix = generateMatrix(sizes[j], density);

                vector<vector<int>> adjList = matrixToAdjacencyList(matrix);

                alignAdjacencyLists(adjList);
                //std::cout << "Density: " << density<<'\n';
                matrTime[j] += matrWrapper(matrix);
                vectTime[j] += vectWrapper(adjList);
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        matrTime[i] = matrTime[i] / 10.0;
        vectTime[i] = vectTime[i] / 10.0;
    }
    std::cout << "Matr Time" << '\n';
    for (int i = 0; i < 10; ++i) {
        std::cout << matrTime[i] << '\n';

    }
    std::cout << "List Time" << '\n';
    for (int i = 0; i < 10; ++i) {
        std::cout << vectTime[i] << '\n';
    }
    return 0;
}