#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <limits.h>

typedef struct{
    char **islands;
    int **matrix;
    int island_count;
} Graph;

typedef struct {
    int distance;         
    int *predecessors;    
    int pred_count;       
    bool visited;         
} Island_info;


Graph *read_graph_from_file(const char *filename);
Graph *create_graph(int island_count);
Island_info *create_island_info(int island_count, int start);
void free_graph(Graph *graph);
int add_island(Graph *graph, const char *name);
void add_bridge(Graph *graph, const char *island1, const char *island2, int length);
void dijkstra(Graph *graph, int start, Island_info *info);
void print_all_paths(Graph *graph, Island_info *info, int start, int end, int *path, int path_len);

//errors

void print_file_error(const char *filename, const char *str, const char *str2);
bool is_valid_island(const char *name);
bool is_valid_lenght(const char *lenght);
void print_line_error(int i);
void free_graph_parts(Graph *graph, char **arr1, char **arr2, char **arr3);

#endif

