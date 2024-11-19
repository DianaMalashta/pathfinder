#include "pathfinder.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        mx_print_error("usage: ./pathfinder [filename]\n");
        return 1;
    }

    Graph *graph = read_graph_from_file(argv[1]);

    for(int i = 0; i < graph->island_count; i++){
        Island_info *info = create_island_info(graph->island_count, i);
        dijkstra(graph, i, info);

        for(int j = i + 1; j < graph->island_count; j++){
            int path[graph->island_count];
            int path_index = 0;

            Result_path *result_path = initialize_result_path(100, graph->island_count);
            recording_result(graph, info, result_path, i, j, path, 0, &path_index);
            sort_result_paths(graph, result_path, path_index);
            print_result_path(result_path, path_index);
            free_result_path(result_path, 100);
        }

        for (int j = 0; j < graph->island_count; j++) free(info[j].predecessors);
        free(info);
    }

    free_graph(graph);
    return 0;
}
