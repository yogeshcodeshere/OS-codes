#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    int head;
    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total_seek = 0;

    printf("\nmovement: \n");

    for (int i = 0; i < n; i++)
    {
        int distance = abs(head - req[i]);
        total_seek += distance;
        printf("%d -> %d (seek = %d)", head, req[i], distance);
        head = req[i];
    }
    
    
    printf("total seek is %d", total_seek);

    return 0;
}