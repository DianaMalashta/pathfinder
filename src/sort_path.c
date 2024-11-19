#include "pathfinder.h"

void sort_paths(Island_info *info, int island_count){
    for (int i = 0; i < island_count; i++){
        if (info[i].pred_count > 1){
            for (int k = 0; k < info[i].pred_count - 1; k++){
                for (int l = k + 1; l < info[i].pred_count; l++){
                    if (info[i].predecessors[k] > info[i].predecessors[l]){
                        int temp = info[i].predecessors[k];
                        info[i].predecessors[k] = info[i].predecessors[l];
                        info[i].predecessors[l] = temp;
                    }
                }
            }
        }
    }
}
