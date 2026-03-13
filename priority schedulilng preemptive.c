#include <stdio.h>
#include <limits.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pid[n], at[n], bt[n], pr[n];
    int rt[n], ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++)
    {
        printf("\nEnter Process ID, Arrival Time, Burst Time, Priority: ");
        scanf("%d %d %d %d",&pid[i],&at[i],&bt[i],&pr[i]);

        rt[i] = bt[i];   // Remaining time
    }

    int current_time = 0;
    int completed = 0;

    while(completed < n)
    {
        int highest_priority = INT_MAX;
        int selected_process = -1;

        for(int i=0;i<n;i++)
        {
            if(at[i] <= current_time && rt[i] > 0)
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
            rt[selected_process]--;

            current_time++;

            if(rt[selected_process] == 0)
            {
                ct[selected_process] = current_time;

                tat[selected_process] =
                    ct[selected_process] - at[selected_process];

                wt[selected_process] =
                    tat[selected_process] - bt[selected_process];

                completed++;
            }
        }
    }

    float total_tat = 0, total_wt = 0;

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f", total_wt/n);

    return 0;
}
