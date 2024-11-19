#include "pathfinder.h"

void recording_result(Graph *graph, Island_info *info, Result_path *result_path, int start, int end, int *path, int path_len, int *path_index){
    path[path_len++] = end;

    if(end == start){
        int index = (*path_index)++;
        result_path[index].path[0] = graph->islands[start];
        result_path[index].path[1] = graph->islands[path[0]];
        for(int i = path_len - 1; i >= 0; i--){
            result_path[index].route[path_len - 1 - i] = graph->islands[path[i]];
        }

        int total_distance = 0;
        for(int i = path_len - 1; i > 0; i--){
            int dist = graph->matrix[path[i]][path[i - 1]];
            result_path[index].distance[path_len - 1 - i] = dist;
            total_distance += dist;
        }
        result_path[index].total_dis = total_distance;
        result_path[index].route_count = path_len;
        return;
    }

    for(int i = 0; i < info[end].pred_count; i++){
        recording_result(graph, info, result_path, start, info[end].predecessors[i], path, path_len, path_index);
    }
}
