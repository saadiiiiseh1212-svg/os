// Name: Saad Azhar
// Roll No: 7993
// Q3 - Priority Scheduling (Non-Preemptive) CPU Scheduling

#include <iostream>
using namespace std;

struct Job {
    int id;
    int burst;
    int priority;
    int waiting;
    int turnaround;
};

int main() {
    int total;
    cout << "How many processes? ";
    cin >> total;

    Job job[total];

    for (int idx = 0; idx < total; idx++) {
        job[idx].id = idx + 1;
        cout << "Burst time for process " << job[idx].id << ": ";
        cin >> job[idx].burst;
        cout << "Priority for process " << job[idx].id << " (lower value = higher priority): ";
        cin >> job[idx].priority;
    }

    // arrange jobs by priority value, smallest first
    for (int a = 0; a < total - 1; a++) {
        for (int b = 0; b < total - a - 1; b++) {
            if (job[b].priority > job[b + 1].priority) {
                Job temp = job[b];
                job[b] = job[b + 1];
                job[b + 1] = temp;
            }
        }
    }

    job[0].waiting = 0;
    job[0].turnaround = job[0].burst;

    for (int idx = 1; idx < total; idx++) {
        job[idx].waiting = job[idx - 1].waiting + job[idx - 1].burst;
        job[idx].turnaround = job[idx].waiting + job[idx].burst;
    }

    double waitSum = 0, turnSum = 0;

    cout << "\nPID\tBurst\tPriority\tWaiting\tTurnaround\n";
    for (int idx = 0; idx < total; idx++) {
        cout << job[idx].id << "\t" << job[idx].burst << "\t" << job[idx].priority
             << "\t\t" << job[idx].waiting << "\t" << job[idx].turnaround << "\n";
        waitSum += job[idx].waiting;
        turnSum += job[idx].turnaround;
    }

    cout << "\nAverage Waiting Time: " << (waitSum / total);
    cout << "\nAverage Turnaround Time: " << (turnSum / total) << endl;

    return 0;
}
