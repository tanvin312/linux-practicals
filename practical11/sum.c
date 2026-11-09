#include <stdio.h>
#include <pthread.h>

int n, sum = 0;
int a[100];

void *calculate_sum(void *arg)
{
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    return NULL;
}

int main()
{
    pthread_t thread;

    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }
    }

    if (pthread_create(&thread, NULL, calculate_sum, NULL) != 0)
    {
        printf("Thread creation failed.\n");
        return 1;
    }

    if (pthread_join(thread, NULL) != 0)
    {
        printf("Thread joining failed.\n");
        return 1;
    }

    printf("Sum = %d\n", sum);

    return 0;
}
