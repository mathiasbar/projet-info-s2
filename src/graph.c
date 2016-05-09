#include "graph.h"

void addNode (Node_t **_node, int _id)
{
    Node_t *newest = malloc(sizeof(Node_t));

    if (newest == NULL)
    {
        //fail in allocation
        printf("memory problem during an addNode operation\n");
        exit(1);
    }

    newest->id = _id;
    newest->next = *_node;
    *_node = newest;
}


void addNewArc(Node_t *_node, unsigned int _id, int _weight)
{
    Arc_t *newest = malloc(sizeof(Arc_t));

    if (newest == NULL)
    {
        //fail in allocation
        printf("memory problem during an addNewArc operation\n");
        exit(1);
    }

    newest->weight = _weight;
    newest->id = _id;
    newest->next = _node->firstArc;
    _node->firstArc = newest;
}


void destroyGraph(Node_t *_node)
{
    Node_t *currentNode;

    while ((currentNode = _node) != NULL)
    {
        _node = _node->next;
        destroyNode(currentNode);
    }
}


void destroyNode(Node_t *_node)
{
    destroyArcs(_node->firstArc);
    free(_node);
}


void destroyArcs(Arc_t *_arc)
{
    Arc_t *currentArc;

    while ((currentArc = _arc) != NULL)
    {
        _arc = _arc->next;
        free(currentArc);
    }
}

Node_t* convertCsvToGraph(FILE *csvFile)
{
    Node_t *first = malloc(sizeof(Node_t));
    int nbOfNodes = 0;
    int nbOfArcs = 0;

    int id;
    int node;
    double weight;
    float lattitude;
    float longitude;
    char nameLine[20];
    char nameStop[3];

    if (csvFile == NULL)
    {
        printf("The file doesn't exist or is not open\n");
        exit(1);
    }
    fscanf(csvFile, "%d %d\n", &nbOfNodes, &nbOfArcs);

    for (int i = 0; i < nbOfNodes; i++)
    {
        fscanf(csvFile, "%d %f %f %s %s\n", &id, &lattitude, &longitude, nameLine, nameStop);
        printf("%d %f %f %s %s\n", id, lattitude, longitude, nameLine, nameStop);
    }

    for (int j = 0; j < nbOfArcs; j++)
    {
        fscanf(csvFile, "%d %d %lf\n", &node, &id, &weight);
        printf("%d %d %lf\n", node, id, weight);
    }

    return first;
}

void displayGraph(Node_t *_rootGraphNode)
{
    while (_rootGraphNode != NULL) {
        printf ("Node %d has:\n", _rootGraphNode->id);

        Arc_t *currentArc = _rootGraphNode->firstArc;
        if (currentArc == NULL) {
            printf ("\tNo Arc\n");
        } else {
            while (currentArc != NULL) {
                printf ("\tArc to node %d", currentArc->id);
                printf ("\twith a weight of %d\n", currentArc->weight);
                currentArc = currentArc->next;
            }
        }
        _rootGraphNode = _rootGraphNode->next;
    }
}
