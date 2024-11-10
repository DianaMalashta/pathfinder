#include "pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_print_error("usage: ./pathfinder [filename]\n");
        return 1;
    }

    Graph *graph = read_graph_from_file(argv[1]);
    if (!graph) {
        mx_print_error("Error: unable to create graph\n");
        return 1;
    }

    mx_printstr("Islands:\n");
    for (int i = 0; i < graph->island_count; i++) {
        if (graph->islands[i]) {
            mx_printstr("  ");
            mx_printint(i);
            mx_printstr(" ");
            mx_printstr(graph->islands[i]);
            mx_printchar('\n');
        }
    }

    mx_printstr("\nBridges (adjacency matrix):\n");
    for (int i = 0; i < graph->island_count; i++) {
        for (int j = 0; j < graph->island_count; j++) {
            if (graph->matrix[i][j] == INT_MAX) {
                mx_printstr("  ∞ ");
            } else {
                mx_printint(graph->matrix[i][j]);
                mx_printstr(" ");
            }
        }
        mx_printchar('\n');
    }

    for(int i = 0; i < graph->island_count; i++){
        Island_info *info = create_island_info(graph->island_count, i);
        dijkstra(graph, i, info);
        for(int j = i + 1; j < graph->island_count; j++){
            print_path(graph, info, i, j);
        }
        free(info);
    }
    free_graph(graph);
    return 0;
}
