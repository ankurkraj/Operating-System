#include<stdio.h>
#include<pthread.h>
#include <limits.h>
#include<stdlib.h>
#include<math.h>

 int a[50],l,max,min,elements;
 double med,av,sd;


 void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int left, int right){
    if (left >= right)
    {
        return;
    }

    int pivot = a[right];
    int cnt = left;

    for (int i = left; i <= right; i++)
    {
        if (a[i] <= pivot)
        {
            swap(&a[cnt], &a[i]);
            cnt++;
        }
    }
    quicksort(left, cnt-2);
    quicksort(cnt, right);
}

void *avg()
{
    int sum=0;
    for(int i=0;i<l;i++)
        {
            sum=sum+a[i];
        }
    av=(double)sum/(double)l;
    
}

void *maximum()
{


    max=INT_MIN;
    for(int i=0;i<l;i++)
        {
            if(max<a[i])
            {
            max=a[i];
            }
        }
        pthread_exit(NULL);
}

void *minimum()
{

     min=INT_MAX;
    for(int i=0;i<l;i++)
        {
            if(min>a[i])
            {
            min=a[i];
            }
        }
    }


void *median (){
    quicksort(0, l-1);
    if(l%2!=0)
        med= a[l/2];
    else
        med = (a[(l-1)/2] + a[l/2])/2.0;
}


void *noel(){

    elements=l;
}

void *standarddeviation(){
    double sqsum=0;
    for(int i=0;i<l;i++){
        sqsum=sqsum+(((double)a[i]-av)*((double)a[i]-av));
    }
    sqsum=sqsum/(double)l;
    sd=sqrt(sqsum);

}

int main()
{
l=0;
int x;
pthread_t tid1;
pthread_t tid2;
pthread_t tid3; 
pthread_t tid4;
pthread_t tid5;
pthread_t tid6;
    printf("Pess -1 if u don't want to enter more numbers\n");
    printf("Enter Numbers");
    printf("\n");
    while(1){
        scanf("%d",&x);
        if(x==-1)
        break;    
        a[l++]=x;

           }  
        pthread_create(&tid1,NULL,&avg,NULL);
        
        pthread_create(&tid2,NULL,&maximum,NULL);
        
        pthread_create(&tid3,NULL,&minimum,NULL);

        pthread_create(&tid4,NULL,&median,NULL);

        pthread_create(&tid5,NULL,&noel,NULL);

        pthread_create(&tid6,NULL,&standarddeviation,NULL);
        

        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        pthread_join(tid3,NULL);
        pthread_join(tid4,NULL);
        pthread_join(tid5,NULL);
        pthread_join(tid6,NULL);
        

        printf("The average value is: %lf",av);

        printf("\nThe Maximum  value is: %d",max);
    
        printf("\nThe Minimum  value is: %d",min);
    
        printf("\nThe Median  value is: %lf",med);
    
        printf("\nTotal element: %d",elements);
    
        printf("\nStandard Deviation: %lf",sd);

        pthread_exit(NULL);

    //printf("\n done and my value is %d",n);

}
