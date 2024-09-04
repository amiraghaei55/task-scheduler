#include "task_scheduler.h"
#include <stdio.h>
#include <time.h>

typedef struct {
    void (*task_function)(void);
    int interval_ms;
    int last_run_time;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void init_scheduler(void) {
    task_count = 0;
}

void register_task(void (*task_function)(void), int interval_ms) {
    if (task_count < MAX_TASKS) {
        tasks[task_count].task_function = task_function;
        tasks[task_count].interval_ms = interval_ms;
        tasks[task_count].last_run_time = clock();
        task_count++;
    } else {
        printf("Max task limit reached!\n");
    }
}

void run_scheduler(void) {
    clock_t current_time = clock();
    
    for (int i = 0; i < task_count; i++) {
        int time_since_last_run = (current_time - tasks[i].last_run_time) * 1000 / CLOCKS_PER_SEC;

        if (time_since_last_run >= tasks[i].interval_ms) {
            tasks[i].task_function();  // Execute the task
            tasks[i].last_run_time = current_time;  // Update the last run time
        }
    }
}
