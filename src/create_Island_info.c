#include "pathfinder.h"

Island_info *create_island_info(int island_count, int start){
    Island_info *info = malloc(sizeof(Island_info) * island_count);
    for(int i = 0; i < island_count; i++){
        info[i].distance = INT_MAX;
        info[i].predecessors = malloc(sizeof(int) * island_count);
        info[i].pred_count = -1;
        info[i].visited = false;
    }
    info[start].distance = 0;
    return info;
}
