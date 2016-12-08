#ifndef MGRAPH_H
#define MGRAPH_H


#include "list.h"

class MGraph
{

public:
    static const int MAX_VERTEX_NUM = 16;
    static const int INFINITY = 0x7FFFFFFF;

    MGraph();
    void Init();

    void Floyd();
    void PrintShortestDistance();


private:
    char vexs[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
    List p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int d[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
};


#endif // MGRAPH_H
