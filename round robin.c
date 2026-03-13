#include <stdio.h>

int main()
{
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n];
    int wt[n], tat[n], ct[n];

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter Process ID, Arrival Time, Burst Time: ");
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);

        rt[i] = bt[i]; // remaining time
    }

    int current_time = 0, completed = 0;

    float total_wt = 0, total_tat = 0;

    while(completed < n)
    {
        int executed = 0;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= current_time && rt[i] > 0)
            {
                executed = 1;

                if(rt[i] > tq)
                {
                    current_time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    current_time += rt[i];

                    ct[i] = current_time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    total_tat += tat[i];
                    total_wt += wt[i];

                    rt[i] = 0;
                    completed++;
                }
            }
        }

        if(executed == 0)
        {
            current_time++; // CPU idle
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f", total_wt/n);

    return 0;
}
