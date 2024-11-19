#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <limits.h>

typedef struct{
    char **islands;
    int **matrix;
    int island_count;
} Graph;

typedef struct{
    int distance;         
    int *predecessors;    
    int pred_count;       
    bool visited;         
} Island_info;

typedef struct{
    char **path;
    char **route;
    int *distance;
    int total_dis;
    int route_count;
}  Result_path;

Graph *create_graph(int island_count);
Graph *read_graph_from_file(const char *filename);
Island_info *create_island_info(int island_count, int start);
Result_path *initialize_result_path(int max_paths, int max_islands);
void free_graph(Graph *graph);
void free_result_path(Result_path *result, int max_paths);
int add_island(Graph *graph, const char *name);
void add_bridge(Graph *graph, const char *island1, const char *island2, int length);
void dijkstra(Graph *graph, int start, Island_info *info);
void sort_paths(Island_info *info, int island_count);
void sort_result_paths(Graph *graph, Result_path *result_path, int count);
void recording_result(Graph *graph, Island_info *info, Result_path *result_path, int start, int end, int *path, int path_len, int *path_index);
void print_result_path(Result_path *result_path, int count);

//errors

void print_file_error(const char *filename, const char *str, const char *str2);
bool is_valid_island(const char *name);
bool is_valid_lenght(const char *lenght);
void print_line_error(int i);
void free_graph_parts(Graph *graph, char **arr1, char **arr2, char **arr3);
char **check_split_with_index(const char *s, char c, int *index);

#endif

