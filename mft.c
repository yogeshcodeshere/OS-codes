#include <stdio.h>
#include <string.h>

int main(){
    int nb, np, i, j;
    int block[10], process[10];
    int allocations[10];
    int frag = 0;

    printf("enter the number of blocks: ");
    scanf("%d", &nb);

    printf("enter block sizes: ");
    for (int i = 0; i < nb; i++)
    {
        scanf("%d", &block[i]);
    }
    
    printf("enter the number of processes: ");
    scanf("%d", &np); 

    printf("enter process sizes: ");
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &process[i]);
    }

    for (int i = 0; i < np; i++)
    {
        allocations[i] = -1;
    }
    
    //allocation logic

    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if (block[j] >= process[i])
            {
                allocations[i] = j;
                frag += block[j] - process[i];
                block[j] = 0;
                break;
            }
            
        }
        
    }

    printf("\nprocess\tblock\n");
    for (int i = 0; i < np; i++)
    {
        if (allocations[i] != -1){
            printf("P%d\t%d\n", i+1, allocations[i]+1);
        }
        else{
            printf("P%d\tnot allocated\n", i+1);

        }

        
        
        
    }
    
    printf("\ntotal fragmentation : %d\n", frag);


    return 0;
}