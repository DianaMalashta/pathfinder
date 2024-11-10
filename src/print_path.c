#include "pathfinder.h"

void print_path(Graph *graph, Island_info *info, int start, int end){
    int fifo[graph->island_count];
    int top = 0;
    int now = end;
    while(now != -1){
        fifo[top] = now;
        top++;
        now = info[now].predecessor;
    }

    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(graph->islands[start]);
    mx_printstr(" -> ");
    mx_printstr(graph->islands[end]);
    mx_printstr("\nRoute: ");

    int suma = 0;
    for(int i = top - 1; i > 0; i--){
        mx_printstr(graph->islands[fifo[i]]);
        mx_printstr(" -> ");
        suma += graph->matrix[fifo[i]][fifo[i - 1]];
    }
    mx_printstr(graph->islands[fifo[0]]);
    mx_printstr("\nDistance: ");
    suma = 0;
    for(int i = top - 1; i > 0; i--){
        int distance = graph->matrix[fifo[i]][fifo[i - 1]];
        mx_printint(distance);
        suma += distance;
        if(i > 1) mx_printstr(" + ");
    }
    mx_printstr(" = ");
    mx_printint(suma);
    mx_printstr("\n========================================\n");
}
