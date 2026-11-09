#include <stdio.h>

struct Process {
    int pid, at, bt, rt, ct, tat, wt;
};

int main() {
    int n, tq, time = 0, completed = 0;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n], temp;

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    printf("Enter the Time Quantum: ");
    scanf("%d", &tq);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int queue[n + 1];
    int front = 0, rear = 0, size = 0;
    int next = 0;
    printf("\nGantt Chart: \n");

    while (completed < n) {
        while (next < n && p[next].at <= time) {
            queue[rear] = next;
            rear = (rear + 1) % (n + 1);
            size++;
            next++;
        }
        if (size == 0) {
            time = p[next].at;
            continue;
        }
        int idx = queue[front];
        front = (front + 1) % (n + 1);
        size--;

        int execute = (p[idx].rt < tq) ? p[idx].rt : tq;
        time += execute;
        p[idx].rt -= execute;

        printf(" P%d | ", p[idx].pid);

        while (next < n && p[next].at <= time) {
            queue[rear] = next;
            rear = (rear + 1) % (n + 1);
            size++;
            next++;
        }

        if (p[idx].rt == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            avgwt += p[idx].wt;
            avgtat += p[idx].tat;
            completed++;
        } else {
            queue[rear] = idx;
            rear = (rear + 1) % (n + 1);
            size++;
        }
    }

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage WT: %.2f", avgwt / n);
    printf("\nAverage TAT: %.2f\n", avgtat / n);

    return 0;
}
 
