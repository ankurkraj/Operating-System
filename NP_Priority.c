#include <stdio.h>
int findex(int arrt[],int num,int x)
    {   
        int a=(num-1),min=-999;
        for(int i=0;i<num;i++)
            {
                if(arrt[i]>x)
                    {a = i-1; break;}
            }
    
        return a;
    }
int sum(int a[], int num)
    {   
        int sum=0;
        for(int i=0;i<num;i++)
            sum = sum + a[i];
    
        return sum;
    }

double average(int a[],int num)
    {   
        int ans = a[0];
        for(int i=1;i<num;i++)
            {
                ans = a[i] + ans;
            }
    
        double average = (double) ans/(double) num;  
    
        return average;
    }
void swap(int a[], int x, int y)
    {
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }
void printry(int a[], int num)
    {
        printf("Array is : ");
        for(int i=0;i<num;i++)
            {
                printf("%d ", a[i]);
            }
    
        printf("\n");
    }

void srt(int a[], int num)
    {
        for(int i=0;i<num;i++)
            for(int j=0;j<num;j++)
            {    
                if(a[i]<a[j])
                    {swap(a,i,j);}
            }
    }


void arrcpy(int src[], int desti[], int num)
    {
        for(int i=0;i<num;i++)
            {desti[i] = src[i];}
    }

int npp(int pr[],int k, int ans[],int freq[])
    {
        int min = -999999;
        int p;
        for(int i=0;i<=k;i++)
            {
                if(pr[(ans[i]-1)]>min && freq[(ans[i]-1)]!=1)
                    {min = pr[(ans[i]-1)];
                     p = i;
                    }
            }
    
        freq[(ans[p]-1)] = 1;
        return p;
    }
int main() {
	int num;
	printf("Enter no. of Processes\n");
	scanf("%d", &num);
	int arrt[num],burst[num],proc[num]; //arrt - arrival time array, burst - burst time array, proc - process array
	
	for(int i=0;i<num;i++)
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
	
	int arrto[num];
	int arrtf[num];
	int bursto[num];

	arrcpy(arrt,arrto,num);
	arrcpy(arrt,arrtf,num);
	arrcpy(burst,bursto,num);
	 srt(arrt,num);
// 	 printry(at,n);

int ans[num];
for(int i=0;i<num;i++)
    for(int j=0;j<num;j++)
            {
                if(arrt[i] == arrto[j])
                    {ans[i] = j+1;
                        arrto[j] = -1;
                        break;
                    }
            }
//printry(ans,n);
int fin[num];
int k=0,v=0;
int freq[num];
for(int j=0;j<num;j++)
    freq[j] = 0;
int t=arrt[0];
do
{
    while(arrt[k] == arrt[k+1])
    {k++;}
    int m = npp(proc,k,ans,freq);
    fin[v] = ans[m];
    if(k < (num-1))
    {t = t + burst[(fin[v]-1)];
        k = findex(arrt,num,t);
    }
    v++;
}while(sum(freq,num) != 5);

//printry(fin,n);


int ext[num],wt[num],tat[num];
ext[0] = burst[(fin[0]-1)] + arrt[0];
for(int j=1;j<num;j++)
    {
        ext[j] = burst[(fin[j] - 1)] + ext[j-1]; 
    }

// printf("Time ");
// printry(ext,n);

for(int i=0;i<num;i++)
    {
        tat[(fin[i]-1)] = ext[i] - arrtf[(fin[i]-1)]; 
    }
// printf("Turn Around time ");
// printry(tat,n);

for(int i=0;i<num;i++)
    {
        wt[i] = tat[i] - burst[i];
    }
printf("\nFor Process:\n");    
for(int i=0;i<num;i++)
    {
        printf("P%d:- Turnaround Time is %d & Waiting Time is %d\n", (i+1),tat[i],wt[i]);
    }
printf("Avg Turnaround Time is %.3f & Avg Waiting Time is %.3f\n", average(tat,num),average(wt,num));


	return 0;
}
