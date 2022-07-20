#include <stdio.h>
int findex(int arrt[],int n,int x)
    {   
        int a=(n-1),min=-999;
        for(int i=0;i<n;i++)
            {
                if(arrt[i]>x)
                    {a = i-1; break;}
            }
    
        return a;
    }
int sum(int a[], int n)
    {   
        int s=0;
        for(int i=0;i<n;i++)
            s = s + a[i];
    
        return s;
    }
void swap(int b[], int x, int y)
    {
        int t = b[x];
        b[x] = b[y];
        b[y] = t;
    }
double avg(int a[],int n)
    {   
        int ans = a[0];
        for(int i=1;i<n;i++)
            {
                ans = a[i] + ans;
            }
    
        double avg = (double) ans/(double) n;  
    
        return avg;
    }
void printry(int a[], int n)
    {
        printf("Array is : ");
        for(int i=0;i<n;i++)
            {
                printf("%d ", a[i]);
            }
    
        printf("\n");
    }
void arrcpy(int src[], int desti[], int n)
    {
        for(int i=0;i<n;i++)
            {desti[i] = src[i];}
    }
void srt(int a[], int n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {    
                if(a[i]<a[j])
                    {swap(a,i,j);}
            }
    }

int sjf(int pr[],int k, int ans[],int freq[])
    {
        int min = 999999;
        int p;
        for(int i=0;i<=k;i++)
            {
                if(pr[(ans[i]-1)]<min && freq[(ans[i]-1)]!=1)
                    {min = pr[(ans[i]-1)];
                     p = i;
                    }
            }
    
        freq[(ans[p]-1)] = 1;
        return p;
    }
int main() {
	int n;
	printf("Enter no. of Processes\n");
	scanf("%d", &n);
	int arrt[n],burst[n],proc[n];
	
	for(int i=0;i<n;i++)
        {
            if(i==0)
                {printf("Enter Arrival time, Burst time and Priority respectively for\n");}
            
            printf("process no.%d: \n", (i+1));
            scanf("%d", &arrt[i]);
            scanf("%d", &burst[i]);
            scanf("%d", &proc[i]);
        }
// 	printf("P AT BT Pr\n");
// 	for(int i=0;i<n;i++)
// 	    {
// 	        printf("P%d %d %d %d\n", (i+1),at[i],bt[i],p[i]);
// 	    }
	
	int ato[n];
	int atf[n];
	int bto[n];
	arrcpy(arrt,ato,n);
	arrcpy(arrt,atf,n);
	arrcpy(burst,bto,n);
	 srt(arrt,n);
// 	 printry(at,n);

int ans[n];
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
            {
                if(arrt[i] == ato[j])
                    {ans[i] = j+1;
                        ato[j] = -1;
                        break;
                    }
            }
//printry(ans,n);
int fin[n];
int k=0,v=0;
int freq[n];
for(int j=0;j<n;j++)
    freq[j] = 0;
int t=arrt[0];
do
{
    while(arrt[k] == arrt[k+1])
    {k++;}
    int m = sjf(burst,k,ans,freq);
    fin[v] = ans[m];
    if(k < (n-1))
    {t = t + burst[(fin[v]-1)];
        k = findex(arrt,n,t);
    }
    v++;
}while(sum(freq,n) != 5);

//printry(fin,n);


int ext[n],wt[n],tat[n];
ext[0] = burst[(fin[0]-1)] + arrt[0];
for(int j=1;j<n;j++)
    {
        ext[j] = burst[(fin[j] - 1)] + ext[j-1]; 
    }

// printf("Time ");
// printry(ext,n);

for(int i=0;i<n;i++)
    {
        tat[(fin[i]-1)] = ext[i] - atf[(fin[i]-1)]; 
    }
// printf("Turn Around time ");
// printry(tat,n);

for(int i=0;i<n;i++)
    {
        wt[i] = tat[i] - burst[i];
    }
printf("\nFor Process:\n");    
for(int i=0;i<n;i++)
    {
        printf("P%d:- Turnaround Time is %d & Waiting Time is %d\n", (i+1),tat[i],wt[i]);
    }
printf("Avg Turnaround Time is %.3f & Avg Waiting Time is %.3f\n", avg(tat,n),avg(wt,n));


	return 0;
}
