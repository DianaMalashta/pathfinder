#include "pathfinder.h"

int add_island(Graph *graph, const char *name){
    for(int i = 0; i < graph->island_count; i++){
        if(graph->islands[i] && mx_strcmp(graph->islands[i], name) == 0) return i;
    }

    for(int i = 0; i < graph->island_count; i++){
        if(!graph->islands[i]){
            graph->islands[i] = mx_strdup(name);
            return i;
        }
    }
    return -1;
}

void add_bridge(Graph *graph, const char *island1, const char *island2, int length){
    int i = add_island(graph, island1);
    int j = add_island(graph, island2);
    graph->matrix[i][j] = length;
    graph->matrix[j][i] = length;
}
