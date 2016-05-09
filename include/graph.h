#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Arc {
    unsigned int id;
    int weight;
    struct Arc *next;
} Arc_t;


typedef struct Node {
    int id;
    Arc_t *firstArc;
    struct Node *next;
    double lattitude;
    double longitude;
    char nomLigneDeMetro;
    char nomDuNoeud;
} Node_t;

/**
* Add a neighbour node in the Neighbors list of a node
*/
extern void addNewArc(Node_t *_node, unsigned int _id, int weight);

/*
* Destroy all the nodes in graph
*/
extern void destroyGraph(Node_t *_node);

/**
* Import a graph in a csv file
*/
extern Node_t* convertCsvToGraph(FILE *file);

/*
* Destroy a node
*/
extern void destroyNode(Node_t *_node);
/*
* Destroy a list of arcs
*/
extern void destroyArcs(Arc_t *_arc);



/*
* Add a new node in the graph
*/
extern void addNode(Node_t **_node, int _id);

/**
* Display the nodes in the graph with their neighbors
*/
extern void displayGraph(Node_t *_rootGraphNode);

#endif
