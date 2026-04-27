#include <stdio.h>
#include <string.h>

int mutex = 1, full = 0, empty = 5, item = 0;

void wait(int *s){
    while(*s <=0);
    (*s)--;
}

void signal(int *s){
    (*s)++;
}

void producer(){
    if (empty == 0){
        printf("buffer is full");
        return;
    }

    wait(&empty);
    wait(&mutex);

    item++;
    printf("\nproduced: %d", item);

    signal(&mutex);
    signal(&full);
}

void consumer(){
    if (full == 0)
    {
        printf("\nbuffer is empty!");
        return;
    }
    
    wait(&full);
    wait(&mutex);

    printf("\nconsumed: %d", item);
    item--;

    signal(&mutex);
    signal(&empty);
}




int main(){
    int choice;

    while(1){
        printf("\n1. produce\n2. Consume\n3. exit\nchoice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            producer();
        }
        else if (choice == 2)
        {
            consumer();
        }
        else if (choice == 3)   
        {
            break;
        }
        else{
            printf("invalid answer");
        }
        
        
        
    }
    




    return 0;
}