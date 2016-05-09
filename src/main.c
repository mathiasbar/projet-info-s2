#include <errno.h>

#include "graph.h"

#define GRAPH_1 "resources/graphe1.csv"
#define GRAPH_3 "resources/graphe3.csv"
#define METRO "resources/metro.csv"


int main(int argc, char const *argv[]) {

    Node_t *firstNodeInGraph = NULL;
    Node_t *graphImported = NULL;

    FILE *grapheCsv = fopen(GRAPH_1, "r");

    if(grapheCsv == NULL)
    {
        printf("Can't open the file:%s errno: %s\n", GRAPH_1, strerror(errno));
        exit(1);
    }

    graphImported = convertCsvToGraph(grapheCsv);

    addNode(&firstNodeInGraph, 5);
        addNewArc(firstNodeInGraph, 2, 5);
    addNode(&firstNodeInGraph, 3);
    addNode(&firstNodeInGraph, 4);
        addNewArc(firstNodeInGraph, 5, 8);
        addNewArc(firstNodeInGraph, 6, -2);
    displayGraph(firstNodeInGraph);
    return 0;
}
