 #include<stdio.h>
struct process
{
 char name;
 int at,bt,ct,wt,tt;
 int processed;
 float ntt;
}p[10];
int n;

void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
 if(p[i].at>p[j].at)
 {
  temp=p[i];
  p[i]=p[j];
  p[j]=temp;
 }
}
}
void main()
{
 int i,j,time,sum_bt=0,smallest;
 char c;
        float avgwt=0,avgwtut=0;
 printf("Enter no of processes:");
 scanf("%d",&n);
 for(i=0,c='A';i<n;i++,c++)
 {
 p[i].name=c;
 printf("\nEnter the arrival time of process%c: ",p[i].name);
 scanf("%d",&p[i].at);
 printf("\nEnter the burst time of process%c: ",p[i].name);
 scanf("%d",&p[i].bt);
 p[i].processed=0;
 sum_bt+=p[i].bt;

}
sortByArrival();
p[9].bt=9999;
printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time");
  for(time=p[0].at;time<sum_bt;)
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
      if(p[i].at<=time && p[i].processed!=1 && p[i].bt<p[smallest].bt)
        smallest=i;
    }
      time+=p[smallest].bt;
  p[smallest].ct=time;
          p[smallest].wt=time-p[smallest].at-p[smallest].bt;
     p[smallest].tt=p[smallest].wt+p[smallest].bt;
     p[smallest].ntt=((float)p[smallest].tt/p[smallest].bt);
    p[smallest].processed=1;
    avgwt+=p[smallest].wt;
    avgwtut+=p[smallest].tt;
 printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t",p[smallest].name,p[smallest].at,p[smallest].bt,p[smallest].wt,p[smallest].tt);
}
printf("\nAverage waiting time:%f\n",avgwt/n);
printf("\nAverage waiting time:%f\n",avgwtut/n);
}