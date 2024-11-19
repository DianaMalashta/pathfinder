#include "pathfinder.h"

void free_result_path(Result_path *result, int max_paths){
    for (int i = 0; i < max_paths; i++){
        free(result[i].path);
        free(result[i].route);
        free(result[i].distance);
    }
    free(result);
}
