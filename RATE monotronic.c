#include <stdio.h>
#include <math.h>

#define MAX 10

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int find_lcm(int arr[], int n) {
    int res = arr[0];
    for (int i = 1; i < n; i++)
        res = lcm(res, arr[i]);
    return res;
}

int main() {
    int n, i, time;
    int burst[MAX], period[MAX], remaining[MAX] = {0};

    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("Enter the CPU burst times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &burst[i]);

    printf("Enter the time periods:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &period[i]);

    int hyper = find_lcm(period, n);
    printf("LCM=%d\n\n", hyper);

    printf("Rate Monotone Scheduling:\n");
    printf("PID\tBurst\tPeriod\n");

    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", i + 1, burst[i], period[i]);

    float U = 0;
    for (i = 0; i < n; i++)
        U += (float)burst[i] / period[i];

    float bound = n * (pow(2, 1.0 / n) - 1);

    printf("\n%f <= %f => %s\n", U, bound, (U <= bound) ? "true" : "false");

    printf("Scheduling occurs for %d ms\n\n", hyper);

    for (time = 0; time < hyper; time++) {

        for (i = 0; i < n; i++) {
            if (time % period[i] == 0)
                remaining[i] = burst[i];
        }

        int selected = -1, minP = 9999;

        for (i = 0; i < n; i++) {
            if (remaining[i] > 0 && period[i] < minP) {
                minP = period[i];
                selected = i;
            }
        }

        if (selected != -1) {
            printf("%dms onwards: Process %d running\n", time, selected + 1);
            remaining[selected]--;
        } else {
            printf("%dms onwards: CPU is idle\n", time);
        }
    }

    return 0;
}
