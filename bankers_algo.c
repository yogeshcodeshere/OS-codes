#include <stdio.h>
#include <string.h>

#define MAX 10

int main(){
    int n, m;

    printf("enter the number of processes: ");
    scanf("%d", &n);

    printf("enter the number of resources: ");
    scanf("%d", &m);

    int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX];
    int avail[MAX], finish[MAX] = {0};
    int safeseq[MAX];

    //input allocation matrix
    printf("enter allocation matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);

        }
    }


    //input max matrix
    printf("enter max matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);

        }
    }

    //input available resources
    printf("enter available resources: \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    //calculating need matrix
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];

        }
    }

    //bankers algorithm
    int count = 0;
    while(count < n){
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0) 
            {
                int j;
                for (j = 0; j < m; j++)
                {
                    if (avail[j] < need[i][j])
                    {
                        break;
                    }
                    
                }
                if (j == m)
                {
                    for (int k = 0; k < m; k++)
                    {
                        avail[k] += alloc[i][k];
                    }
                    safeseq[count++] = i+1;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0){
            printf("\nsystem is not in a safe state\n");

            return 0;
        }
    }

    //safe state
    printf("\nsystem is in safe state.\nthe safe sequence is : ");
    for (int i = 0; i < n; i++)
    {
        printf("p%d ", safeseq[i]);
    }
    printf("\n");
    
    return 0;
}