#include "pathfinder.h"

Graph *create_graph(int island_count){
    Graph *graph = malloc(sizeof(Graph));
    graph->island_count = island_count;
    graph->islands = malloc(sizeof(char *) * island_count);
    for(int i = 0; i < island_count; i++){
        graph->islands[i] = NULL;
    }

    graph->matrix = malloc(sizeof(int *) * island_count);
    for(int i = 0; i < island_count; i++){
        graph->matrix[i] = malloc(sizeof(int) * island_count);
        for(int j = 0; j < island_count; j++){
            graph->matrix[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    return graph;
}
