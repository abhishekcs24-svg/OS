#include <stdio.h>

int main() {
    int n;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int C[n], D[n], P[n];
    int remaining[n], next_release[n];

    for (int i = 0; i < n; i++) {
        printf("\nTask %d\n", i + 1);

        printf("Execution Time (C%d): ", i + 1);
        scanf("%d", &C[i]);

        printf("Deadline (D%d): ", i + 1);
        scanf("%d", &D[i]);

        printf("Time Period (P%d): ", i + 1);
        scanf("%d", &P[i]);

        remaining[i] = 0;
        next_release[i] = 0;
    }

    int time_period;
    printf("\nEnter total scheduling time: ");
    scanf("%d", &time_period);

    printf("\n--- EDF Scheduling (Periodic Tasks) ---\n");

    for (int time = 0; time < time_period; time++) {


        for (int i = 0; i < n; i++) {
            if (time == next_release[i]) {
                remaining[i] = C[i];
                next_release[i] += P[i];
            }
        }

        int selected = -1;
        int min_deadline = 9999;


        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                int abs_deadline = next_release[i] - P[i] + D[i];

                if (abs_deadline < min_deadline) {
                    min_deadline = abs_deadline;
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            printf("Time %d: Idle\n", time);
        } else {
            printf("Time %d: Task %d\n", time, selected + 1);
            remaining[selected]--;
        }
    }

    return 0;
}
