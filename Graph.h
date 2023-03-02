//--------------------------------------------------------------------------------------//
//  ������ �������� ������������������, ����������� ����� � ������� ������� ���������   //
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
    
    void addVertex(int vnumber);                // ���������� �������
    void addEdge(int v1, int v2, int weight);   // ���������� �����   
    bool edgeExists(int v1, int v2);            // ���������� �� �������� ������� 
    bool vertexExists(int v);

    int getVertex(int pos);
    std::string getName(int pos);

    void findAllFriends();  // ����� ���� ��������� ������, �������� ������� ���� �����������


private:
    int matrix[SIZE][SIZE]; // ������� ���������
    int vertexes[SIZE];     // ��������� ������
    int vertexCount;        // ���������� ����������� ������
    std::string names[SIZE] = { "����", "������", "�����", "����", "����" };;// ������ ���� �����
};