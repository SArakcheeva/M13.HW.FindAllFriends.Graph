#include "Graph.h"
#include <iostream>
#include <string>

#define VERYBIGINT 1000000000


//���������� �������
//����� ���������� ������� ����� ����������� � ��������� ������ ����� ������� � ������ ������ vertexes
//� ���������� �������� ���������� ������ vertexCount
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount++] = vnumber;
}


//���������� �����
//����� ���������� ����� ����� ����������� � ��������� �������� ���� ����� weight � ������� ���������
//� ��������� ������ v1, v2, ��� ������� ����������� �����
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;//�.� ������� �������� ������������
}


// �������� ������������� �����
// ��� ��������, ���������� �� �����, ����� ���������� �������� �������� ������� ���������
// � ��������� ������� ������ (���� ���� �����, �� ������� �� 0)
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}


// �������� ������������� �������
// ��� ��������, ���������� �� �������, ����� ���������, ���� �� �� ����� � ������� vertexes
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