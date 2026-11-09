# CPU Scheduling Algorithms in C

A collection of CPU scheduling algorithms implemented in C as part of my OS practice.

## Algorithms Implemented

- **FCFS** – First Come, First Serve
- **SJF** – Shortest Job First (Non-Preemptive)
- **SRTF** – Shortest Remaining Time First (Preemptive SJF)
- **Round Robin** – Time Quantum based scheduling
- **Priority Scheduling** – Non-Preemptive

## Features

- Takes arrival time and burst time as input
- Calculates Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT)
- Displays average waiting and turnaround times
- Prints a Gantt chart to show process execution
- Handles CPU idle time

## How to Run

Make sure you have GCC installed.

```bash
gcc fcfs.c -o fcfs
./fcfs
```

Replace `FCFS.c` with whichever algorithm you want to run.

## Notes

These implementations use simple logic and are mainly intended for learning and practicing OS concepts.

For priority scheduling, a lower priority number represents a higher priority.
