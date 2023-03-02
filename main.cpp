//-----------------------------------------------------------------------------//
//        ������: ��� ���� ���������� ������ ������������� ����� �����.        //
//        ����� ����� ��� ���� ��������� ����� ��� �����������.                //
//-----------------------------------------------------------------------------//

#include <windows.h>
#include <iostream>
#include "Graph.h"

int main()
{
    //��� ����������� �����/������ ��������� � �������
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    // ������ ������
    Graph g;

    // ��������� �������
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);

    // ��������� �����
    g.addEdge(0, 1, 1);//��� �������� ��� = 1 
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    // ������ ������
    for (auto i = 0; i < SIZE; i++) {
        std::string str = g.getName(g.getVertex(i));
        std::cout << str << "-> ";
    }
    std::cout << std::endl;

    // ����� ���� ��������� ������, �������� ������� ���� �����������
    g.findAllFriends();


    //----------------------------------------------------------------------------
    Graph g2;
    // ��������� �������
    g2.addVertex(0);
    g2.addVertex(1);
    g2.addVertex(2);
    g2.addVertex(3);
    g2.addVertex(4);

    // ��������� �����
    g2.addEdge(0, 1, 1);//��� �������� ��� = 1
    g2.addEdge(0, 2, 1);
    g2.addEdge(0, 3, 1);
    g2.addEdge(1, 2, 1);
    g2.addEdge(2, 3, 1);
    g2.addEdge(1, 4, 1);
    g2.addEdge(4, 3, 1);

    g2.findAllFriends();

    return 0;
}