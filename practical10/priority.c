#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int bt[20], p[20], pr[20];
    int wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if(n < 1 || n > 20)
    {
        printf("Invalid number of processes");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;

        printf("Enter burst time for P%d: ", p[i]);
        scanf("%d", &bt[i]);

        if(bt[i] <= 0)
        {
            printf("Invalid burst time");
            return 0;
        }

        printf("Enter priority for P%d: ", p[i]);
        scanf("%d", &pr[i]);
    }

    // Sort according to priority
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(pr[i] > pr[j])
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t%d\t%d\n",
        p[i], pr[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);

    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
