#include <stdio.h>

struct Process {
    int pid, at, bt, rt, ct, tat, wt;
};

int main() {
    int n, time = 0, completed = 0, prev = -2;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);

        p[i].rt = p[i].bt;
    }

    printf("\nGantt Chart: \n");

    while (completed < n) {
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (idx == -1 ||
                    p[i].rt < p[idx].rt ||
                    (p[i].rt == p[idx].rt &&
                     p[i].at < p[idx].at)) {
                    idx = i;
                }
            }
        }
        if (idx != prev) {
            if (prev >= 0){
                printf(" P%d | ", p[prev].pid);
            }
            prev = idx;
        }

        if (idx == -1) {
            time++;
            continue;
        }

        p[idx].rt--;
        time++;

        if (p[idx].rt == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            avgwt += p[idx].wt;
            avgtat += p[idx].tat;
            completed++;
        }
    }

    if (prev >= 0){
        printf(" P%d | ", p[prev].pid);
    }

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage WT: %.2f", avgwt / n);
    printf("\nAverage TAT: %.2f\n", avgtat / n);

    return 0;
}
