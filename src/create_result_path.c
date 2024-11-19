#include "pathfinder.h"

Result_path *initialize_result_path(int max_paths, int max_islands){
    Result_path *result = malloc(sizeof(Result_path) * max_paths);

    for (int i = 0; i < max_paths; i++){
        result[i].path = malloc(sizeof(char *) * 2);
        result[i].route = malloc(sizeof(char *) * max_islands);
        result[i].distance = malloc(sizeof(int) * (max_islands - 1));
        result[i].total_dis = 0;
        result[i].route_count = 0;
    }

    return result;
}
