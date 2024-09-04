#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#define MAX_TASKS 10  // Maximum number of tasks

// Function prototypes
void init_scheduler(void);
void register_task(void (*task_function)(void), int interval_ms);
void run_scheduler(void);

#endif // TASK_SCHEDULER_H
