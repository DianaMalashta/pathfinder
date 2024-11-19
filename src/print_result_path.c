#include "pathfinder.h"

void print_result_path(Result_path *result_path, int count){
    for(int i = 0; i < count; i++){
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(result_path[i].path[0]);
        mx_printstr(" -> ");
        mx_printstr(result_path[i].path[1]);
        mx_printstr("\nRoute: ");
        for(int j = 0; j < result_path[i].route_count; j++){
            mx_printstr(result_path[i].route[j]);
            if(j < result_path[i].route_count - 1) mx_printstr(" -> ");
        }
        mx_printstr("\nDistance: ");
        for(int j = 0; j < result_path[i].route_count - 1; j++){
            mx_printint(result_path[i].distance[j]);
            if(j < result_path[i].route_count - 2) mx_printstr(" + ");
        }
        if(result_path[i].route_count > 2){
            mx_printstr(" = ");
            mx_printint(result_path[i].total_dis);
        }
        mx_printstr("\n========================================\n");
    }
}

