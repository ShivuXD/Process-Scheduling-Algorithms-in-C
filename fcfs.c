#include <stdio.h>

struct Process {
    int pid, at, bt, ct, tat, wt;

};

int main() {
    int n;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of process(es): ");
    scanf("%d", &n);

    struct Process p[n], temp;

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        
        printf("Enter Arrival Time and Burst Time of P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    int time = 0;
    printf("Gantt Chart: \n");
    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at;
        }
        p[i].ct = time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        time = p[i].ct;
        avgwt += p[i].wt;
        avgtat += p[i].tat;
        printf("P%d |\t", i+1);
    }
    printf("\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Average Waiting Time: %.2f\n", avgwt / n);
    printf("Average Turnaround Time: %.2f", avgtat / n);
    return 0;
}
