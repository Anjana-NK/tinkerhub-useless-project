#include <stdio.h>

void main() {
    int n;
    int arrival[10], burst[10], waiting[10], turnaround[10], completion[10];
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter arrival time of P%d:", i+1);
        scanf("%d",&arrival[i]);

        printf("Enter burst time of P%d:", i+1);
        scanf("%d",&burst[i]);
    }

    int currentTime = 0;

    for(int i = 0; i < n; i++) {
        if(currentTime<arrival[i]) {
            currentTime=arrival[i];
        }

        waiting[i]=currentTime-arrival[i];
        currentTime+=burst[i];
        completion[i]=currentTime;
        turnaround[i]=completion[i]-arrival[i];
    }

    printf("\nGantt Chart:\n|");
    for(int i=0; i<n; i++) {
        printf(" P%d |",i+1);
    }

    printf("\n0");
    for(int i=0; i<n; i++) {
        printf("   %d", completion[i]);
    }

    printf("\n\nProcess\tAT\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",i+1,arrival[i],burst[i],waiting[i],turnaround[i]);
        avgWT+=waiting[i];
        avgTAT+=turnaround[i];
    }
    avgWT/=n;
    avgTAT/=n;

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

}
