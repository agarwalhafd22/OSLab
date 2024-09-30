#include <stdio.h>
#include <stdlib.h>

int safety(int p, int r, int all[p][r],int max[p][r],int needed[p][r], int avail[p+2][r])
{
    int k=0;
    int c=0;
    int num=0;
    int d;
    for(int i=0;i<p;i++)
    {
        for(d=0;d<p;d++)
        {
            c=0;
            for(int j=0;j<r;j++)
            {
                if(needed[d][j]!=-1)
                    if(avail[k][j]>=needed[d][j])
                        c++;
            }
            if(c==r)
                break;
        }
        if(c==r)
        {
            num=num*10+(d+1);
            k++;
            for(int l=0;l<r;l++)
            {
                avail[k][l]=avail[k-1][l]+all[d][l];
                needed[d][l]=-1;
            }
        }
        else
            return 0;
    }
    return num;
}

void request(int p, int r, int all[p][r],int max[p][r],int needed[p][r], int avail[p+2][r])
{
    int proNum;
    int resReq[r];
    int k=0;
    printf("Enter process number: ");
    scanf("%d", &proNum);
    printf("Enter resource request: ");
    for(int i=0;i<r;i++)
        scanf("%d", &resReq[i]);
    for(int i=0;i<r;i++)
    {
        if(needed[proNum+1][i]<resReq[i])
        {
            printf("Request not granted!");
            exit(0);
        }
    }
    for(int i=0;i<r;i++)
    {
        avail[k][i]=avail[k][i]-resReq[i];
        needed[proNum-1][i]=needed[proNum-1][i]-resReq[i];
        all[proNum-1][i]=all[proNum-1][i]+resReq[i];
    }
    int num=safety(p,r,all,max,needed,avail);
    if(num==0)
        printf("Request not granted!");
    else
        printf("Safe sequence is: %d", num);
}

int main()
{
    int p,r;
    printf("Enter no of processes:\n");
    scanf("%d", &p);
    printf("Enter no of resources:\n");
    scanf("%d", &r);
    int all[p][r];
    int max[p][r];
    int needed[p][r];
    int avail[p+2][r];
    char str[p];
    for(int i=0;i<p;i++)
    {
        printf("Enter all the allocated resources for process no %d: ", i+1);
        for(int j=0;j<r;j++)
        {
            scanf("%d", &all[i][j]);
        }
    }
    printf("\n");
    for(int i=0;i<p;i++)
    {
        printf("Enter all the max resources for process no %d: ", i+1);
        for(int j=0;j<r;j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("\n");
    
    printf("Enter no of instances of each resources available:\n");
    for(int i=0;i<r;i++)
        scanf("%d", &avail[0][i]);
        
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            needed[i][j]=max[i][j]-all[i][j];
        }
    } 
    printf("\n");
    for(int i=0;i<p;i++)
    {
        printf("Resources needed for process %d: ", i+1);
        for(int j=0;j<r;j++)
        {
            printf("%d ", needed[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int c;
    printf("Enter 1 for safety sequcence and 2 for resource-request:\n");
    scanf("%d", &c);
    int num;
    if(c==1)
    {
        num=safety(p,r,all,max,needed,avail);
        if(num==0)
            printf("No safety sequence, deadlock present!\n");
        else
            printf("Safe sequence is: %d", num);
    }
    else
        request(p,r,all,max,needed,avail);
}