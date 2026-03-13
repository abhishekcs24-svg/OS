#include<stdio.h>

int main()
{
    int n, AT[10], BT[10], CT[10], TAT[10], WT[10], PID[10], comp_status[10], completed,curr_time,i,j;
    curr_time=0, completed=0;
    float Tsum=0,Wsum=0 ;
    float AvgTAT, AvgWT;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter arrival time of process %d: ",i+1);
        scanf("%d",&AT[i]);
        printf("Enter burst time of process %d: ",i+1);
        scanf("%d",&BT[i]);

        PID[i]=i;

        comp_status[i]=0;
    }

    while(completed<n)
    {
        int min = 10000,minIndex=-1;
        for(i=0;i<n;i++)
        {
            if ((AT[i]<=curr_time) && (comp_status[i]==0))
            {
                if(BT[i]<min)
                {
                    min=BT[i];
                    minIndex=i;
                }
            }
        }
        if(min==10000)
        {
            curr_time++;
        }
        else
        {
            CT[minIndex] = curr_time + BT[minIndex];
            TAT[minIndex] = CT[minIndex] - AT[minIndex];
            WT[minIndex] = TAT[minIndex] - BT[minIndex];
            comp_status[minIndex]=1;
            curr_time = CT[minIndex];
            completed++;
        }


    }

    for(i=0;i<n;i++)
    {
        Wsum+=WT[i];
        Tsum+=TAT[i];
    }

    AvgWT = (Wsum/n);
    AvgTAT = (Tsum/n);

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT");
    printf("\n------------------------------------------\n");
    for( i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", (PID[i]+1),AT[i],BT[i],CT[i],TAT[i],WT[i]);
    }

    printf("\nThe average waiting time is %.6f", AvgWT);
    printf("\nThe average turnaround time is %.6f", AvgTAT);

}




