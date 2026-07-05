// Name: Saad Azhar
// Roll No: 7993
// Q1 - First Come First Serve (FCFS) CPU Scheduling

#include <iostream>
using namespace std;

struct Process {
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
};

int main() {
    int total;
    cout << "How many processes? ";
    cin >> total;

    Process proc[total];

    for (int idx = 0; idx < total; idx++) {
        cout << "\nProcess " << (idx + 1) << " - arrival time: ";
        cin >> proc[idx].arrival;
        cout << "Process " << (idx + 1) << " - burst time: ";
        cin >> proc[idx].burst;
    }

    // arrange processes by arrival time before scheduling
    for (int a = 0; a < total - 1; a++) {
        for (int b = 0; b < total - a - 1; b++) {
            if (proc[b].arrival > proc[b + 1].arrival) {
                Process temp = proc[b];
                proc[b] = proc[b + 1];
                proc[b + 1] = temp;
            }
        }
    }

    int clock = 0;
    for (int idx = 0; idx < total; idx++) {
        if (clock < proc[idx].arrival)
            clock = proc[idx].arrival;
        clock += proc[idx].burst;
        proc[idx].completion = clock;
        proc[idx].turnaround = proc[idx].completion - proc[idx].arrival;
        proc[idx].waiting = proc[idx].turnaround - proc[idx].burst;
    }

    double waitSum = 0, turnSum = 0;

    cout << "\n\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int idx = 0; idx < total; idx++) {
        cout << (idx + 1) << "\t" << proc[idx].arrival << "\t" << proc[idx].burst
             << "\t" << proc[idx].completion << "\t\t" << proc[idx].turnaround
             << "\t\t" << proc[idx].waiting << "\n";
        waitSum += proc[idx].waiting;
        turnSum += proc[idx].turnaround;
    }

    cout << "\nAverage Waiting Time: " << (waitSum / total);
    cout << "\nAverage Turnaround Time: " << (turnSum / total) << endl;

    return 0;
}
