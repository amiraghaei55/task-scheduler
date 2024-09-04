#include <stdio.h>
#include <time.h>
#include "task_scheduler.h"
#include "tasks.h"

// Function to simulate delay (simulating time passing in the embedded system)
void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000);
}

int main(void) {
    // Initialize task scheduler
    init_scheduler();

    // Register tasks with the scheduler
    register_task(blink_led_task, 1000);  // Run every 1000 ms (1 second)
    register_task(read_sensor_task, 5000); // Run every 5000 ms (5 seconds)
    register_task(log_data_task, 10000);   // Run every 10,000 ms (10 seconds)

    while (1) {
        // Run the scheduler (check and execute tasks)
        run_scheduler();

        // Simulate a system tick (typically in real embedded systems this would be driven by a hardware timer)
        delay(100);  // Simulate 100 ms delay (system tick of 100 ms)
    }

    return 0;
}
