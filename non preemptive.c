#include <stdio.h>

struct process {
    int pid, at, bt, pr, ct, wt, tat, completed;
};

int main() {
    int n, completed_count = 0, current_time = 0;
    float total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nFor Process P%d:\n", p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Priority (Lower # = Higher Priority): ");
        scanf("%d", &p[i].pr);
        p[i].completed = 0;
    }

    printf("\n--- Execution Order ---\n");

    while(completed_count < n) {
        int idx = -1;
        int highest_priority = 9999;

        for(int i = 0; i < n; i++) {
            if(p[i].at <= current_time && p[i].completed == 0) {
                if(p[i].pr < highest_priority) {
                    highest_priority = p[i].pr;
                    idx = i;
                }
                else if(p[i].pr == highest_priority) {
                    if(p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if(idx == -1) {
            current_time++;
        } else {

            p[idx].ct = current_time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            total_wt += p[idx].wt;
            total_tat += p[idx].tat;

            printf("Time %d: P%d starts | Ends at %d\n", current_time, p[idx].pid, p[idx].ct);

            current_time = p[idx].ct;
            p[idx].completed = 1;
            completed_count++;
        }
    }
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid, p[i].at, p[i].bt, p[i].pr, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
