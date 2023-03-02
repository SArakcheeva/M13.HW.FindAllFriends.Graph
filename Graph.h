//--------------------------------------------------------------------------------------//
//  МОДЕЛЬ ХРАНЕНИЯ НЕОРИЕНТИРОВАННОГО, ВЗВЕШЕННОГО ГРАФА С ПОМОЩЬЮ МАТРИЦЫ СМЕЖНОСТИ   //
//--------------------------------------------------------------------------------------//
#pragma once
#include <iostream>
#include <string.h>

#define SIZE 5

class Graph {
public:
    Graph() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                matrix[i][j] = 0;
        vertexCount = 0;
    }
    
    void addVertex(int vnumber);                // добавление вершины
    void addEdge(int v1, int v2, int weight);   // добавление ребра   
    bool edgeExists(int v1, int v2);            // существует ли смежнная вершина 
    bool vertexExists(int v);

    int getVertex(int pos);
    std::string getName(int pos);

    void findAllFriends();  // поиск всех возможных друзей, согласно правилу трех рукопожатий


private:
    int matrix[SIZE][SIZE]; // матрица смежности
    int vertexes[SIZE];     // хранилище вершин
    int vertexCount;        // количество добавленных вершин
    std::string names[SIZE] = { "Олег", "Никита", "Настя", "Ваня", "Женя" };;// список имен людей
};