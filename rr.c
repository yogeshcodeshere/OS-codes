#include <stdio.h>
#include <string.h>

int main(){
    int n, i, time=0, remain;

    printf("enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    //input
    for (int i = 0; i < n; i++)
    {
        printf("enter AT and BT for process%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int q;
    printf("Enter time quantum: ");
    scanf("%d", &q);

    remain = n;

    while(remain > 0){
        int done = 1;

        for (int i = 0; i < n; i++)
        {
            if (rt[i] > 0 && at[i] <= time)
            {
                done = 0;
                if (rt[i] > q)
                {
                    time += q;
                    rt[i] -= q;
                }

                else if (rt[i] <= q)
                {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    remain--;
                }
                
                
            }
            
        }

        if (done==1){
            time++;
        }
        
    }

    //calculating wt and tat
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    //caculating averages
    float awt = 0, atat = 0;
    for (int i = 0; i < n; i++)
    {
        awt += wt[i];
        atat += tat[i];
    }

    awt /= n;
    atat /= n;

    printf("Processid\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++)
    {
        printf("p%d\t\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}