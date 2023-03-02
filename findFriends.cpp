//-------------------------------------------------------------------------------------//
//            ����� ���� ��������� ������, �������� ������� ���� �����������           //
//-------------------------------------------------------------------------------------//                                                                                     //
//                     �� ������ ��������� ������-��������                             //
//           (������� ���������� ���������� ����� ����� ����� ������ � �����)          //
//-------------------------------------------------------------------------------------//
#include <iostream>
#include "Graph.h"


#define VERYBIGINT 1000000000

void Graph::findAllFriends()
{
    int weights[SIZE][SIZE]; // ������� �����
    // ������������ �������
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) {
                weights[i][j] = 0; // ���� �� ����� ���� ����� 0
            }
            else {
                if (!edgeExists(i, j)) {
                    weights[i][j] = VERYBIGINT; // ���� ����� ���
                }
                else {
                    weights[i][j] = matrix[i][j]; // ���� ����� ����
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) { // �������� �� k
        int ck = vertexes[k]; // ������� ����� �������
        for (int i = 0; i < vertexCount; i++) {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++) {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // �������� ������� �����
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    std::cout << "���� ��������� ����� ��� �����������:" << std::endl;

    // ���������� ��� �������
    for (int i = 0; i < vertexCount; i++) {
        // ��������� ������� "���� �����������"
        for (int n = 1; n <= 3; n++) {
            // ��� ������ ������� ���� ���� ������
            for (int j = i + 1; j < vertexCount; j++) {
                if (weights[i][j] == n) {
                    std::cout << Graph::getName(vertexes[i]) << "-> " << Graph::getName(vertexes[j]) << std::endl;
                }
            }
        }
    }
}