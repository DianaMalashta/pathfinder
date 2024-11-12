#include "pathfinder.h"

Graph *read_graph_from_file(const char *filename){
    char *file = mx_file_to_str(filename);
    if(!file) print_file_error(filename, "error: file ", " does not exist\n");
    if(mx_strlen(file) == 0){
        free(file);
        print_file_error(filename, "error: file ", " is empty\n");
    }
    char **lines = mx_strsplit(file, '\n');
    free(file);
    if(!lines[0]){
        lines++;
        mx_del_strarr(&lines);
        mx_print_error("error: line 1 is not valid\n");
    }
    if(!is_valid_lenght(lines[0])){
        mx_del_strarr(&lines);
        mx_print_error("error: line 1 is not valid\n");
    }
    int island_count = mx_atoi(lines[0]);
    if(island_count <= 0){
        free(file);
        mx_del_strarr(&lines);
        mx_print_error("error: line 1 is not valid\n");
    }

    Graph *graph = create_graph(island_count);
    int actual_lenght = 0;

    for(int i = 1; lines[i]; i++){
        char **islands = mx_strsplit(lines[i], '-');
        if(!islands[0] || !islands[1]){
            free_graph_parts(graph, islands, NULL, lines);
            print_line_error(i + 1);
        }
        char *island1 = islands[0];
        char **sub_parts = mx_strsplit(islands[1], ',');
        if(!sub_parts[0] || !sub_parts[1]){
            free_graph_parts(graph, islands, sub_parts, lines);
            print_line_error(i + 1);
        }
        char *island2 = sub_parts[0];
        char *lenght_str = sub_parts[1];
        if(!is_valid_island(island1) || !is_valid_island(island2) || !is_valid_lenght(lenght_str)){
            free_graph_parts(graph, islands, sub_parts, lines);
            print_line_error(i + 1);
        }
        
        int bridge_len = mx_atoi(lenght_str);
        if(bridge_len <= 0){
            free_graph_parts(graph, islands, sub_parts, lines);
            print_line_error(i + 1);
        }

        if((long)actual_lenght + bridge_len > INT_MAX){
            free_graph_parts(graph, islands, sub_parts, lines);
            mx_print_error("error: sum of bridges lengths is too big\n");
        }
        actual_lenght += bridge_len;
        int i1 = add_island(graph, island1);
        int i2 = add_island(graph, island2);
        if(graph->matrix[i1][i2] != INT_MAX){
            free_graph_parts(graph, islands, sub_parts, lines);
            mx_print_error("error: duplicate bridges\n");
        }
        
        add_bridge(graph, island1, island2, bridge_len);
        mx_del_strarr(&sub_parts);
        mx_del_strarr(&islands);
    }
    int diferent_islands = 0;
    for(int i = 0; i < graph->island_count; i++) if(graph->islands[i]) diferent_islands++;
    mx_del_strarr(&lines);
    if(diferent_islands != island_count){
        free_graph(graph);
        mx_print_error("error: invalid number of islands\n");
    }
    return graph;
}
