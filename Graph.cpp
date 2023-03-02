#include "Graph.h"
#include <iostream>
#include <string>

#define VERYBIGINT 1000000000


//ДОБАВЛЕНИЕ ВЕРШИНЫ
//Метод добавления вершины будет заключаться в занесении номера новой вершины в массив вершин vertexes
//и увеличении счетчика количества вершин vertexCount
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount++] = vnumber;
}


//ДОБАВЛЕНИЕ РЕБРА
//Метод добавления ребра будет заключаться в занесении значения веса ребра weight в матрицу смежности
//с индексами вершин v1, v2, для которых добавляется ребро
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;//т.к матрица является симметричной
}


// ПРОВЕРКА СУЩЕСТВОВАНИЯ РЕБРА
// Для проверки, существует ли ребро, нужно посмотреть значение элемента матрицы смежности
// с индексами номеров вершин (если есть ребро, он отличен от 0)
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}


// ПРОВЕРКА СУЩЕСТВОВАНИЯ ВЕРШИНЫ
// Для проверки, существует ли вершина, нужно проверить, есть ли ее номер в массиве vertexes
bool Graph::vertexExists(int v)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == v)
            return true;
    return false;
}


int Graph::getVertex(int pos) {
    return vertexes[pos];
}


std::string Graph::getName(int pos) {
    return names[pos];
}