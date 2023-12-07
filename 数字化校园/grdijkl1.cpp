// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for Dijkstra's single-source shortest paths algorithm
// Version 1: Use a simple scan of the distance matrix to find the next
// closest node.
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency List representation

#include "book.h"
#include <fstream>
#include "grlist.h"
#include <iostream>
#include<cstdio>
#include <fstream>
#include <sstream>
#include <string>

int minVertex(Graph*, int*);

// Compute shortest path distances from "s".
// Return these distances in "D".
void Dijkstra(Graph* G, int* D, int s) {
  int i, v, w;
  for (i=0; i<G->n(); i++) {      // Process the vertices
    v = minVertex(G, D);
    if (D[v] == INFINITY) return; // Unreachable vertices
    G->setMark(v, VISITED);
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
      if (D[w] > (D[v] + G->weight(v, w)))
        D[w] = D[v] + G->weight(v, w);
  }
}

int minVertex(Graph* G, int* D) { // Find min cost vertex
  int i, v = -1;
  // Initialize v to some unvisited vertex
  for (i=0; i<G->n(); i++)
    if (G->getMark(i) == UNVISITED) { v = i; break; }
  for (i++; i<G->n(); i++)  // Now find smallest D value
    if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
      v = i;
  return v;
}

Graphl createGraph(FILE *fid){
    char line[100];
    while (fgets(line, 100, fid) != NULL) { // 逐行读取文件
        char* token;
        char* rest = line;
        char* tokens[100]; // 存储当前行的所有单词
        int i = 0;
        while ((token = strtok(rest, " ")) != NULL) { // 将当前行按空格分割成单词
            tokens[i++] = token;
        }
        // 处理当前行的单词
        for (int j = 0; j < i; j++) {
            printf("%s ", tokens[j]);
        }
        printf("\n");
    }


}

// Test Dijkstra's algorithm:
// Version for Adjancency List representation
int main(int argc, char** argv) {
  Graph* G;
  FILE *fid;

  if (argc != 2) {
    cout << "Usage: grdijkl1 <file>\n";
    exit(-1);
  }

  if ((fid = fopen(argv[1], "rt")) == NULL) {
    cout << "Unable to open file |" << argv[1] << "|\n";
    exit(-1);
  }

  G = createGraph<Graphl>(fid);
  if (G == NULL) {
    cout << "Unable to create graph\n";
    exit(-1);
  }

  int D[G->n()];
  for (int i=0; i<G->n(); i++)     // Initialize
    D[i] = INFINITY;
  D[0] = 0;

  Dijkstra(G, D, 0);

  for(int k=0; k<G->n(); k++)
    cout << D[k] << " ";
  cout << endl;
  return 0;
}
