// Name: Saad Azhar
// Roll No: 7993
// Q2 - Shortest Job First (Non-Preemptive) CPU Scheduling

#include <iostream>
using namespace std;

int main() {
    int total;
    cout << "How many processes? ";
    cin >> total;

    int burstTime[total];
    int waitingTime[total];
    int turnaroundTime[total];
    bool finished[total];
    int sequence[total];

    for (int idx = 0; idx < total; idx++) {
        cout << "Burst time for process " << (idx + 1) << ": ";
        cin >> burstTime[idx];
        finished[idx] = false;
    }

    int clock = 0, count = 0;

    while (count < total) {
        int pick = -1;
        for (int idx = 0; idx < total; idx++) {
            if (!finished[idx]) {
                if (pick == -1 || burstTime[idx] < burstTime[pick])
                    pick = idx;
            }
        }

        waitingTime[pick] = clock;
        clock += burstTime[pick];
        turnaroundTime[pick] = clock;
        finished[pick] = true;
        sequence[count] = pick;
        count++;
    }

    cout << "\nOrder of execution: ";
    for (int idx = 0; idx < total; idx++)
        cout << "P" << (sequence[idx] + 1) << " ";

    double waitSum = 0, turnSum = 0;
    cout << "\n\nPID\tBurst\tWaiting\tTurnaround\n";
    for (int idx = 0; idx < total; idx++) {
        cout << (idx + 1) << "\t" << burstTime[idx] << "\t"
             << waitingTime[idx] << "\t" << turnaroundTime[idx] << "\n";
        waitSum += waitingTime[idx];
        turnSum += turnaroundTime[idx];
    }

    cout << "\nAverage Waiting Time: " << (waitSum / total);
    cout << "\nAverage Turnaround Time: " << (turnSum / total) << endl;

    return 0;
}
