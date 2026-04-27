#include <stdio.h>
#include <string.h>

int main(){
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter AT and BT for process%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    //first process
    ct[0] = at[0] + bt[0];
    

    //calculating ct
    
    for (int i = 1; i < n; i++)
    {
        if(ct[i-1] < at[i]){
            ct[i] = at[i] + bt[i];
        }
        else{
            ct[i] = ct[i-1] + bt[i];
        }
    }

    //calculating wt and tat

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    
    //averages
    float wt_avg = 0, avg_tat = 0;
    for (int i = 0; i < n; i++)
    {
        wt_avg += wt[i];
        avg_tat += tat[i];
    }

    wt_avg = wt_avg / n;
    avg_tat = avg_tat / n;
    
    printf("Processid\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++)
    {
        printf("p%d\t\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    return 0;
}