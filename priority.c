#include <stdio.h>

struct Process {
    int pid, at, bt, priority, ct, tat, wt, done;
};

int main() {
    int n, time = 0, completed = 0;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        p[i].done = 0;

        printf("Enter Arrival Time, Burst Time and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
    }

    printf("\nGantt Chart: \n");

    while (completed < n) {
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].done == 0 && p[i].at <= time) {
                if (idx == -1 ||
                    p[i].priority < p[idx].priority ||
                    (p[i].priority == p[idx].priority &&
                     p[i].at < p[idx].at)) {
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            int next = -1;

            for (int i = 0; i < n; i++) {
                if (p[i].done == 0) {
                    if (next == -1 || p[i].at < p[next].at) {
                        next = i;
                    }
                }
            }

            time = p[next].at;
            continue;
        }

        time += p[idx].bt;
        p[idx].ct = time;

        printf(" P%d | ", p[idx].pid);

        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        avgwt += p[idx].wt;
        avgtat += p[idx].tat;
        p[idx].done = 1;
        completed++;
    }

    printf("\n\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage WT: %.2f", avgwt / n);
    printf("\nAverage TAT: %.2f\n", avgtat / n);

    return 0;
}
