# CPU Scheduling Algorithms — Assignment 1

Implementation of classic CPU scheduling algorithms in C++.

**Submitted by:** Saad Azhar
**Roll No:** 7993

## Files

| File | Description |
|---|---|
| `Q1_FCFS.cpp` | First Come First Serve scheduling — calculates Completion Time, Turnaround Time, Waiting Time, and Average Waiting Time |
| `Q2_SJF.cpp` | Shortest Job First (non-preemptive) — displays execution order and average waiting time |
| `Q3_Priority.cpp` | Priority Scheduling (non-preemptive) — lower number means higher priority |
| `Q4_RoundRobin.cpp` | Round Robin scheduling with user-defined time quantum |
| `Q5_Comparison.cpp` | Runs the same process set through FCFS, SJF, and Priority scheduling and reports the best-performing algorithm by average waiting time |

## How to compile and run

```bash
g++ Q1_FCFS.cpp -o Q1_FCFS
./Q1_FCFS
```

Repeat the same pattern for each file, replacing the filename.

## Sample input (3 processes)

```
Number of processes: 3
Arrival times: 0 1 2
Burst times: 5 3 8
```
