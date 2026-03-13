#include<stdio.h>

int main()
{
    int n, AT[10],BT[10],TAT[10],WT[10],CT[10],PD[10];
    float Wavg,Tavg;
    float Wsum=0;
    float Tsum=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for (int i=0;i<n;i++)
    {
        printf("\nEnter arrival time %d: ",(i+1));
        scanf("%d",&AT[i]);
        printf("\nEnter burst time %d: ",(i+1));
        scanf("%d",&BT[i]);
        PD[i]=i;
    }
    WT[0]=0;
    TAT[0] = BT[0];

    for(int i=1; i<n ; i++)
    {
        WT[i] = (WT[i-1] + BT[i-1] + AT[i-1])-AT[i];
        if (WT[i]<0)
        {
             WT[i]=0;
        }

        TAT[i]=WT[i]+BT[i];
    }

    for(int i=0;i<n;i++)
    {
        Wsum+=WT[i];
        Tsum+=TAT[i];
    }

    Wavg=Wsum/n;
    Tavg=Tsum/n;

    printf("\nAverage waiting time is %f",Wavg);
    printf("\nAverage turnaroundf time is %f",Tavg);
}

