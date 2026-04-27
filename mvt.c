#include <stdio.h>
#include <string.h>

int main(){
    int ms, np, i;
    int process[10];

    printf("total memory size: ");
    scanf("%d", &ms);

    printf("number of processes: ");
    scanf("%d", &np);

    printf("enter process size: ");
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &process[i]);
    }
    
    for (int i = 0; i < np; i++)
    {
        if (process[i] <= ms)
        {
            printf("process %d allocated \n", i+1);
            ms -= process[i];
        }
        else{
            printf("process %d not allocated\n", i+1);
        }
        
    }

    printf("remaining memory : %d", ms);


    return 0;
}