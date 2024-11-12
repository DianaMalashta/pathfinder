#include "pathfinder.h"

void print_all_paths(Graph *graph, Island_info *info, int start, int end, int *path, int path_len){
    path[path_len++] = end;
    if(end == start){
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(graph->islands[start]);
        mx_printstr(" -> ");
        mx_printstr(graph->islands[path[0]]);
        mx_printstr("\nRoute: ");

        for(int i = path_len - 1; i >= 0; i--){
            mx_printstr(graph->islands[path[i]]);
            if(i > 0) mx_printstr(" -> ");
        }

        mx_printstr("\nDistance: ");
        int total_distance = 0;
        for(int i = path_len - 1; i > 0; i--){
            int dist = graph->matrix[path[i]][path[i - 1]];
            mx_printint(dist);
            total_distance += dist;
            if(i > 1) mx_printstr(" + ");
        }
        if(path_len > 2)mx_printstr(" = ");
        if(path_len > 2)mx_printint(total_distance);
        mx_printstr("\n========================================\n");
        return;
    }

    for(int i = info[end].pred_count - 1; i >= 0 ; i--){
        print_all_paths(graph, info, start, info[end].predecessors[i], path, path_len);
    }
}

