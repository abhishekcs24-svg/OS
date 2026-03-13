#include <stdio.h>
#include <limits.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n];
    int completed[n];

    float total_tat = 0, total_wt = 0;

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter Process ID, Arrival Time, Burst Time, Priority: ");
        scanf("%d %d %d %d", &pid[i], &at[i], &bt[i], &pr[i]);
        completed[i] = 0;
    }

    int current_time = 0;
    int completed_count = 0;

    while(completed_count < n)
    {
        int highest_priority = INT_MAX;
        int selected_process = -1;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= current_time && completed[i] == 0)
            {
                if(pr[i] < highest_priority)
                {
                    highest_priority = pr[i];
                    selected_process = i;
                }
            }
        }

        if(selected_process == -1)
        {
            current_time++;
        }
        else
        {
            int start_time = current_time;

            ct[selected_process] = start_time + bt[selected_process];

            tat[selected_process] = ct[selected_process] - at[selected_process];

            wt[selected_process] = tat[selected_process] - bt[selected_process];

            current_time = ct[selected_process];

            completed[selected_process] = 1;
            completed_count++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);

        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", total_tat/n);
    printf("\nAverage WT = %.2f", total_wt/n);

    return 0;
}
