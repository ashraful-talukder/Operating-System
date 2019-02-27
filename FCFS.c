#include<stdio.h>
#include<conio.h>

int main()
{
    int n,i,j,at[20],bt[20],t1,t2,ct[20],tat[20],wt[20],ttat=0,twt=0;
    printf("Enter the number of process(max 20): ");
    scanf("%d",&n);
    printf("\t\t\tEnter the processes\n");
    printf("processes\tArrival Time Burst time\n");
    for(i=0 ; i<n ; i++)
    {
        printf("process[%d]:\t\t",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }
    for(i=0 ; i<n-1 ; i++)
    {
        for(j=i+1 ; j<n ; j++)
        {
            if(at[i]>at[j])
            {
                t1=at[i];
                at[i]=at[j];
                at[j]=t1;

                t2=bt[i];
                bt[i]=bt[j];
                bt[j]=t2;
            }
        }
    }
    for(i=0 ; i<n ; i++)
    {
        if(i==0)
        {
            ct[i]=at[i]+bt[i];
        }
        else
        {
            if(ct[i-1]<at[i])
            {
                ct[i]=at[i]+bt[i];
            }
            else
            {
                ct[i]=ct[i-1]+bt[i];
            }
        }
    }
    for(i=0 ; i<n ; i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=ct[i]-at[i]-bt[i];
        ttat=ttat+tat[i];
        twt=twt+wt[i];
    }
    printf("processes\tarrival\tburst\tcompletion\twaiting\tturnaround\n");
    for(i=0 ; i<n ; i++)
    {
        printf("process[%d]\t[%d]\t[%d]\t[%d]\t[%d]\t[%d]\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
    }


    return 0;
}
