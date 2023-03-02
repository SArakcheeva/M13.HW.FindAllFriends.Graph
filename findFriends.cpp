//-------------------------------------------------------------------------------------//
//            ПОИСК ВСЕХ ВОЗМОЖНЫХ ДРУЗЕЙ, СОГЛАСНО ПРАВИЛУ ТРЕХ РУКОПОЖАТИЙ           //
//-------------------------------------------------------------------------------------//                                                                                     //
//                     на основе Алгоритма ФЛОЙДА-УОРШЕЛЛА                             //
//           (находит кратчайшие расстояния между любой парой вершин в графе)          //
//-------------------------------------------------------------------------------------//
#include <iostream>
#include "Graph.h"


#define VERYBIGINT 1000000000

void Graph::findAllFriends()
{
    int weights[SIZE][SIZE]; // матрица путей
    // инициализаци матрицы
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) {
                weights[i][j] = 0; // путь до самой себя равен 0
            }
            else {
                if (!edgeExists(i, j)) {
                    weights[i][j] = VERYBIGINT; // если ребра нет
                }
                else {
                    weights[i][j] = matrix[i][j]; // если ребро есть
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) { // итерации по k
        int ck = vertexes[k]; // возьмем номер вершины
        for (int i = 0; i < vertexCount; i++) {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++) {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // пересчет матрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    std::cout << "Пары знакомств через три рукопожатия:" << std::endl;

    // перебираем все вершины
    for (int i = 0; i < vertexCount; i++) {
        // учитываем правило "трех рукопожатий"
        for (int n = 1; n <= 3; n++) {
            // для каждой вершины ищем всех друзей
            for (int j = i + 1; j < vertexCount; j++) {
                if (weights[i][j] == n) {
                    std::cout << Graph::getName(vertexes[i]) << "-> " << Graph::getName(vertexes[j]) << std::endl;
                }
            }
        }
    }
}