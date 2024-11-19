#include "pathfinder.h"

int island_index(Graph *graph, const char *island){
    for(int i = 0; i < graph->island_count; i++){
        if(mx_strcmp(graph->islands[i], island) == 0) return i;
    }
    return -1;
}

void sort_result_paths(Graph *graph, Result_path *result_path, int count){
    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            if(mx_strcmp(result_path[i].path[0], result_path[j].path[0]) == 0 &&
                mx_strcmp(result_path[i].path[1], result_path[j].path[1]) == 0 &&
                result_path[i].total_dis == result_path[j].total_dis){
                int k = 0;
                while(k < result_path[i].route_count && k < result_path[j].route_count){
                    int idx_i = island_index(graph, result_path[i].route[k]);
                    int idx_j = island_index(graph, result_path[j].route[k]);
                    if(idx_i > idx_j){
                        Result_path temp = result_path[i];
                        result_path[i] = result_path[j];
                        result_path[j] = temp;
                        break;
                    } else if(idx_i < idx_j) break;
                    k++;
                }
            }
        }
    }
}
