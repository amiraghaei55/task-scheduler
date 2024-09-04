# Real-Time Task Scheduler Simulation

This project simulates a real-time task scheduler for embedded systems. It uses a basic round-robin scheduling mechanism to execute multiple tasks at different intervals. Tasks are simulated as functions (such as blinking an LED, reading sensor data, and logging data) that run periodically based on their scheduling interval.

### Features
- **Round-robin task scheduling**: Tasks are executed at specified time intervals.
- **Simulated time-based tasks**: Tasks like LED blinking, sensor reading, and data logging are simulated with print statements.
- **Modular design**: Tasks are modular, and more tasks can be added easily.

### Project Structure
- **main.c**: Main loop and task scheduling control.
- **task_scheduler.h / task_scheduler.c**: Scheduler implementation to manage and execute tasks.
- **tasks.h / tasks.c**: Simulated tasks like LED blinking, sensor reading, and data logging.

### How to Compile
You can compile the project using `gcc`:
```bash
gcc main.c task_scheduler.c tasks.c -o task_scheduler
