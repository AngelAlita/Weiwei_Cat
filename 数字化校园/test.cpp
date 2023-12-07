#include "bits/stdc++.h"
#include "grlist.h"

using namespace  std;


template<typename Graphl>
Graphl* createGraph(FILE* fid){
    int numVertex, numEdge;
    fscanf(fid, "%d %d", &numVertex, &numEdge);
    Graphl* G = new Graphl(numVertex);
    int u, v, w;
    while (fscanf(fid, "%d %d %d", &u, &v, &w) == 3) {
        G->setEdge(u, v, w);
    }
    return G;
}


int main(int argc, char** argv)
{
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


    cout << G->weight(1,2)<< endl;

}




