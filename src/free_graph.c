#include "pathfinder.h"

void free_graph(Graph *graph){
    if(!graph) return;
    for(int i = 0; i < graph->island_count; i++) free(graph->islands[i]);
    free(graph->islands);
    for(int i = 0; i < graph->island_count; i++) free(graph->matrix[i]);
    free(graph->matrix);
    free(graph);
}

void free_graph_parts(Graph *graph, char **arr1, char **arr2, char **arr3){
    free_graph(graph);
    if(arr1) mx_del_strarr(&arr1);
    if(arr2) mx_del_strarr(&arr2);
    if(arr3) mx_del_strarr(&arr3);
}
