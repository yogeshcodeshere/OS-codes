#include <stdio.h>
#include <string.h>

int main()
{
    int nb, np, i, j;
    int block[10], process[10], alloc[10];

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for (i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for (i = 0; i < np; i++)
    {
        scanf("%d", &process[i]);
        alloc[i] = -1;
    }

    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if (block[j] >= process[i])
            {
                alloc[i] = j;
                block[j] = 0;
                break;
            }
            
        }
        
    }

    printf("\nprocess\tblock\n");
    for (int i = 0; i < np; i++)
    {
        if(alloc[i] != -1){
            printf("p%d\t%d\n", i+1, alloc[i]+1);
        }
        else{
            printf("p%d\tnot allocated\n", i+1);
        }
    }
    

    return 0;
}