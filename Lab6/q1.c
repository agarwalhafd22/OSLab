#include <stdio.h>
#include <stdlib.h>

int find_min_bt(int bt[], int n, int completed[])
{
    int min = 999, min_index;
    for (int i = 0; i < n; i++)
    {
        if (bt[i] < min && completed[i] == 0)
        {
            min = bt[i];
            min_index = i;
        }
    }
    return min_index;
}

void preemptive_sjf(int p[], int at[], int bt[], int n)
{
    int ct[n], tat[n], wt[n], completed[n];
    int time = 0, i, j, min_index;
    for (i = 0; i < n; i++)
    {
        completed[i] = 0;
    }
    while (1)
    {
        int flag = 0;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && completed[i] == 0)
            {
                flag = 1;
                min_index = find_min_bt(bt, n, completed);
                time += bt[min_index];
                ct[min_index] = time;
                completed[min_index] = 1;
            }
        }
        if (flag == 0)
            break;
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
}

void round_robin(int p[], int at[], int bt[], int n, int quantum)
{
    int ct[n], tat[n], wt[n], temp_bt[n];
    int time = 0, i, j;
    for (i = 0; i < n; i++)
    {
        temp_bt[i] = bt[i];
    }
    while (1)
    {
        int flag = 0;
        for (i = 0; i < n; i++)
        {
            if (temp_bt[i] > 0)
            {
                flag = 1;
                if (temp_bt[i] > quantum)
                {
                    time += quantum;
                    temp_bt[i] -= quantum;
                }
                else
                {
                    time += temp_bt[i];
                    temp_bt[i] = 0;
                    ct[i] = time;
                }
            }
        }

        if (flag == 0)
            break;
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
}
void non_preemptive_priority(int p[], int at[], int bt[], int priority[], int n)
{
    int ct[n], tat[n], wt[n];
    int time = 0, i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (priority[i] < priority[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        time += bt[i];
        ct[i] = time;
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("Process\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
    }
}

void first_come_first_serve(int p[], int at[], int bt[], int n)
{
    int ct[n], tat[n], wt[n];
    int time = 0, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (time < at[i])
        {
            time = at[i];
        }
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("Process\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        int temp =
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
}

int main()
{
    int choice, n, i, quantum;
    int p[10], at[10], bt[10], priority[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the process IDs, arrival times, burst times, and priorities:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d %d %d %d", &p[i], &at[i], &bt[i], &priority[i]);
    }

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Preemptive SJF\n");
        printf("2. Round Robin\n");
        printf("3. Non-Preemptive Priority Scheduling\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            preemptive_sjf(p, at, bt, n);
            break;
        case 2:
            printf("Enter the time quantum: ");
            scanf("%d", &quantum);
            round_robin(p, at, bt, n, quantum);
            break;
        case 3:
            non_preemptive_priority(p, at, bt, priority, n);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}