#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    char name[20];
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};


void fcfsScheduling(struct Process queue[], int n, int *currentTime) {
    for (int i = 0; i < n; i++) {
        if (*currentTime < queue[i].arrivalTime) {
            *currentTime = queue[i].arrivalTime;
        }
        queue[i].completionTime = *currentTime + queue[i].burstTime;
        queue[i].turnaroundTime = queue[i].completionTime - queue[i].arrivalTime;
        queue[i].waitingTime = queue[i].turnaroundTime - queue[i].burstTime;
        *currentTime = queue[i].completionTime;
    }
}
void displayResults(struct Process queue[], int n, char type[]) {
    printf("\n--- %s Processes ---\n", type);
    printf("Name\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
               queue[i].name,
               queue[i].arrivalTime,
               queue[i].burstTime,
               queue[i].completionTime,
               queue[i].turnaroundTime,
               queue[i].waitingTime);
    }
}

int main() {
    int nSystem, nUser;
    int currentTime = 0;

    printf("Enter number of system processes: ");
    scanf("%d", &nSystem);
    struct Process systemQueue[nSystem];

    for (int i = 0; i < nSystem; i++) {
        printf("Enter name, arrival time, burst time for system process %d: ", i + 1);
        scanf("%s %d %d", systemQueue[i].name, &systemQueue[i].arrivalTime, &systemQueue[i].burstTime);
    }

    printf("Enter number of user processes: ");
    scanf("%d", &nUser);
    struct Process userQueue[nUser];

    for (int i = 0; i < nUser; i++) {
        printf("Enter name, arrival time, burst time for user process %d: ", i + 1);
        scanf("%s %d %d", userQueue[i].name, &userQueue[i].arrivalTime, &userQueue[i].burstTime);
    }


    fcfsScheduling(systemQueue, nSystem, &currentTime);
    displayResults(systemQueue, nSystem, "System");


    fcfsScheduling(userQueue, nUser, &currentTime);
    displayResults(userQueue, nUser, "User");

    return 0;
}

