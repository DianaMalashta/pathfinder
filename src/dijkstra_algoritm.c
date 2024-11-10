#include "pathfinder.h"

void dijkstra(Graph *graph, int start, Island_info *info){
    info[start].distance = 0;
    for(int i = 0; i < graph->island_count - 1; i++){
        int min_distance = INT_MAX;
        int min_index = -1;
        for(int j = 0; j < graph->island_count; j++){
            if(!info[j].visited && info[j].distance < min_distance){
                min_distance = info[j].distance;
                min_index = j;
            }
        }
        if(min_index == -1) break;
        info[min_index].visited = true;

        for(int j = 1; j < graph->island_count - 1; j++){
            int edge = graph->matrix[min_index][j];
            if(edge != INT_MAX && !info[j].visited){
                int new = info[min_index].distance + edge;
                if(new < info[j].distance){
                    info[j].distance = new;
                    info[j].predecessor = min_index;
                }
            }
        }
    }
}
