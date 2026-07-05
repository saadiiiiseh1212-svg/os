// Name: Saad Azhar
// Roll No: 7993
// Q5 - Comparing FCFS, SJF, and Priority Scheduling

#include <iostream>
using namespace std;

double getFCFSWait(int arrival[], int burst[], int total) {
    int arr[total], bur[total], finish[total];
    for (int idx = 0; idx < total; idx++) {
        arr[idx] = arrival[idx];
        bur[idx] = burst[idx];
    }

    for (int a = 0; a < total - 1; a++)
        for (int b = 0; b < total - a - 1; b++)
            if (arr[b] > arr[b + 1]) {
                swap(arr[b], arr[b + 1]);
                swap(bur[b], bur[b + 1]);
            }

    finish[0] = arr[0] + bur[0];
    for (int idx = 1; idx < total; idx++)
        finish[idx] = max(finish[idx - 1], arr[idx]) + bur[idx];

    double sum = 0;
    for (int idx = 0; idx < total; idx++)
        sum += (finish[idx] - arr[idx]) - bur[idx];

    return sum / total;
}

double getSJFWait(int burst[], int total) {
    int bur[total];
    bool finished[total];
    for (int idx = 0; idx < total; idx++) {
        bur[idx] = burst[idx];
        finished[idx] = false;
    }

    int clock = 0, count = 0;
    double sum = 0;

    while (count < total) {
        int pick = -1;
        for (int idx = 0; idx < total; idx++)
            if (!finished[idx] && (pick == -1 || bur[idx] < bur[pick]))
                pick = idx;

        sum += clock;
        clock += bur[pick];
        finished[pick] = true;
        count++;
    }

    return sum / total;
}

double getPriorityWait(int burst[], int priority[], int total) {
    int bur[total], pri[total];
    for (int idx = 0; idx < total; idx++) {
        bur[idx] = burst[idx];
        pri[idx] = priority[idx];
    }

    for (int a = 0; a < total - 1; a++)
        for (int b = 0; b < total - a - 1; b++)
            if (pri[b] > pri[b + 1]) {
                swap(pri[b], pri[b + 1]);
                swap(bur[b], bur[b + 1]);
            }

    int wait[total];
    wait[0] = 0;
    for (int idx = 1; idx < total; idx++)
        wait[idx] = wait[idx - 1] + bur[idx - 1];

    double sum = 0;
    for (int idx = 0; idx < total; idx++)
        sum += wait[idx];

    return sum / total;
}

int main() {
    int total;
    cout << "How many processes? ";
    cin >> total;

    int arrival[total], burst[total], priority[total];

    for (int idx = 0; idx < total; idx++) {
        cout << "\nProcess " << (idx + 1) << ":\n";
        cout << "  Arrival time: ";
        cin >> arrival[idx];
        cout << "  Burst time: ";
        cin >> burst[idx];
        cout << "  Priority (lower value = higher priority): ";
        cin >> priority[idx];
    }

    double fcfsResult = getFCFSWait(arrival, burst, total);
    double sjfResult = getSJFWait(burst, total);
    double priorityResult = getPriorityWait(burst, priority, total);

    cout << "\n--- Scheduling Algorithm Comparison ---\n";
    cout << "FCFS average waiting time:     " << fcfsResult << "\n";
    cout << "SJF average waiting time:      " << sjfResult << "\n";
    cout << "Priority average waiting time: " << priorityResult << "\n";

    double best = min(fcfsResult, min(sjfResult, priorityResult));

    cout << "\nBest performing algorithm: ";
    if (best == fcfsResult) cout << "FCFS\n";
    else if (best == sjfResult) cout << "SJF\n";
    else cout << "Priority Scheduling\n";

    return 0;
}
