
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];

    // Step 1: Read arrival time and burst time
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("Arrival time and burst time of P%d: ", i + 1);

        if (scanf("%d %d", &at[i], &bt[i]) != 2 ||
            at[i] < 0 || bt[i] <= 0) {
            printf("Invalid input. Use AT >= 0 and BT > 0.\n");
            return 1;
        }
    }

    // Step 2: Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (at[j] > at[j + 1]) {
                int temp;

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    // Step 3: Initialize time and averages
    int time = 0;
    float total_tat = 0;
    float total_wt = 0;

    // Step 4: Execute processes using FCFS
    printf("\nGantt Chart\n0");

    for (int i = 0; i < n; i++) {

        if (time < at[i]) {
            time = at[i];
            printf(" [idle] %d", time);
        }

        time = time + bt[i];

        printf(" [P%d] %d", pid[i], time);

        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat = total_tat + tat[i];
        total_wt = total_wt + wt[i];
    }

    printf("\n");

    // Step 5: Display process table
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Step 6: Display average times
    printf("\nAverage Turnaround Time = %.2f ms\n",
           total_tat / n);

    printf("Average Waiting Time = %.2f ms\n",
           total_wt / n);

    return 0;
}

