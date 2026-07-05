// Name: Saad Azhar
// Roll No: 7993
// Q4 - Round Robin CPU Scheduling

#include <iostream>
using namespace std;

int main() {
    int total, quantum;
    cout << "How many processes? ";
    cin >> total;

    int burst[total], remaining[total], waiting[total], turnaround[total];

    for (int idx = 0; idx < total; idx++) {
        cout << "Burst time for process " << (idx + 1) << ": ";
        cin >> burst[idx];
        remaining[idx] = burst[idx];
    }

    cout << "Time quantum: ";
    cin >> quantum;

    int elapsed = 0;
    bool pending;

    do {
        pending = false;
        for (int idx = 0; idx < total; idx++) {
            if (remaining[idx] == 0) continue;

            pending = true;

            if (remaining[idx] > quantum) {
                elapsed += quantum;
                remaining[idx] -= quantum;
            } else {
                elapsed += remaining[idx];
                waiting[idx] = elapsed - burst[idx];
                remaining[idx] = 0;
            }
        }
    } while (pending);

    double waitSum = 0, turnSum = 0;
    cout << "\nPID\tBurst\tWaiting\tTurnaround\n";
    for (int idx = 0; idx < total; idx++) {
        turnaround[idx] = waiting[idx] + burst[idx];
        cout << (idx + 1) << "\t" << burst[idx] << "\t" << waiting[idx]
             << "\t" << turnaround[idx] << "\n";
        waitSum += waiting[idx];
        turnSum += turnaround[idx];
    }

    cout << "\nAverage Waiting Time: " << (waitSum / total);
    cout << "\nAverage Turnaround Time: " << (turnSum / total) << endl;

    return 0;
}
