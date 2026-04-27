#include <stdio.h>

int main() {
    int frames, n, i, j, k = 0, page_faults = 0;
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n], memory[frames];

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < frames; i++)
    {
        memory[i] = -1; 
    }

    //fifo logic
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < frames; j++)
        {
            if(memory[j] == pages[i]){
                found = 1;
                break;
            }
        }

        if(!found){
            memory[k] = pages[i];
            k = (k+1) % frames;
            page_faults++;

        }

        printf("\n");
        for (int j = 0; j < frames; j++)
        {
            if (memory[j] != -1)
            {
                printf("%d ", memory[j]);
            }
            else{
                printf("- ");
            }
            
        }
        
        
    }
    printf("\ntotal page faults: %d\n", page_faults);


    return 0;

}