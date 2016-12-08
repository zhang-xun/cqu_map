#include <iostream>
#include "MGraph.h"



MGraph::MGraph()
{
    vexnum = arcnum = 0;

    for (int i=0; i!=MAX_VERTEX_NUM; i++)
        for (int j=0; j!=MAX_VERTEX_NUM; j++)
            arcs[i][j] = 0;


}

void MGraph::Init()
{
    for (int i=0; i!=15; i++)
        vexs[i] = 'a' + i;

    arcs[1-1][2-1] = 192;
    arcs[1-1][4-1] = 212;
    arcs[1-1][5-1] = 290;

    arcs[2-1][3-1] = 200;

    arcs[3-1][4-1] = 178;
    arcs[3-1][14-1] = 230;
    arcs[3-1][15-1] = 245;

    arcs[4-1][5-1] = 240;
    arcs[4-1][13-1] = 285;
    arcs[4-1][14-1] = 360;

    arcs[5-1][6-1] = 225;
    arcs[5-1][7-1] = 210;

    arcs[6-1][7-1] = 200;
    arcs[6-1][8-1] = 370;

    arcs[7-1][9-1] = 140;
    arcs[7-1][12-1] = 180;
    arcs[7-1][13-1] = 235;

    arcs[8-1][9-1] = 270;
    arcs[8-1][11-1] = 400;

    arcs[9-1][10-1] = 150;

    arcs[10-1][11-1] = 180;
    arcs[10-1][12-1] = 200;

    arcs[12-1][13-1] = 240;

    arcs[13-1][14-1] = 230;

     arcs[14-1][15-1] = 140;

    for (int i=0; i!=MAX_VERTEX_NUM; i++)
    {
        for (int j=0; j!=MAX_VERTEX_NUM; j++)
            std::cout << arcs[i][j]<< "\t";
        std::cout << std::endl;
    }
    vexnum = 15;
    arcnum = 25;
}

void MGraph::Floyd()
{
    for (int v=0; v!=vexnum; v++)
        for (int w=0; w!=vexnum; w++) {
            if (arcs[v][w])
                d[v][w] = arcs[v][w];
            else
                d[v][w] = INFINITY;
            if (d[v][w]) {
                p[v][w].Add(v);
                p[v][w].Add(w);
            }
        }
    for (int u=0; u!=vexnum; u++)
        for (int v=0; v!=vexnum; v++)
            for (int w=0; w!=vexnum; w++)
                if (d[v][u]!=INFINITY && d[u][w]!=INFINITY && d[v][u]+d[u][w]<d[v][w]) {
                    d[v][w] = d[v][u] + d[u][w];
                    p[v][w].Link(p[v][u], p[u][w]);
                }
}

void MGraph::PrintShortestDistance()
{


    for (int i=0; i!=vexnum; i++)
        for (int j=0; j!=vexnum; j++) {
            if (i!=j) {
                std::cout << "Path  " << i+1 << "  To  " << j+1 << "\t";
                if (d[i][j] != INFINITY) {
                    std::cout << "Length   " << d[i][j] << "   ,路径如下:";
                    p[i][j].InitTrans();
                    int vex;
                    std::cout << i+1;
                    while ((vex = p[i][j].GetNextVertex()) != -1)
                        std::cout << " -> "<< vex+1 ;
                    std::cout << std::endl;
                }
                else
                   std::cout << "INFINITY" << std::endl;
            }
        }
}
