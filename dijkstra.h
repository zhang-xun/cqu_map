#ifndef DIJKSTRA
#define DIJKSTRA

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

#define INFINITY_D 10000
#define TRUE 1
#define FALSE 0
#define VERTEX_NUM 15



typedef struct graph
{
    std::string vexs[VERTEX_NUM];  /*顶点*/
    int arcs[VERTEX_NUM][VERTEX_NUM];   /*邻接矩阵*/
    int vex_num;     /*顶点数*/
    int arc_num;     /*弧数*/
}Graph;


inline void ShortestPath(Graph g,int v0,int p[][VERTEX_NUM],int d[])
{
/*迪杰斯特拉算法求最短路径，g为图的邻接矩阵，v0为起始顶点，
p[v][w]储存v0到v路径上w的后继顶点(无后继置-1)，d[v]为路径v0到v的带权长度*/

    int v;
    int w;
    int min;
    int i,j;
    int final[VERTEX_NUM];  /*final[v]=TRUE当且仅当v属于S*/

    /*初始化数组*/
    for (v = 0; v < g.vex_num; v++)
    {
        final[v] = FALSE;
        d[v] = g.arcs[v0][v];
        for (w = 0; w < g.vex_num; w++)
        {
            p[v][w] = -1;


        }
        if (d[v] < INFINITY_D)
        {
            p[v][0] = v0;
            p[v][1] = v;
        }
    }
    /*初始化，顶点v0属于S集合*/
    d[v0] = 0;
    final[v0] = TRUE;
    /*循环n-1次求最短路径*/
    for (i = 1; i < g.vex_num; i++)
    {
        min=INFINITY_D;
        for (w = 0; w<g.vex_num; w++)
        {
            if (!final[w])  /* w属于V-S */
            {
                if (d[w] < min)
                {
                    /* w顶点离v0更近 */
                    v=w;
                    min=d[w];
                 }
             }
        }
        final[v] = TRUE;    /*离v0顶点最近的v加入S集*/
        for (w = 0; w<g.vex_num; w++)    /*更新当前最短路径及距离*/
        {
            if (!final[w] && (min+g.arcs[v][w] < d[w]) )
            {
                                           /*修改d[w]和p[w] (w属于V-S) */
                d[w] = min + g.arcs[v][w];
                for (j = 0; p[v][j]> -1 && j < VERTEX_NUM; j++)
                {
                    p[w][j] = p[v][j];  /* p[w]=p[v] */
                 }
                p[w][j] = w;        /* p[w]=p[v]+w */
             }
        }
    }
}




inline std::vector<std::string> init(int start, int end)
{
    std::vector<std::string> result;
    int i, j;
    Graph g;
    int p[VERTEX_NUM][VERTEX_NUM];
    int d[VERTEX_NUM];
    int v0;


    /*初始化图g*/
    g.vexs[0]="1";
    g.vexs[1]="2";
    g.vexs[2]="3";
    g.vexs[3]="4";
    g.vexs[4]="5";
    g.vexs[5]="6";
    g.vexs[6]="7";
    g.vexs[7]="8";
    g.vexs[8]="9";
    g.vexs[9]="10";
    g.vexs[10]="11";
    g.vexs[11]="12";
    g.vexs[12]="13";
    g.vexs[13]="14";
    g.vexs[14]="15";



    for(i=0;i<VERTEX_NUM;i++)
        for(j=0;j<VERTEX_NUM;j++)
            g.arcs[i][j]=INFINITY_D;

    g.arcs[1-1][2-1] = 192;
    g.arcs[1-1][4-1] = 212;
    g.arcs[1-1][5-1] = 290;

    g.arcs[2-1][3-1] = 200;

    g.arcs[3-1][4-1] = 178;
    g.arcs[3-1][14-1] = 230;
    g.arcs[3-1][15-1] = 245;

    g.arcs[4-1][5-1] = 240;
    g.arcs[4-1][13-1] = 285;
    g.arcs[4-1][14-1] = 360;

    g.arcs[5-1][6-1] = 225;
    g.arcs[5-1][7-1] = 210;

    g.arcs[6-1][7-1] = 200;
    g.arcs[6-1][8-1] = 370;

    g.arcs[7-1][9-1] = 140;
    g.arcs[7-1][12-1] = 180;
    g.arcs[7-1][13-1] = 235;

    g.arcs[8-1][9-1] = 270;
    g.arcs[8-1][11-1] = 400;

    g.arcs[9-1][10-1] = 150;

    g.arcs[10-1][11-1] = 180;
    g.arcs[10-1][12-1] = 200;

    g.arcs[12-1][13-1] = 240;

    g.arcs[13-1][14-1] = 230;

     g.arcs[14-1][15-1] = 140;



    g.vex_num=VERTEX_NUM;
    g.arc_num=25;

    /*输出图的有关信息*/
    for(i=0;i<VERTEX_NUM;i++)
    {
        //printf("%c\t",g.vexs[i]);
        std::cout << g.vexs[i] << "\t" ;
        for(j=0;j<VERTEX_NUM;j++)
        {
            //printf("%5d ",g.arcs[i][j]);
            std::cout << g.arcs[i][j] << "\t" ;
        }
        printf("\n");
    }
    printf("\n");

    /*求最短路径*/
    v0 = start-1;                   //logic 1-15  actual 0-14
    ShortestPath(g,v0,p,d);

    /*输出最短路径*/
    for (i = 0; i < g.vex_num; i++)
    {
        if(i == end-1)              //logic 1-15  actual 0-14
        {
        //printf("Path %c to %c:\n",g.vexs[v0],g.vexs[i]);
        std::cout << "path " << g.vexs[v0] << "to " << g.vexs[i]  << ":";
        if ( p[i][v0] != -1 )   /*存在路径则输出*/
        {
            for (j = 0; p[i][j]!=-1; j++)
            {
                if (j != 0)
                    printf("→");
                //printf("  %c",g.vexs[p[i][j]]);
                std::cout << g.vexs[p[i][j]] ;
                result.push_back(g.vexs[p[i][j]]);
            }
            printf("\n");
        }
        printf("Length:%d\n",d[i]);
        printf("\n");
        }
    }

    for(int i = 0; i< result.size(); i++)
        std::cout << "result" << result[i] << std::endl;

    return result;
}



#endif // DIJKSTRA

